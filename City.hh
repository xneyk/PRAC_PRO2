/**
 * @file City.hh
 * @brief Especificación de la clase City.
*/
#ifndef _CITY_HH_
#define _CITY_HH_

#ifndef NO_DIAGRAM
#include <map>
using namespace std;
#endif

#include "ProductSet.hh"
#include "ProductInventoryStats.hh"

/**
 * @class City
 * @brief Representa una ciudad. Cada ciudad tiene un nombre y un inventario. Un inventario es un contenedor destinado a almacenar productos.
 * 
 * De cada producto, guarda cuantas unidades de éste hay en el inventario y cuantas son necesarias. No puede pasar que haya un producto donde las unidades necesarias sean 0.
*/
class City {
private:

   map<int,ProductInventoryStats> inventory;
   // La clave (entero) representa el identificador del producto dentro de un conjunto de productos
   // ProductInventoryStats representa toda la información relevante de un producto en un inventario.
   int totalWeight;
   int totalVolume;

public:

   // Constructoras
   
   /**
    * @brief Creadora de ciudades sin inventario
    * \pre Cierto.
    * \post Se ha creado una nueva instancia de City con nombre = "name" y inventario vacio.
   */
   City();

   // Modificadoras

   /**
    * @brief Añade el producto con identificador "id" al inventario del paràmetro implicito
    * \pre El producto con id "id" existe y no se encuentra dentro del inventario del parámetro implícito. "owned" >= 0 y "needed" > 0.
    * \post En el inventario del parámetro implícito hay un nuevo producto con id "id". El parámetro implicito tiene "owned" uds. del producto y necesita "needed" uds. del producto.
   */
   void addProduct(int id, const ProductSet &product_set, int owned, int needed);

   /**
    * @brief Modifica los datos del producto con identificador "id" en el inventario del parámetro ímplicito
    * 
    * Es decir, modifica cuantas unidades se tienen de dicho producto y cuantas se necesitan.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito. "newOwned" >= 0 y "newNeeded" > 0.
    * \post El parámetro implicito tiene "newOwned" uds. del producto "id" y necesita "newNeeded" uds.
   */
   void setProductStatus(int id, const ProductSet &product_set, int new_owned, int new_needed);

   /**
    * @brief Elimina el producto "id" del inventario del parámetro implícito
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post El inventario del parámetro implicito ya no contiene el producto "id". Todas las uds de dicho producto que tenia la ciudad han desaparecido.
   */
   void removeProduct(int id, const ProductSet &product_set);

   /**
    * @brief El parámetro implícito comercia con otra ciudad.
    * 
    * El parámetro implícito le da a la ciudad todos los productos que le sobren hasta alcanzar, si es posible, los que la otra necesite, y viceversa.
    * \pre Cierto.
    * \post El parámetro implícito ha realizado todas las compra-ventas posibles con la otra ciudad.
   */
   void trade(City &visitor_city);

   // Consultoras

   /**
    * @brief Comprueva si el parámetro implícito contiene el producto con id "id".
    * \pre Cierto.
    * \post Retorna "true" en caso de contenerlo, "false" en caso contrario.
   */
   bool hasProduct(int id) const;

   /**
    * @brief Consultora de peso total de un inventario
    * \pre Cierto.
    * \post Retorna el peso total del parámetro implícito
   */
   int getTotalWeight() const;

   /**
    * @brief Consultora de volumen total de un inventario
    * \pre Cierto.
    * \post Retorna el volumen total del parámetro implícito
   */
   int getTotalVolume() const;

   /**
    * @brief Consultora de las unidades del producto "id" que tiene el parámetro implícito.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post Retorna el numero de unidades del producto "id" que tiene el parámetro implícito.
   */
   int getOwnedById(int id) const;

   /**
    * @brief Consultora de las unidades del producto "id" que necesita el parámetro implícito.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post Retorna el numero de unidades del producto "id" que necesita el parámetro implícito.
   */
   int getNeededById(int id) const;

   /**
    * @brief Consultora del estado de un producto dentro del inventario.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post Se retorna los datos de ese producto dentro de dicho inventario.
   */
   ProductInventoryStats getProductStats(int id) const;

   // IO (Lectura - Escritura)

   /**
    * @brief Input de una ciudad por el canal estándar.
    * \pre En el canal estándar se encuentra la información de un inventario en el siguiente formato: se lee un número indicando cuatos productos se añaden. A continuación vienen n lineas de "product_id" "owned" "needed". "needed" > 0.
    * \post Se ha leido la información pertinente de la ciudad y todos los datos se encuentran disponibles en el parámetro implicito.
   */
   void read(const ProductSet &product_set);


   /**
    * @brief Output de un inventario por el canal estándar.
    * \pre Cierto.
    * \post Se he dejado en el canal estándar la información del inventario en el formato pertinente: "product_id" "owned" "needed", para cada producto del inventario, seguido de su peso y volumen total.
   */
   void printInventory() const;
};

#endif