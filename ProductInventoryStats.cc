#include "ProductInventoryStats.hh"

// Constructoras

ProductInventoryStats::ProductInventoryStats() {
   owned = -1;
   needed = -1;
}

ProductInventoryStats::ProductInventoryStats(int owned, int needed) {
   this->owned = owned;
   this->needed = needed;
}

// Modificadoras

void ProductInventoryStats::setOwned(int new_owned) {
   owned = new_owned;
}

void ProductInventoryStats::setNeeded(int new_needed) {
   needed = new_needed;
}

// Consultoras

int ProductInventoryStats::getOwned() const {
   return owned;
}

int ProductInventoryStats::getNeeded() const {
   return needed;
}