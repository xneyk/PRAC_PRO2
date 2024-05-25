/**
 * @file Boat.hh
 * @brief Especificación de la clase Boat.
 */

#ifndef _BOAT_HH_
#define _BOAT_HH_ 

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#include <string>
using namespace std;
#endif

/**
 * @class Boat
 * @brief Un barco (Boat) se dedica a hacer viajes, donde intenta vender una cantidad de un cierto producto y comprar una cantidad de otro cierto producto. Estos dos productos siempre son distintos. Ambas cantidades serán no negativas y al menos una de ellas será estrictamente positiva
*/
class Boat {
private:

   int productForSaleId;
   int availible;
   int productToBuyId;
   int buy_target;
   list<string> travels;

public:

   // Constructoras

   /**
    * @brief Creadora de barcos no inicializados
    * 
    * Un barco inicializado es aquel que tiene definidos que producto vende, cual compra, y las cantidades de cada uno.
    * \pre Cierto.
    * \post Se ha creado un barco NO inicializado.
   */
   Boat();

   /**
    * @brief Creadora de barcos inicializados
    * 
    * Un barco inicializado es aquel que tiene definidos que producto vende, cual compra, y cuantos dispone de cada uno.
    * \pre "productForSaleId" != "productToBuyId" y ambos son productos existentes. "availible" y "buy_target" deben ser mayores que cero y al menos uno estirictamente mayor que cero.
    * \post Se ha creado un barco inicializado. La cantidad de productos "productToBuyId" que quiere el barco es "buy_target" y la cantidad de productos "productForSaleId" que tiene el barco es "availible".
    * \warning La nueva instancia no ha realizado ningún viaje.
   */
   Boat(int productToBuyId, int buy_target, int productForSaleId, int availible);

   /**
    * @brief Creadora copiadora de barcos
    * 
    * Crea una nueva instancia de Boat como copia de una ya existente.
    * \pre Cierto.
    * \post Los atributos de la nueva instancia son iguales a los del parámetro de referencia uno a uno.
   */
   // Boat(const Boat &boat);

   // Modificadoras

   /**
    * @brief Modifica la cantidad del producto que quiere comprar.
    * \pre Cierto.
    * \post La cantidad que quiere comprar ha disminuido "amount" unidades.
   */
   void buyProduct(int amount);

   /**
    * @brief Modifica la cantidad del producto a vender que tiene el barco.
    * \pre "amount" <= que la cantidad disponible del producto a la venta.
    * \post La cantidad de producto disponible a la venta del paràmetro implícito ha disminuido "amount" unidades.
   */
   void sellProduct(int amount);

   /**
    * @brief Modificadora de la información del barco.
    * \pre "productForSaleId" != "productToBuyId" y ambos son productos existentes. "availible" y "buy_target" deben ser mayores que cero y al menos uno estirictamente mayor que cero.
    * \post Se ha moidificado el parámetro implícito. La cantidad de productos "productToBuyId" es "buy_target" y la cantidad de productos "productForSaleId" que tiene es "availible".
   */
   void setBoat(int productToBuyId, int buy_target, int productForSaleId, int availible);

   /**
    * @brief Añade la última ciudad del viaje ("city_name") a los viajes realizados.
    * \pre Cierto
    * \post "city_name" se ha añadido como último viaje realizado.
   */
   void addTravel(string city_name);

   /**
    * @brief Se borra la lista de viajes realizados por el barco.
    * \pre Cierto.
    * \post El barco no ha realizado ningun viaje (Conserva todos los demás atrivutos).
   */
   void clearTravels();

   // Consultoras


   /**
    * @brief Consultora de la cantidad de producto de compra que tiene.
    * \pre Cierto.
    * \post Retorna cuantas unidades en total quiere vender el barco.
   */
   int getBuyTarget() const;
   
   /**
    * @brief Consultora de la cantidad disponible del producto a la venta.
    * \pre Cierto.
    * \post Retorna la cantidad que tiene el parámetro implícito de producto a la venta.
   */
   int getAvailible() const;

   /**
    * @brief Consultora del identificador del producto que se debe vender.
    * \pre Cierto.
    * \post Retorna el identificador del producto que vende el parámetro implícito.
   */
   int getProductToBuyId() const;

   /**
    * @brief Consultora del identificador del producto que se debe comprar.
    * \pre Cierto.
    * \post Retorna el identificador del producto que compra el parámetro implícito.
   */
   int getProductForSaleId() const;
   
   // I/O

   /**
    * @brief Output de la clase Boat.
    * \pre El parámetro implicito esta inicializado.
    * \post Se ha escrito la información del parámetro implícito por el canal estandard, siguiendo el formato especificado.
   */
   void print() const;
};

#endif