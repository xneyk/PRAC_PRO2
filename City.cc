#include "City.hh"

// Constructoras

City::City() {
   inventory = map<int,ProductInventoryStats>();
   totalWeight = 0;
   totalVolume = 0;
}

// Modificadoras

void City::addProduct(int id, const ProductSet &product_set, int owned, int needed) {
   inventory[id] = ProductInventoryStats(owned, needed);
   totalWeight += owned*product_set.getWeightById(id);
   totalVolume += owned*product_set.getVolumeById(id);
}

void City::setProductStatus(int id, const ProductSet &product_set, int new_owned, int new_needed) {
   int old_owned = getOwnedById(id);
   inventory[id].setOwned(new_owned);
   inventory[id].setNeeded(new_needed);

   totalWeight += (new_owned - old_owned)*product_set.getWeightById(id);
   totalVolume += (new_owned - old_owned)*product_set.getVolumeById(id);
}

void City::removeProduct(int id, const ProductSet &product_set) {
   int old_owned = getOwnedById(id);
   inventory.erase(id);
   totalWeight -= old_owned*product_set.getWeightById(id);
   totalVolume -= old_owned*product_set.getVolumeById(id);
}

// Consultoras

bool City::hasProduct(int id) const {
   return inventory.find(id) != inventory.end();
}

int City::getTotalWeight() const {
   return totalWeight;
}

int City::getTotalVolume() const {
   return totalVolume;
}

int City::getOwnedById(int id) const {
   return inventory.at(id).getOwned();
}

int City::getNeededById(int id) const {
   return inventory.at(id).getNeeded();
}

ProductInventoryStats City::getProductStats(int id) const {
   return inventory.at(id);
}



// IO (Lectura - Escritura)

void City::read(const ProductSet &product_set) {
   (*this) = City(); // Entiendo que si volvemos a leer el inventario se debe sobre escribir.
   int number_of_products;
   cin >> number_of_products;
   int id, owned, needed;
   for (int i = 0; i < number_of_products; ++i ) {
      cin >> id >> owned >> needed;
      addProduct(id, product_set, owned, needed);
   }
}

void City::printInventory() const {
   map<int,ProductInventoryStats>::const_iterator inventory_line = inventory.begin();
   while (inventory_line != inventory.end()) {
      cout << inventory_line->first << ' ';
      cout << inventory_line->second.getOwned() << ' ';
      cout << inventory_line->second.getNeeded() << endl;
      ++inventory_line;
   }
   cout << getTotalWeight() << ' ' << getTotalVolume() << endl;
}
