#include "ProductSet.hh"

// Constructoras

ProductSet::ProductSet() {
   setOfProducts = map<int,Product>();
   int lastIdAdded = 0;  
}

// Modificadoras

void ProductSet::addProduct(Product product) {
   setOfProducts[lastIdAdded + 1] = product;
   ++lastIdAdded;
}