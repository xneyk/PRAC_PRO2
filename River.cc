#include "River.hh"

// Constructoras

River::River() {
   structure = BinTree<string>();
   citySet = map<string, City>();
}

// Consultoras

bool River::existsCityWithId(string name) const {
   return citySet.find(name) != citySet.end();
}

int River::getProductOwnedById(string city_name, int product_id) const {
   return getCity(city_name).getOwnedById(product_id);
}

int River::getProductNeededById(string city_name, int product_id) const {
   return getCity(city_name).getNeededById(product_id);
}

// Modificadoras

void River::addProduct(string city_name, int id, const ProductSet &product_set, int owned, int needed) {
   getCity(city_name).addProduct(id, product_set, owned, needed);
}

void River::setProductStatus(string city_name, int id, const ProductSet &product_set, int new_owned, int new_needed) {
   getCity(city_name).setProductStatus(id, product_set, new_owned, new_needed);
}

void River::removeProduct(string city_name, int id, const ProductSet &product_set) {
   getCity(city_name).removeProduct(id, product_set);
}

void River::trade(string cityA, string cityB) {
}

void River::redistribute() {
}

void River::travel() {
}

void River::read() {
   string city;
   string trash;
   cin >> city;
   if (city != "#") {
      citySet[city] = City();
      structure = BinTree<string>(city, buildRiverChildren(), buildRiverChildren());
   }
   // Si hay un '#' condición del río hay exactamente uno más, este hay que consumirlo.
   getline(cin, trash, '#');
}

BinTree<string> River::buildRiverChildren() {
   string city;
   cin >> city;
   if (city != "#") {
      citySet[city] = City();
      return BinTree<string>(city, buildRiverChildren(), buildRiverChildren());
   }
}

void River::printBoat() {
   boat.print();
   list<string>::const_iterator travel = travels.begin();
   while (travel != travels.end()) {
      cout << *travel << endl;
   }
}


// Métodos Privados (para hacer más legible/limpia la implementación)

City River::getCity(string city_name) const {
   return citySet.at(city_name);
}

void River::addTravel(string city_name) {
   travels.push_front(city_name);
}

// SOLO PARA LA FASE DE DESARROLLO PODER VER COMO SE ORGANIZA EL RIO, ELIMINAR LUEGO.
void River::printRiver() {
   structure.setOutputFormat(BinTree<string>::VISUALFORMAT);
   cout << structure << endl;
}