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
         // reset boat travels
      }
      else if (cmd == "leer_inventario" or cmd == "li") {
         cin >> city_id;
         if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
            City trash; // se encarga de consumir los datos del inventario.
            trash.read(product_set);
         } else {
            river.readCityWithId(city_id, product_set);
         }
      }
      else if (cmd == "leer_inventarios" or cmd == "ls") {
         int n;
         cin >> n; // número de inventarios a leer.
         for (int i = 0; i < n; ++i) {
            cin >> city_id;
            river.readCityWithId(city_id, product_set);
         }
      }
      else if (cmd == "modificar_barco" or cmd == "mb") {
         cin >> forSaleId >> availible >> toBuyId >> purchased;
         if (not (product_set.existsProductWithId(forSaleId) and product_set.existsProductWithId(toBuyId))) {
            cout << "error: no existe el producto" << endl;
         }
         else if (forSaleId == toBuyId) {
            cout << "error: no se puede comprar y vender el mismo producto" << endl;
         }
         else {
            boat.setBoat(forSaleId, availible, toBuyId, purchased);
         }
      }
      else if (cmd == "escribir_barco" or cmd == "eb") {
         boat.print();
      }
      else if (cmd == "consultar_num" or cmd == "cn") {
         cout << product_set.getTotalProducts() << endl;
      }
      else if (cmd == "agregar_productos" or cmd == "ap") {
         int n;
         cin >> n;
         for (int i = 0; i < n; ++i) {
            int weight, volume;
            cin >> weight >> volume;
            product_set.addProduct(Product(weight, volume));
         }
      }
      else if (cmd == "escribir_producto" or cmd == "ep") {
         cin >> product_id;
         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         } else {
            product_set.printProductById(product_id);
         }
      }
      else if (cmd == "escribir_ciudad" or cmd == "ec") {
         cin >> city_id;
         if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         } else {
            river.printCityWithId(city_id);
         }
      }
      else if (cmd == "poner_prod" or cmd == "pp") {
         cin >> city_id >> product_id >> product_own >> product_need;

         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         }
         else if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         }
         else {
            river.addProduct(city_id, product_id, product_set, product_own, product_need);
            river.printCityWeightAndVolume(city_id);
         }
      }
      else if (cmd == "modificar_prod" or cmd == "mp") {
         cin >> city_id >> product_id >> product_own >> product_need;

         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         }
         else if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         }
         else if (not river.cityHasProduct(city_id, product_id)) {
            cout << "error: la ciudad no tiene el producto" << endl;
         }
         else {
            river.setProductStatus(city_id, product_id, product_set, product_own, product_need);
            river.printCityWeightAndVolume(city_id);
         }
      }
      else if (cmd == "quitar_prod" or cmd == "qp") {
         cin >> city_id >> product_id;

         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         }
         else if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         }
         else if (not river.cityHasProduct(city_id, product_id)) {
            cout << "error: la ciudad no tiene el producto" << endl;
         }
         else {
            river.removeProduct(city_id, product_id, product_set);
            river.printCityWeightAndVolume(city_id);
         }
      }
      else if (cmd == "consultar_prod" or cmd == "cp") {
         cin >> city_id >> product_id;

         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         }
         else if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         }
         else if (not river.cityHasProduct(city_id, product_id)) {
            cout << "error: la ciudad no tiene el producto" << endl;
         }
         else {
            river.printProductStatsById(city_id, product_id);
         }
      }
      else if (cmd == "comerciar" or cmd == "co") {

      }
      else if (cmd == "redistribuir" or cmd == "re") {

      }
      else if (cmd == "hacer_viaje" or cmd == "hv") {

      }
   }
}