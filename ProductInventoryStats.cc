#include "ProductInventoryStats.hh"

// Constructoras

ProductInventoryStats::ProductInventoryStats(int needed, int owned) {
   this->needed = needed;
   this->owned = owned;
}


// Modificadoras

void ProductInventoryStats::setNeeded(int new_needed) {
   needed = new_needed;
}

void ProductInventoryStats::setOwned(int new_owned) {
   owned = new_owned;
}

// Consultoras

int ProductInventoryStats::getNeeded() const {
   return needed;
}

int ProductInventoryStats::getOwned() const {
   return owned;
}
