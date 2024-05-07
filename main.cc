#include <iostream>

#include "River.hh"
#include "ProductSet.hh"
#include "Boat.hh"

using namespace std;

int main() {
   // Inicialicación del CONJUNTO DE PRODUCTOS.
   ProductSet productSet;

   int initial_products;
   cin >> initial_products;
   for (int i = 0; i < initial_products; ++i) {
      int weight, volume;
      productSet.addProduct(Product(weight, volume));
   }

   // Inicialicación del RIO.
   River river;
   river.read();

   // Inicialicación del BARCO.
   int forSaleId, availible;
   int toBuyId, purchased;
   cin >> forSaleId >> availible >> toBuyId >> purchased;

   Boat boat(forSaleId, availible, toBuyId, purchased);

   // TRATAMIENTO DE LOS COMANDOS
}