#include "Boat.hh"

// Constuctoras

Boat::Boat() {
   productToBuyId = 0;
   buy_target = 0;
   productForSaleId = 0;
   availible = 0;
   travels = list<string>();
}

Boat::Boat(int productToBuyId, int buy_target, int productForSaleId, int availible) {
   this->productToBuyId = productToBuyId;
   this->buy_target = buy_target;
   this->productForSaleId = productForSaleId;
   this->availible = availible;
   travels = list<string>();
}

// Boat::Boat(const Boat &boat) {
//    productForSaleId = boat.productForSaleId;
//    availible = boat.availible;
//    productToBuyId = boat.productToBuyId;
//    buy_target = boat.buy_target;
// }

// Modificadoras

void Boat::buyProduct(int amount) {
   buy_target -= amount;
}

void Boat::sellProduct(int amount) {
   availible -= amount;
}

void Boat::setBoat(int productToBuyId, int buy_target, int productForSaleId, int availible) {
   this->productToBuyId = productToBuyId;
   this->buy_target = buy_target;
   this->productForSaleId = productForSaleId;
   this->availible = availible;
}

void Boat::addTravel(string city_name) {
   travels.push_back(city_name);
}

void Boat::clearTravels() {
   travels = list<string>();
}

// Consultoras

int Boat::getBuyTarget() const {
   return buy_target;
}

int Boat::getAvailible() const {
   return availible;
}

int Boat::getProductToBuyId() const {
   return productToBuyId;
}

int Boat::getProductForSaleId() const {
   return productForSaleId;
}

// I/O

void Boat::print() const {
   cout << productToBuyId << ' ' << buy_target << ' ' << productForSaleId << ' ' << availible;
   cout << endl;

   list<string>::const_iterator travel = travels.begin();
   while (travel != travels.end()) {
      cout << *travel << endl;
      ++travel;
   }
}