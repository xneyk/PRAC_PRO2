#include "Product.hh"


// Constructoras

Product::Product(int weight, int volume) {
   this->weight = weight;
   this->volume = volume;
}

// Consultoras

int Product::getWeight() const {
   return weight;
}

int Product::getVolume() const {
   return volume;
}

// I/O

void Product::print() const {
   cout << weight << ' ' << volume << endl;
}
