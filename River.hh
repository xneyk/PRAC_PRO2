/**
 * @file River.hh
 * @brief Especificación de la clase River
*/

#ifndef _RIVER_HH_
#define _RIVER_HH_

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <string>
#endif

#include "City.hh"

class River {
private:

   BinTree<string> river; 
   // Representa la estructura de la cuenca fluvial
   // Observación: Notad que solamente se trata de sus identificadores, la información
   // de cada ciudad se almacena en una clase "City".
   map<string, City> citySet; // Tal vez seria buena idea abstraerlo en una clase CitySet.
   // Es en este conjunto de ciudades donde se relaciona a cada clase con su identificador
   // correspondiente.

public:

   // Constructoras

   /**
    * @brief Creadora de rios vacios.
    * \pre Cierto.
    * \post Se ha creado una nueva instancia de rio, dicho rio sin afluentes y por ende, sin ciudades.
   */
   River();

   // Consultoras

   /**
    * \brief Comprueva si en el rio existe una ciudad con identificador "name".
    * \pre Cierto.
    * \post retorna "true" en caso de exisitir, "false" en caso contrario.
   */
   bool existsCityWithId(string name) const;

   /**
    * @brief Consultora de las unidades del producto "id" que tiene la ciudad "city_name".
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name".
    * \post Retorna el numero de unidades del producto "id" que tiene la ciudad "city_name".
   */
   int getProductOwnedById(string city_name, int product_id);

   /**
    * @brief Consultora de las unidades del producto "id" que necesita la ciudad "city_name".
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name".
    * \post Retorna el numero de unidades del producto "id" que necesita la ciudad "city_name".
   */
   int getProductNeededById(string city_name, int product_id);

   // Modificadoras

   /**
    * @brief Añade el producto con identificador "id" al inventario de la ciudad "city_name".
    * \pre El producto con id "id" existe y no se encuentra dentro del inventario de la ciudad "city_name". "owned" >= 0 y "needed" > 0.
    * \post En el inventario de la ciudad "city_name" hay un nuevo producto con id "id". La ciudad "city_name". tiene "owned" uds. del producto y necesita "needed" uds. del producto.
   */
   void addProduct(string, int id, int owned, int needed);

   /**
    * @brief Modifica los datos del producto con identificador "id" en el inventario de la ciudad "city_name".
    * 
    * Es decir, modifica cuantas unidades se tienen de dicho producto y cuantas se necesitan.
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name". "newOwned" >= 0 y "newNeeded" > 0.
    * \post La ciudad "city_name" tiene "newOwned" uds. del producto "id" y necesita "newNeeded" uds.
   */
   void setProductStatus(int id, int newOwned, int newNeeded);

   /**
    * @brief Elimina el producto "id" del inventario del parámetro implícito
    * \pre El producto con id "id" se encuentra dentro del inventario del parámetro implícito.
    * \post El inventario del parámetro implicito ya no contiene el producto "id". Todas las uds de dicho producto que tenia la ciudad han desaparecido.
   */
   void removeProduct(int id);

   // I/O

   void read();

};

#endif