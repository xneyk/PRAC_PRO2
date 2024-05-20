#include "ProductSet.hh"

// Constructoras

ProductSet::ProductSet() {
   setOfProducts = map<int,Product>();
   lastIdAdded = 0;
}

// Modificadoras

void ProductSet::addProduct(Product product) {
   setOfProducts[lastIdAdded + 1] = product;
   ++lastIdAdded;
}

// Consultoras

bool ProductSet::existsProductWithId(int id) const {
   return 1 <= id and id <= lastIdAdded;
}

int ProductSet::getTotalProducts() const {
   return lastIdAdded;
}

int ProductSet::getWeightById(int id) const {
   // map::at(T key) throw error si el elemento con clave "key" no existe.
   // --> nunca va a pasar los errores se controlan en main.
   return setOfProducts.at(id).getWeight();
}

int ProductSet::getVolumeById(int id) const {
   // map::at(T key) throw error si el elemento con clave "key" no existe.
   // --> nunca va a pasar los errores se controlan en main.
   return setOfProducts.at(id).getVolume();
}

void ProductSet::printProductById(int id) const {
   setOfProducts.at(id).print();
}
