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
   increaseTotalWeightAndVolumen(
      owned*product_set.getWeightById(id),
      owned*product_set.getVolumeById(id)
   );
}

void City::setProductStatus(int id, const ProductSet &product_set, int new_owned, int new_needed) {
   int old_owned = getOwnedById(id);
   inventory[id].setOwned(new_owned);
   inventory[id].setNeeded(new_needed);

   increaseTotalWeightAndVolumen(
      (new_owned - old_owned)*product_set.getWeightById(id),
      (new_owned - old_owned)*product_set.getVolumeById(id)
   );
}

void City::removeProduct(int id, const ProductSet &product_set) {
   int old_owned = getOwnedById(id);
   inventory.erase(id);
   decreaseTotalWeightAndVolumen(
      old_owned*product_set.getWeightById(id),
      old_owned*product_set.getVolumeById(id)
   );
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
         // local_excess*visitor_excess < 0 ==> (local_excess > 0 ∧ visitor_excess < 0) ∨ (local_excess < 0 ∧ visitor_excess > 0)
         
            // Se transacciona el excedente más pequeño, ya que si la visitante necesita más de lo que
            // la local tiene, esta le dará todo su excedente. Por otro lado, si el excedente de la local
            // es mayor que lo que le falta a la visitante para llegar a lo que necesita, la local le dará
            // solamente esta cantidad.
            int transacted = min(abs(local_excess), abs(visitor_excess));

            // Se debe recalcular el peso y volumen total de ambas ciudades.
            int product_weigth = product_set.getWeightById(local_id);
            int product_volume = product_set.getVolumeById(local_id);
            // Precalculamos la variacion de pesos y volúmenes.
            int weight_variance = transacted*product_weigth;
            int volume_variance = transacted*product_volume;

            int local_new_owned, visitor_new_owned;
            if (local_excess > 0) { // ==> visitor_exces < 0 ==> p.i vende "transacted" visitor compra "transacted".
               local_new_owned = local_owned - transacted;
               decreaseTotalWeightAndVolumen(weight_variance, volume_variance);
               visitor_new_owned = visitor_owned + transacted;
               visitor_city.increaseTotalWeightAndVolumen(weight_variance, volume_variance);
            } else { // local_excess < 0 ==> visitor_exces > 0 ==> p.i compra "transacted" visitor vende "transacted".
               local_new_owned = local_owned + transacted;
               increaseTotalWeightAndVolumen(weight_variance, volume_variance);
               visitor_new_owned = visitor_owned - transacted;
               visitor_city.decreaseTotalWeightAndVolumen(weight_variance, volume_variance);
            }

            local_product->second.setOwned(local_new_owned);
            visitor_product->second.setOwned(visitor_new_owned);
         }
         ++local_product;
         ++visitor_product;
      }
      else if (local_id < visitor_id) ++local_product;
      else ++visitor_product; // (local_id > visitor_id) == (visitor_id < local_id)
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

// Métodos privados

void City::increaseTotalWeightAndVolumen(int weight_variance, int volume_variance) {
   totalWeight += weight_variance;
   totalVolume += volume_variance;
}

void City::decreaseTotalWeightAndVolumen(int weight_variance, int volume_variance) {
   // Se perfectamente que esto mismo lo podemos conseguir haciendo 
   // increaseTotalWeightAndVolumen(-weight_variance, -volume_variance) y ahorrarnos esta función
   // pero en mi opinión esta tonteria tiene un gran impacto en la legibilidad del código.
   totalWeight -= weight_variance;
   totalVolume -= volume_variance;
}