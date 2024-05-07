/**
 * @file Inventory.hh
 * @brief Especificación de la clase Inventary
*/

#ifndef _INVENTORY_HH_
#define _INVENTORY_HH_

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "ProductSet.hh"
#include "ProductInventoryStats.hh"

/**
 * @class Inventory
 * @brief Un inventario es un contenedor destinado a almacenar productos (clase Product). Por otro lado, de cada producto, guarda cuantas unidades de éste hay en el inventario y cuantas son necesarias. No puede pasar que haya un producto donde las unidades necesarias sean 0.
*/
class Inventory {
private:
   
   map<int,ProductInventoryStats> inventory;
   // La clave (entero) representa el identificador del producto dentro de un conjunto de productos
   // ProductInventoryStats representa toda la información relevante de un producto en un inventario.
   int totalWeight;
   int totalVolume;

public:

   // Constructoras

   /**
    * @brief Creadora de inventarios vacios.
    * \pre Cierto.
    * \post Se ha creado una nueva instancia de inventario. El contenido de éste es vacio.
   */
   Inventory();

   // Modificadoras

   /**
    * @brief Añade el producto con identificador "id" al inventario del paràmetro implicito.
    * \pre El producto con id "id" existe y no se encuentra dentro del inventario del parámetro implícito. "owned" >= 0 y "needed" > 0.
    * \post En el inventario del parámetro implícito hay un nuevo producto con id "id". El parámetro implicito tiene "owned" uds. del producto y necesita "needed" uds. del producto.
   */
   void addProduct(int id, int owned, int needed);

   /**
    * @brief Modifica los datos del producto con identificador "id" en el inventario del parámetro ímplicito.
    * 
    * Es decir, modifica cuantas unidades se tienen de dicho producto y cuantas se necesitan.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito. "newOwned" >= 0 y "newNeeded" > 0.
    * \post El parámetro implicito tiene "owned" uds. del producto "id" y necesita "needed" uds.
   */
   void setProductStatus(int id, int newOwned, int newNeeded);

   /**
    * @brief Elimina el producto "id" del inventario del parámetro implícito.
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post El inventario del parámetro implicito ya no contiene el producto "id". Todas las uds de dicho producto que tenia la ciudad han desaparecido.
   */
   void removeProduct(int id);

   // Consultoras

   /**
    * @brief Consultora de peso total de un inventario
    * \pre Cierto.
    * \post Retorna el peso total del parámetro implícito
   */
   int getTotalWeight();

   /**
    * @brief Consultora de volumen total de un inventario
    * \pre Cierto.
    * \post Retorna el volumen total del parámetro implícito
   */
   int getTotalVolume();

   // /**
   //  * @brief Consultora de las estadísitcas de un producto (Ver clase ProductInventoryStats).
   //  * \pre el producto con identificador "id" existe dentro del inventario.
   //  * \post Retorna las estadísitcas de un producto del parámetro implícito
   // */
   // ProductInventoryStats getProductStats(int id);

   /**
    * @brief Consultora de unidades necesarias.
    * \pre Cierto.
    * \post Retorna el numero de unidades necesarias del parametro implícito
   */
   int getNeededById(int id) const;

   /**
    * @brief Consultora de unidades disponibles.
    * \pre Cierto.
    * \post Retorna el numero de unidades disponibles del parametro implícito
   */
   int getOwnedById(int id) const;

   // <---------->
   // NO SOY DEMASIADO FAN DE QUE LA LECTURA Y ESCRITURA DE UN TIPO DE DATOS VAYAN LIGADOS A LA CLASE
   
   // IO (Lectura - Escritura)

   /**
    * @brief Input de un inventario por el canal estándar.
    * \pre En el canal estándar se encuentra la información de un inventario en el siguiente formato:
    * \warning Aún se debe especificar cúal es el formato de lectura de un inventario.
    * \post Se ha leido la información pertinente del inventario y todos los datos se encuentran disponibles en el parámetro implicito.
   */
   void read();


   /**
    * @brief Output de un inventario por el canal estándar.
    * \pre Cierto.
    * \warning Aún se debe especificar cúal es el formato de escritura de un inventario.
    * \post Se he dejado en el canal estándar la información del inventario en el formato pertinente.
   */
   void write();
   // <---------->
};

#endif