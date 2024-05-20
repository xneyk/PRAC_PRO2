#include "Boat.hh"

// Constuctoras

Boat::Boat() {
   productForSaleId = 0;
   availible = 0;
   productToBuyId = 0;
   purchased = 0;
}

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

// I/O

void Boat::print() {
   cout << productForSaleId << ' ' << availible << ' ' << productToBuyId << ' ' << purchased;
   cout << endl;
   list<string>::const_iterator travel = travels.begin();
   while (travel != travels.end()) {
      cout << *travel << endl;
      ++travel;
   }
}

// Métodos privados para mayor legibilidad / limpieza.

void Boat::addTravel(string city_name) {
   travels.push_front(city_name);
}