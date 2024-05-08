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
   string cmd;
   while (cin >> cmd and cmd != "fin") {
      if (cmd == "leer_rio" or cmd == "lr") {

      }
      else if (cmd == "leer_inventario" or cmd == "li") {

      }
      else if (cmd == "leer_inventarios" or cmd == "ls") {

      }
      else if (cmd == "modificar_barco" or cmd == "mb") {

      }
      else if (cmd == "escribir_barco" or cmd == "eb") {

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
      // Esta úlima línea es solo para la fase de desarrollo, en la entrega definitiva se va a eliminar.
      else cerr << cmd << " NO es un comando vàlido\n";
   }
}