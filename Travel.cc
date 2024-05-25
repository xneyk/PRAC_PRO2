#include "Travel.hh"

// Constructoras

// Travel::Travel() {
//    product_for_sale_id = 0;
//    stock = 0;
//    product_to_buy_id = 0;
//    buy_target = 0;
//    length = 0;
//    last_trade = "";
// }

Travel::Travel(const Boat& boat) {
   product_for_sale_id = boat.getProductForSaleId();
   stock = boat.getAvailible();
   product_to_buy_id = boat.getProductToBuyId();
   buy_target = boat.getBuyTarget();
   length = 0;
   last_trade = "";
}

// Travel::Travel(const Travel& travel) {
//    stock = travel.stock;
//    buy_target = travel.buy_target;
//    length = travel.length;
//    last_trade = travel.last_trade;
// }

// Modificadoras

void Travel::updateStatus(int sold, int bought) {
   stock -= sold;
   buy_target -= bought;
}

void Travel::setLastTrade(string city_name) {
   last_trade = city_name;
}

void Travel::increaseLength() {
   ++length;
}

// Consultoras

string Travel::getLastTrade() const {
   return last_trade;
}

int Travel::getLength() const {
   return length;
}

int Travel::getProductForSaleId() const {
   return product_for_sale_id;
}

int Travel::getProductToBuyId() const {
   return product_to_buy_id;
}

int Travel::getStock() const {
   return stock;
}

int Travel::getBuyTarget() const {
   return buy_target;
}

bool Travel::objectiveAchived() const {
   return stock == 0 and buy_target == 0;
}

bool Travel::betterTravelThan(const Travel& travel) const {
   if (stock + buy_target != travel.stock + travel.buy_target) return stock + buy_target < travel.stock + travel.buy_target;
   if (length != travel.length) return length < travel.length;
   
   // Empate ==> El parámetro implícito és mejor.
   return true;
}
