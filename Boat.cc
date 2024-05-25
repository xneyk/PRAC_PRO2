#include "Boat.hh"

// Constuctoras

Boat::Boat() {
   productForSaleId = 0;
   availible = 0;
   productToBuyId = 0;
   buy_target = 0;
}

Boat::Boat(int productForSaleId, int availible, int productToBuyId, int buy_target) {
   this->productForSaleId = productForSaleId;
   this->availible = availible;
   this->productToBuyId = productToBuyId;
   this->buy_target = buy_target;
}

// Boat::Boat(const Boat &boat) {
//    productForSaleId = boat.productForSaleId;
//    availible = boat.availible;
//    productToBuyId = boat.productToBuyId;
//    buy_target = boat.buy_target;
// }

// Modificadoras

void Boat::sellProduct(int amount) {
   availible -= amount;
}

void Boat::buyProduct(int amount) {
   buy_target -= amount;
}

void Boat::setBoat(int productForSaleId, int availible, int productToBuyId, int buy_target) {
   (*this) = Boat(productForSaleId, availible, productToBuyId, buy_target);
}

// Consultoras

int Boat::getAvailible() const {
   return availible;
}

int Boat::getBuyTarget() const {
   return buy_target;
}

int Boat::getProductToBuyId() const {
   return productToBuyId;
}

int Boat::getProductForSaleId() const {
   return productForSaleId;
}

// I/O

void Boat::print() {
   cout << productForSaleId << ' ' << availible << ' ' << productToBuyId << ' ' << buy_target;
   cout << endl;
}