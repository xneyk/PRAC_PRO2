#include "Boat.hh"

// Constuctoras

Boat::Boat(int productForSaleId, int availible, int productToBuyId, int purchased) {
   this->productForSaleId = productForSaleId;
   this->availible = availible;
   this->productToBuyId = productToBuyId;
   this->purchased = purchased;
}

Boat::Boat(const Boat &boat) {
   productForSaleId = boat.productForSaleId;
   availible = boat.availible;
   productToBuyId = boat.productToBuyId;
   purchased = boat.purchased;
}

// Modificadoras

void Boat::sellProduct(int amount) {
   availible -= amount;
}

void Boat::buyProduct(int amount) {
   purchased += amount;
}

void Boat::setBoat(int productForSaleId, int availible, int productToBuyId, int purchased) {
   (*this) = Boat(productForSaleId, availible, productToBuyId, purchased);
}

// Consultoras

int Boat::getAvailible() {
   return availible;
}

int Boat::getPurchased() {
   return purchased;
}

int Boat::getProductToBuyId() {
   return productToBuyId;
}

int Boat::getProductForSaleId() {
   return productForSaleId;
}
