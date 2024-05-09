#include <iostream>

#include "River.hh"
#include "ProductSet.hh"
#include "Boat.hh"

using namespace std;

int main() {
   // Inicialicación del CONJUNTO DE PRODUCTOS.
   ProductSet product_set;

   int initial_products;
   cin >> initial_products;
   for (int i = 0; i < initial_products; ++i) {
      int weight, volume;
      product_set.addProduct(Product(weight, volume));
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
   string cmd;
   string city_id;
   int product_id;
   int product_need, product_own;
   while (cin >> cmd and cmd != "fin") {
      if (cmd == "leer_rio" or cmd == "lr") {
         river.read();
      }
      else if (cmd == "leer_inventario" or cmd == "li") {

      }
      else if (cmd == "leer_inventarios" or cmd == "ls") {

      }
      else if (cmd == "modificar_barco" or cmd == "mb") {
         cin >> forSaleId >> availible >> toBuyId >> purchased;
         boat.setBoat(forSaleId, availible, toBuyId, purchased);
      }
      else if (cmd == "escribir_barco" or cmd == "eb") {
         boat.print();
      }
      else if (cmd == "consultar_num" or cmd == "cn") {

      }
      else if (cmd == "agregar_productos" or cmd == "ap") {

      }
      else if (cmd == "escribir_producto" or cmd == "ep") {

      }
      else if (cmd == "escribir_ciudad" or cmd == "ec") {

      }
      else if (cmd == "poner_prod" or cmd == "pp") {
         cin >> city_id >> product_id >> product_own >> product_need;
         if (product_set.existsProductWithId(product_id)) {
            if (river.existsCityWithId(city_id)) {
               river.addProduct(city_id, product_id, product_own, product_need);
            }
            else cout << "error: no existe la ciudad" << endl;
         }
         else cout << "error: no existe el producto" << endl;
      }
      else if (cmd == "modificar_prod" or cmd == "mp") {

      }
      else if (cmd == "quitar_prod" or cmd == "qp") {

      }
      else if (cmd == "consultar_prod" or cmd == "cp") {

      }
      else if (cmd == "comerciar" or cmd == "co") {

      }
      else if (cmd == "redistribuir" or cmd == "re") {

      }
      else if (cmd == "hacer_viaje" or cmd == "hv") {

      }
   }
}