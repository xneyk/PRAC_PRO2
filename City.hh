/**
 * @file City.hh
 * @brief Especificación de la clase City.
*/
#ifndef _CITY_HH_
#define _CITY_HH_

#ifndef NO_DIAGRAM
#include <string>
#endif

#include "Inventory.hh"
using namespace std;

/**
 * @class City
 * @brief Representa una ciudad. Cada ciudad tiene un nombre y un inventario (representado) por la clase "Inventory"
*/
class City {
private:

   Inventory inventory;
   // int totalWeight; <-- Propiedades naturales de
   // int totalVolume;     un inventario, no de la ciudad.

public:

   // Constructoras
   
   /**
    * @brief Creadora de ciudades sin inventario
    * \pre Cierto.
    * \post Se ha creado una nueva instancia de City con nombre = "name" y inventario vacio.
   */
   City();

   /**
    * @brief Creadora de ciudades con inventario
    * \pre Cierto.
    * \post Se ha creado una nueva instancia de City con nombre = "name" y un inventario = "inventory".
   */
   City(Inventory inventory);

   // Modificadoras

   /**
    * @brief Añade el producto con identificador "id" al inventario del paràmetro implicito
    * \pre El producto con id "id" existe y no se encuentra dentro del inventario del parámetro implícito. "owned" >= 0 y "needed" > 0.
    * \post En el inventario del parámetro implícito hay un nuevo producto con id "id". El parámetro implicito tiene "owned" uds. del producto y necesita "needed" uds. del producto.
   */
   void addProduct(int id, int owned, int needed);

   /**
    * @brief Modifica los datos del producto con identificador "id" en el inventario del parámetro ímplicito
    * 
    * Es decir, modifica cuantas unidades se tienen de dicho producto y cuantas se necesitan.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito. "newOwned" >= 0 y "newNeeded" > 0.
    * \post El parámetro implicito tiene "owned" uds. del producto "id" y necesita "needed" uds.
   */
   void setProductStatus(int id, int newOwned, int newNeeded);

   /**
    * @brief Elimina el producto "id" del inventario del parámetro implícito
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post El inventario del parámetro implicito ya no contiene el producto "id". Todas las uds de dicho producto que tenia la ciudad han desaparecido.
   */
   void removeProduct(int id);

   // Consultoras

   /**
    * @brief Consultora de las unidades del producto "id" que tiene el parámetro implícito.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post Retorna el numero de unidades del producto "id" que tiene el parámetro implícito.
   */
   int getProductOwnedById(int id);

   /**
    * @brief Consultora de las unidades del producto "id" que necesita el parámetro implícito.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post Retorna el numero de unidades del producto "id" que necesita el parámetro implícito.
   */
   int getProductNeededById(int id);
};

#endif