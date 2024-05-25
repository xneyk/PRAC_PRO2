/**
 * @file River.hh
 * @brief Especificación de la clase River
*/

#ifndef _RIVER_HH_
#define _RIVER_HH_

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <list>
#include <string>
using namespace std;
#endif

#include "City.hh"
#include "Boat.hh"
#include "Travel.hh"

/**
 * @class River
 * @brief Un río (River) representa una estructura (arborescente) donde hay ciudades en sus fuentes/nacimientos y en los puntos en que dos afluentes se unen, incluida la desembocadura, donde casualmente se unen dos afluentes. No hay ciudades en tramos del río que no sean nacimientos o uniones de afluentes.
*/
class River {
private:

   BinTree<string> structure;
   // Representa la estructura de la cuenca fluvial
   // Observación: Notad que solamente se trata de sus identificadores, la información
   // de cada ciudad se almacena en una clase "City".
   
   map<string, City> citySet; // Tal vez seria buena idea abstraerlo en una clase CitySet.
   // Es en este conjunto de ciudades donde se relaciona a cada ciudad con su identificador
   // correspondiente.

   int total_cities;
   map<string, int> cityPreorder;
   // Relaciona cada ciudad con su indice del preorden.
   
   list<string> travels;
   // Almacena el nombre de las ciudades donde a acabado cada viaje realizado en el río.
   // Cada nombre corresponde a un viaje, concretamente el que se ha realizado acabando en dicha ciudad.
   // Los viajes se mantienen siempre ordenados cronologicamente.

   /**
    * @brief Añade la última ciudad del viaje ("city_name") a los viajes realizados.
    * \pre Cierto
    * \post "city_name" se ha añadido como último viaje realizado.
   */
   void addTravel(string city_name);

   /**
    * @brief Método auxiliar para la lectura de la estructura del río.
    * \pre La información del nuevo rio se encuentra en el canal estandard siguiendo el formato específico.
    * \post Se ha sobre escrito parámetro implícito con la nueva estructura de la cuenta. Todas sus ciudades han quedado con el inventario vacio.
   */
   BinTree<string> buildRiver();
   
   /**
    * @brief Método auxiliar para la redistribución.
    * 
    * Recibe la estructura del subarbol sobre el que se debe hacer la redistribución.
    * \pre La raíz de structure no es vacia.
    * \post Todas las ciudades han comerciado con sus vecinos immediados. primero con la situada a la derecha y luego con la situada a la izquierda.
   */
   void redistribute(BinTree<string> structure, const ProductSet &product_set);

   /**
    * @brief Encuentra la ruta más provechosa para el barco
    * \pre "current_travel" contiene el estado del viaje realizado para llegar a la ciudad actual.
    * \post "best_travel" guarda el mejor viaje realizado hasta el momento.
   */
   void findOptimalRoute(BinTree<string> structure, Travel current_travel, Travel &best_travel) const;

   /**
    * @brief Metodo auxiliar de "findOptimalRoute". Simula la transacción entre barco y ciudad dentro del viaje "current_travel".
    * \pre "current_travel" contiene el estado del viaje realizado para llegar a la ciudad actual.
    * \post "current_travel" contiene el estado del viaje realizado una vez se comercia con la ciudad visitada ("city_name").
   */
   void tryTransaction(string city_name, Travel &current_travel) const;

   /**
    * @brief Efectua la transacción entre barco y ciudad
    * \pre Cierto.
    * \post La ciudad "city_name" y el barco "boat" han comerciado.
   */
   void transaction(string city_name, Boat &boat, const ProductSet &product_set);

   /**
    * @brief Comercio entre barco y ciudades.
    * \pre 
   */
   void trade(BinTree<string> structure, string last_city, Boat &boat, const ProductSet &product_set);

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
    * \post Retorna "true" en caso de exisitir, "false" en caso contrario.
   */
   bool existsCityWithId(string name) const;

   /**
    * @brief Comprueva si la ciudad "city_name" tiene el producto "id" en su inventario.
    * \warning Se considera que lo tiene aunque sus unidades sean 0.
    * \pre La ciudad "city_name" existe.
    * \post Retorna retorna "true" en caso de contenterlo, "false" en caso contrario.
   */
   bool cityHasProduct(string city_name, int id) const;

   /**
    * @brief Consultora de las unidades del producto "id" que tiene la ciudad "city_name".
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name".
    * \post Retorna el numero de unidades del producto "id" que tiene la ciudad "city_name".
   */
   int getProductOwnedById(string city_name, int product_id) const;

   /**
    * @brief Consultora de las unidades del producto "id" que necesita la ciudad "city_name".
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name".
    * \post Retorna el numero de unidades del producto "id" que necesita la ciudad "city_name".
   */
   int getProductNeededById(string city_name, int product_id) const;

   // Modificadoras

   /**
    * @brief Añade el producto con identificador "id" al inventario de la ciudad "city_name".
    * \pre El producto con id "id" existe y no se encuentra dentro del inventario de la ciudad "city_name". "owned" >= 0 y "needed" > 0.
    * \post En el inventario de la ciudad "city_name" hay un nuevo producto con id "id". La ciudad "city_name". tiene "owned" uds. del producto y necesita "needed" uds. del producto.
   */
   void addProduct(string city_name, int id, const ProductSet &product_set, int owned, int needed);

   /**
    * @brief Modifica los datos del producto con identificador "id" en el inventario de la ciudad "city_name".
    * 
    * Es decir, modifica cuantas unidades se tienen de dicho producto y cuantas se necesitan.
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name". "new_owned" >= 0 y "new_needed" > 0.
    * \post La ciudad "city_name" tiene "new_owned" uds. del producto "id" y necesita "new_needed" uds.
   */
   void setProductStatus(string city_name, int id, const ProductSet &product_set, int new_owned, int new_needed);

   /**
    * @brief Elimina el producto "id" del inventario de la ciudad "city_name"
    * \pre El producto con id "id" se encuentra dentro del inventario de la ciudad "city_name". "city_name" se encuentra en el parámetro implícito.
    * \post El inventario de la ciudad "city_name" ya no contiene el producto "id". Todas las uds de dicho producto que tenia la ciudad han desaparecido.
   */
   void removeProduct(string city_name, int id, const ProductSet &product_set);

   /**
    * @brief Dos ciudades (existentes) del rio comercian entre ellas.
    * 
    * Una ciudad le da a la otra todos los productos que le sobren hasta alcanzar si es posible los que la otra necesite, y viceversa.
    * \pre "cityA" y "cityB" son los identificadores de dos ciudades EXISTENTES en el parámetro implícito.
    * \post Las dos ciudades han intercambiado productos. Ninguna de las dos se queda con menos unidades de las necesarias si la cantidad de dicho producto era superior que las que necesita.
   */
   void trade(string city_A, string city_B, const ProductSet &product_set);

   /**
    * @brief A partir de la ciudad de la desembocadura, cada ciudad comerciará con las dos ciudades inmediatamente situadas río arriba.
    * 
    * Primero comerciará la ciudad de la desembocadura con la ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda, y así sucesivamente, hasta llegar a las ciudades de los nacimientos.
    * \pre Cierto.
    * \post Todas las ciudades han comerciado con sus vecinos immediados. primero con la situada a la derecha y luego con la situada a la izquierda.
   */
   void redistribute(const ProductSet &product_set);

   /**
    * @brief Acción de comerció entre un barco y una ruta ciudades del Rio. 
    * 
    * El como se decide en que ruta comerciar en caso que haya más de una ruta igual de provechosa es quedarse con la más corta, y en caso de que tengan la misma longitud, quedarse con la que viene río arriba a mano derecha.
    * \pre Cierto.
    * \post El barco ha comerciado con todas aquellas ciudades del camino que mas provecho le daba.
    * \return Retorna la cantidad total de elementos transaccionados (vendidos + comprados).
   */
   int travel(Boat boat, const ProductSet &product_set);

   // I/O

   /**
    * @brief Input de la clase River
    * \pre La información del nuevo rio se encuentra en el canal estandard siguiendo el formato específico.
    * \post Se ha sobre escrito parámetro implícito con la nueva estructura de la cuenta. Todas sus ciudades han quedado con el inventario vacio.
   */
   void read();

   /**
    * @brief Input de una ciudad por el canal estándar.
    * \pre En el canal estándar se encuentra la información del inventario en el siguiente formato: se lee un número indicando cuatos productos se añaden. A continuación vienen n lineas de "product_id" "owned" "needed". "needed" > 0.
    * \post Se ha leido la información pertinente de la ciudad y todos los datos se encuentran disponibles en el parámetro implicito.
   */
   void readCityWithId(string city_name, const ProductSet &product_set);

   /**
    * @brief Output del contenido de una ciudad del parámetro implícito
    * \pre La ciudad se encuentra en el parámetro implícito
    * \post Se ha dejado en el canal estandard de salida el nombre de la ciudad seguido de su inventario.
   */
   void printCityWithId(string city_name) const;

   /**
    * @brief Output del peso y volumen total de una ciudad del parámetro implícito.
    * \pre La ciudad se encuentra en el parámetro implícito
    * \post Se ha dejado en el canal estandard de salida el peso y volumen total de la ciudad.
   */
   void printCityWeightAndVolume(string city_name) const;

   /**
    * @brief Output del estado de un producto en el inventario de una ciudad del parámetro implícito.
    * \pre La ciudad se encuentra en el parámetro implícito, el producto se encuentra en su inventario.
    * \post Se ha dejado en el canal estandard de salida cuantas uds. tiene y cuantas uds. necesita la ciudad de dicho producto.
   */
   void printProductStatsById(string city_name, int id);

   // SOLO PARA LA FASE DE DESARROLLO PODER VER COMO SE ORGANIZA EL RIO, ELIMINAR LUEGO.
   void printRiver();
};

#endif