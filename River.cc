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

// void River::trade(string cityA, string cityB) {
// }

// void River::redistribute() {
// }

// void River::travel() {
// }

// I / O

void River::read() {
   string city;
   cin >> city;
   if (city != "#") {
      citySet[city] = City();
      structure = BinTree<string>(city, buildRiverChildren(), buildRiverChildren());
   }
}


void River::readCityWithId(string city_name, const ProductSet &product_set) {
   citySet.at(city_name).read(product_set);
}

void River::printCityWithId(string city_name) const {
   citySet.at(city_name).printInventory();
}

void River::printCityWeightAndVolume(string city_name) const {
   City city = citySet.at(city_name);
   cout << city.getTotalWeight() << city.getTotalVolume() << endl;
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

BinTree<string> River::buildRiverChildren() {
   string city;
   cin >> city;
   if (city != "#") {
      citySet[city] = City();
      return BinTree<string>(city, buildRiverChildren(), buildRiverChildren());
   }
   return BinTree<string>();
}