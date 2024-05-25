#include "River.hh"

// Constructoras

River::River() {
   structure = BinTree<string>();
   citySet = map<string, City>();
   cityPreorder = map<string, int>();
   total_cities = 0;
}

// Consultoras

bool River::existsCityWithId(string name) const {
   return citySet.find(name) != citySet.end();
}

bool River::cityHasProduct(string city_name, int id) const {
   return citySet.at(city_name).hasProduct(id);
}

int River::getProductOwnedById(string city_name, int product_id) const {
   return citySet.at(city_name).getOwnedById(product_id);
}

int River::getProductNeededById(string city_name, int product_id) const {
   return citySet.at(city_name).getNeededById(product_id);
}

// Modificadoras

void River::addProduct(string city_name, int id, const ProductSet &product_set, int owned, int needed) {
   citySet.at(city_name).addProduct(id, product_set, owned, needed);
}

void River::setProductStatus(string city_name, int id, const ProductSet &product_set, int new_owned, int new_needed) {
   citySet.at(city_name).setProductStatus(id, product_set, new_owned, new_needed);
}

void River::removeProduct(string city_name, int id, const ProductSet &product_set) {
   citySet.at(city_name).removeProduct(id, product_set);
}

void River::trade(string city_A, string city_B, const ProductSet &product_set) {
   citySet.at(city_A).trade(citySet.at(city_B), product_set);
}

void River::redistribute(const ProductSet &product_set) {
   // Solamente se tiene que comprobar que uno de los hijos no esta vacio, ya que
   // por definición de rio: Cada ciudad o tiene una ciudad a la derecha y una a la izquierda
   // o no tiene ninguna.
   if (not (structure.empty() or structure.left().empty())) {
      string root = structure.value();
      string right_neighbor = structure.left().value();
      string left_neighbor = structure.right().value();

      citySet.at(root).trade(citySet.at(right_neighbor), product_set);
      citySet.at(root).trade(citySet.at(left_neighbor), product_set);

      // Se sigue la redistrubución por el lado derecho (río arriba) del río.
      redistribute(structure.left(), product_set);
      // Se sigue la redistrubución por el lado izquierdo (río arriba) del río.
      redistribute(structure.right(), product_set);
   }
}

int River::travel(Boat &boat, const ProductSet &product_set) {
   Travel current_travel(boat);
   Travel best_travel(current_travel);

   findOptimalRoute(structure, current_travel, best_travel);
   // El mejor viaje es best_travel. Es decir, el viaje que acaba en la ciudad best_travel.getLastTrade()

   if (best_travel.getLastTrade() != "") {
      // Si no se ha podido comerciar no hay ruta de comercio posible no hay que efectuarla
      Boat traveling_boat = boat; // Se envia una copia del barco a viajar por el rio.
      trade(structure, best_travel.getLastTrade(), traveling_boat, product_set);
      // Va a ir comerciando por la ruta que acaba en "best_travel.getLastTrade()" hasta encontrar a esa ciudad.

      boat.addTravel(best_travel.getLastTrade()); // Se añade el viaje a la lista.
   }

   
   return boat.getAvailible() - best_travel.getStock() + boat.getBuyTarget() - best_travel.getBuyTarget();
}

// I / O

void River::read() {
   (*this) = River();
   // Al leer un rio es como si se creara uno nuevo.

   structure = buildRiver();
}

void River::readCityWithId(string city_name, const ProductSet &product_set) {
   citySet.at(city_name).read(product_set);
}

void River::printCityWithId(string city_name) const {
   citySet.at(city_name).printInventory();
}

void River::printCityWeightAndVolume(string city_name) const {
   City city = citySet.at(city_name);
   cout << city.getTotalWeight() << ' ' << city.getTotalVolume() << endl;
}

void River::printProductStatsById(string city_name, int id) {
   ProductInventoryStats product_stats = citySet.at(city_name).getProductStats(id);
   cout << product_stats.getOwned() << ' ';
   cout << product_stats.getNeeded() << endl;
}

// SOLO PARA LA FASE DE DESARROLLO PODER VER COMO SE ORGANIZA EL RIO, ELIMINAR LUEGO.
void River::printRiver() {
   structure.setOutputFormat(BinTree<string>::VISUALFORMAT);
   cout << structure << endl;
}

// Métodos Privados (para hacer más legible/limpia la implementación)

BinTree<string> River::buildRiver() {
   string city;
   cin >> city;
   if (city != "#") {
      ++total_cities;
      citySet[city] = City();
      cityPreorder[city] = total_cities; // Relacionamos cada ciudad con su posición en el preorden.
      
      BinTree<string> left_child = buildRiver();
      BinTree<string> right_child = buildRiver();
      return BinTree<string>(city, left_child, right_child);
   }
   return BinTree<string>();
}

void River::redistribute(BinTree<string> structure, const ProductSet &product_set) {
   // Solamente se tiene que comprobar que uno de los hijos no esta vacio, ya que
   // por definición de rio: Cada ciudad o tiene una ciudad a la derecha y una a la izquierda
   // o no tiene ninguna.

   // No se comprueva que la raíz no sea vacia puesto que es la precondición.
   if (not structure.left().empty()) {
      string root = structure.value();
      string right_neighbor = structure.left().value();
      string left_neighbor = structure.right().value();

      citySet.at(root).trade(citySet.at(right_neighbor), product_set);
      citySet.at(root).trade(citySet.at(left_neighbor), product_set);

      // Se sigue la redistrubución por el lado derecho (río arriba) del río.
      redistribute(structure.left(), product_set);
      // Se sigue la redistrubución por el lado izquierdo (río arriba) del río.
      redistribute(structure.right(), product_set);
   }
}

void River::findOptimalRoute(BinTree<string> structure, Travel current_travel, Travel &best_travel) const {
   if (not structure.empty()) {
      current_travel.increaseLength();
      tryTransaction(structure.value(), current_travel);
      if (current_travel.betterTravelThan(best_travel)) best_travel = current_travel;
      if (not (current_travel.objectiveAchived() or structure.left().empty())) {
         findOptimalRoute(structure.right(), current_travel, best_travel);
         findOptimalRoute(structure.left(), current_travel, best_travel);
      }
   }
   // no se actualiza ningún valor pues se ha llegado al final de la ruta.
}

void River::tryTransaction(string city_name, Travel &current_travel) const {
   City city = citySet.at(city_name);
   int to_buy_id = current_travel.getProductToBuyId();
   int for_sale_id = current_travel.getProductForSaleId();

   int bought = 0, sold = 0;
   if (city.hasProduct(to_buy_id)) { // Posible venta de la ciudad
      int excess = city.getOwnedById(to_buy_id) - city.getNeededById(to_buy_id);
      if (excess > 0) {
         bought = min(current_travel.getBuyTarget(), excess);
      }
   }
   if (city.hasProduct(for_sale_id)) { // Posible compra de la ciudad
      int excess = city.getOwnedById(for_sale_id) - city.getNeededById(for_sale_id);
      if (excess < 0) {
         sold = min(current_travel.getStock(), -excess);
      }
   }

   if (not (bought == 0 and sold == 0)) {
      current_travel.updateStatus(bought, sold);
      current_travel.setLastTrade(city_name);
   }
}

void River::transaction(string city_name, Boat &boat, const ProductSet &product_set) {
   int to_buy_id = boat.getProductToBuyId();
   int for_sale_id = boat.getProductForSaleId();

   int bought = 0, sold = 0;
   if (citySet.at(city_name).hasProduct(to_buy_id)) { // Posible venta de la ciudad
      ProductInventoryStats to_buy_stats = citySet.at(city_name).getProductStats(to_buy_id);
      int owned = to_buy_stats.getOwned();
      int needed = to_buy_stats.getNeeded();
      int excess =  owned - needed;
      if (excess > 0) { // A la ciudad le sobran productos
         bought = min(boat.getBuyTarget(), excess);

         citySet.at(city_name).setProductStatus(to_buy_id, product_set, owned - bought, needed);
         boat.buyProduct(bought);
      }
   }
   if (citySet.at(city_name).hasProduct(for_sale_id)) { // Posible compra de la ciudad
      ProductInventoryStats for_sale_stats = citySet.at(city_name).getProductStats(for_sale_id);
      int owned = for_sale_stats.getOwned();
      int needed = for_sale_stats.getNeeded();
      int excess =  owned - needed;
      if (excess < 0) { // La ciudad quiere comprar el producto (le hace falta)
         sold = min(boat.getAvailible(), -excess);

         citySet.at(city_name).setProductStatus(for_sale_id, product_set, owned + sold, needed);
         boat.sellProduct(sold);
      }
   }
}

void River::trade(BinTree<string> structure, string last_city, Boat &boat, const ProductSet &product_set) {
   if (not structure.empty()) {
      string root_city = structure.value();
      transaction(root_city, boat, product_set);

      int searching_id = cityPreorder.at(last_city);

      if (cityPreorder.at(root_city) != searching_id) {
         if (not structure.right().empty()) { // ==> structure.left().empty() false.
            int right_city_preorder_id = cityPreorder.at(structure.right().value());
            if (searching_id >= right_city_preorder_id) {
               trade(structure.right(), last_city, boat, product_set);
            } else {
               trade(structure.left(), last_city, boat, product_set);
            }
         }
      }
   }
}
