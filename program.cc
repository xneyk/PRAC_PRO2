/**
 * @file program.cc
 * @brief Este es el programa principal, el cual proporciona una especie de CLI con la que podemos interactuar con el código de la práctica.
*/
/**
 * @mainpage
 * Se describe una cuenca fluvial con un río principal y varios afluentes, donde las ciudades están ubicadas en las fuentes y en los puntos de unión de los afluentes, incluyendo la desembocadura al norte. No hay ciudades en otros tramos del río. Las aguas fluyen de sur a norte.
 * 
 * En una representación gráfica las ciudades se utilizan como nodos, y cada una tiene un inventario de productos identificados por números, con atributos de peso y volumen. Cada ciudad necesita ciertos productos y puede tener más, menos o exactamente la cantidad que necesita.
 * 
 * Un barco comercial se usa para transportar productos entre las ciudades. En cada viaje, el barco puede vender una cantidad de un producto y comprar otra cantidad de un producto diferente.
 * 
 * El proceso comienza leyendo el número de productos y sus atributos, seguido de la estructura de la cuenca y los detalles del barco, incluyendo los productos que quiere comprar y vender y sus cantidades. No se consideran situaciones erróneas en los datos iniciales.
 * 
 * Este problema ha sido resuelto modularizando en siete clases, haciendo que su lectura y mantenimiento sea fácil y eficaz.
 * <ul>
 *    <li>Boat</li>
 *    <li>City</li>
 *    <li>Product</li>
 *    <li>ProductInventoryStats</li>
 *    <li>ProductSet</li>
 *    <li>River</li>
 *    <li>Travel</li>
 * </ul>
*/
#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

#include "River.hh"
#include "ProductSet.hh"
#include "Boat.hh"

int main() {
   // Inicialicación del CONJUNTO DE PRODUCTOS.
   ProductSet product_set;

   int initial_products;
   cin >> initial_products;
   for (int i = 0; i < initial_products; ++i) {
      int weight, volume;
      cin >> weight >> volume;
      product_set.addProduct(Product(weight, volume));
   }

   // Inicialicación del RIO.
   River river;
   river.read();

   // Inicialicación del BARCO.
   int toBuyId, buy_target;
   int forSaleId, availible;
   cin >> toBuyId >> buy_target >> forSaleId >> availible;

   Boat boat(toBuyId, buy_target, forSaleId, availible);

   // TRATAMIENTO DE LOS COMANDOS
   string cmd;
   string city_id;
   int product_id;
   int product_need, product_own;
   while (cin >> cmd and cmd != "fin") {
      if (cmd == "leer_rio" or cmd == "lr") {
         cout << '#' << cmd << endl;

         river.read();
         boat.clearTravels();
      }
      else if (cmd == "leer_inventario" or cmd == "li") {
         cin >> city_id;
         cout << '#' << cmd << ' ' << city_id << endl;

         if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
            City trash; // se encarga de consumir los datos del inventario.
            trash.read(product_set);
         } else {
            river.readCityWithId(city_id, product_set);
         }
      }
      else if (cmd == "leer_inventarios" or cmd == "ls") {
         cout << '#' << cmd << endl;

         while (cin >> city_id and city_id != "#") {
            river.readCityWithId(city_id, product_set);
         }
      }
      else if (cmd == "modificar_barco" or cmd == "mb") {
         cout << '#' << cmd << endl;

         cin >> toBuyId >> buy_target >> forSaleId >> availible;
         if (not (product_set.existsProductWithId(toBuyId) and product_set.existsProductWithId(forSaleId))) {
            cout << "error: no existe el producto" << endl;
         }
         else if (toBuyId == forSaleId) {
            cout << "error: no se puede comprar y vender el mismo producto" << endl;
         }
         else {
            boat.setBoat(toBuyId, buy_target, forSaleId, availible);
         }
      }
      else if (cmd == "escribir_barco" or cmd == "eb") {
         cout << '#' << cmd << endl;

         boat.print();
      }
      else if (cmd == "consultar_num" or cmd == "cn") {
         cout << '#' << cmd << endl;

         cout << product_set.getTotalProducts() << endl;
      }
      else if (cmd == "agregar_productos" or cmd == "ap") {
         int n;
         cin >> n;
         cout << '#' << cmd << ' ' << n << endl;

         for (int i = 0; i < n; ++i) {
            int weight, volume;
            cin >> weight >> volume;
            product_set.addProduct(Product(weight, volume));
         }
      }
      else if (cmd == "escribir_producto" or cmd == "ep") {
         cin >> product_id;
         cout << '#' << cmd << ' ' << product_id << endl;

         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         } else {
            product_set.printProductById(product_id);
         }
      }
      else if (cmd == "escribir_ciudad" or cmd == "ec") {
         cin >> city_id;
         cout << '#' << cmd << ' ' << city_id << endl;

         if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         } else {
            river.printCityWithId(city_id);
         }
      }
      else if (cmd == "poner_prod" or cmd == "pp") {
         cin >> city_id >> product_id >> product_own >> product_need;
         cout << '#' << cmd << ' ' << city_id << ' ' << product_id << endl;

         if (not product_set.existsProductWithId(product_id)) {
            cout << "error: no existe el producto" << endl;
         }
         else if (not river.existsCityWithId(city_id)) {
            cout << "error: no existe la ciudad" << endl;
         }
         else if (river.cityHasProduct(city_id, product_id)) {
            cout << "error: la ciudad ya tiene el producto" << endl;
         }
         else {
            river.addProduct(city_id, product_id, product_set, product_own, product_need);
            river.printCityWeightAndVolume(city_id);
         }
      }
      else if (cmd == "modificar_prod" or cmd == "mp") {
         cin >> city_id >> product_id >> product_own >> product_need;
         cout << '#' << cmd << ' ' << city_id << ' ' << product_id << endl;

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
         cout << '#' << cmd << ' ' << city_id << ' ' << product_id << endl;

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
         cout << '#' << cmd << ' ' << city_id << ' ' << product_id << endl;

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
         string city_a, city_b;
         cin >> city_a >> city_b;
         cout << '#' << cmd << ' ' << city_a << ' ' << city_b << endl;

         if (not (river.existsCityWithId(city_a) and river.existsCityWithId(city_b))) {
            cout << "error: no existe la ciudad" << endl;
         }
         else if (city_a == city_b) {
            cout << "error: ciudad repetida" << endl;
         }
         else {
            river.trade(city_a, city_b, product_set);
         }
      }
      else if (cmd == "redistribuir" or cmd == "re") {
         cout << '#' << cmd << endl;

         river.redistribute(product_set);
      }
      else if (cmd == "hacer_viaje" or cmd == "hv") {
         cout << '#' << cmd << endl;

         cout << river.travel(boat, product_set) << endl;
      }
      else if (cmd == "//")  {
         string trash;
         getline(cin, trash);
      }
   }
}