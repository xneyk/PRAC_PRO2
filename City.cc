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

void City::trade(City &visitor_city, const ProductSet &product_set) {
   map<int, ProductInventoryStats>::iterator visitor_product = visitor_city.inventory.begin();
   map<int, ProductInventoryStats>::iterator local_product = inventory.begin();

   // Vamos a iterar los dos inventarios a la vez de arriba a abajo, aprovechando que estos estan
   // ordenados de menor a mayor indice, podremos ir avanzando los dos "montones" individualmentel
   // e ir encontrando todos los indices que coincidan.
   while (local_product != inventory.end() and visitor_product != visitor_city.inventory.end()) {
      // Guardamos los identificadores de cada producto en una variable para mayor legibilidad.
      int local_id = local_product->first, visitor_id = visitor_product->first;
      
      if (local_id == visitor_id) { // Las dos ciudades tienen el mismo producto ==> pueden comerciar.
         int local_owned = local_product->second.getOwned();
         int visitor_owned = visitor_product->second.getOwned();
         int local_excess = local_product->second.getOwned() - local_product->second.getNeeded();
         int visitor_excess = visitor_product->second.getOwned() - visitor_product->second.getNeeded();

         if (local_excess*visitor_excess < 0) {
            // Se transacciona el excedente más pequeño, ya que si la visitante necesita más de lo que
            // la local tiene, esta le dará todo su excedente. Por otro lado, si el excedente de la local
            // es mayor que lo que le falta a la visitante para llegar a lo que necesita, la local le dará
            // solamente esta cantidad.
            int transacted = min(abs(local_excess), abs(visitor_excess));

            int local_new_owned = local_excess > 0 ? local_owned - transacted : local_owned + transacted;
            int visitor_new_owned = visitor_excess > 0 ? visitor_owned - transacted : visitor_owned + transacted;

            local_product->second.setOwned(local_new_owned);
            visitor_product->second.setOwned(visitor_new_owned);
            
            // Recalculamos el peso y volumen total de ambas ciudades.
            int product_weigth = product_set.getWeightById(local_id);
            int product_volume = product_set.getVolumeById(local_id);

            int weight_variance = transacted*product_weigth;
            int volumen_variance = transacted*product_volume;

            totalWeight += local_excess > 0 ? -weight_variance : weight_variance;
            totalVolume += local_excess > 0 ? -volumen_variance : volumen_variance;
            visitor_city.totalWeight += visitor_excess > 0 ? -weight_variance : weight_variance;
            visitor_city.totalVolume += visitor_excess > 0 ? -volumen_variance : volumen_variance;
            
         }
         ++local_product;
         ++visitor_product;
      }
      else if (local_id > visitor_id) ++visitor_product;
      else ++local_product; // (local_id < visitor_id)
   }
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
