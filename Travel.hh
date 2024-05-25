/**
 * @file Travel.hh
 * @brief Especificación de la clase Travel
*/

#ifndef _TRAVEL_HH_
#define _TRAVEL_HH_

#ifndef NO_DIAGRAM
#include <stack>
#include <string>
using namespace std;
#endif

#include "Boat.hh"


class Travel {

private:
   int product_for_sale_id;
   int stock; // Cantidad que se quiere vender.
   int product_to_buy_id;
   int buy_target; // Cantidad que queda por comprar.
   int length;
   string last_trade;

public:
   // Constructoras
   
   /**
    * @brief Constructora de viajes vacios.
    * \pre Cierto.
    * \post Se ha creado una nueva instancia vacia de la clase Travel.
   */
   // Travel(); <-- SEGURAMENTE NO NECESARIA

   /**
    * @brief Creadora de viajes a partir de las propiedades de un barco.
    * \pre Cierto
    * \post el producto que se vende, el que se compra, la cantidad disponible y el objetivo de compra es el mismo que para el barco "boat".
   */
   Travel(const Boat &boat);

   /**
    * @brief Constructora copiadora de viajes.
    * \pre Cierto.
    * \post Se ha creado nueva instancia identica a "travel".
   */
   // Travel(const Travel &travel);

   // Modificadoras

   /**
    * @brief Actualiza la cantidad disponible y el objetivo de compra.
    * \pre Cierto.
    * \post La cantidad disponible ha disminuido sold y el objetivo de compra ha disminuido "bought"
   */
   void updateStatus(int sold, int bought);

   /**
    * @brief Añade "city_name" como la última ciudad con la que se ha comerciado.
    * \pre Cierto.
    * \post Se ha asignado "city_name" como última ciudad de este viaje.
   */
   void setLastTrade(string city_name);
   
   /**
    * @brief Incrementa en una unidad la longitud del viaje.
    * \pre Cierto.
    * \post longitud = longitud + 1.
   */
   void increaseLength();

   // Consultoras
   
   /**
    * @brief Consultora de la última ciudad con la que se ha comerciado en el viaje.
    * \pre Cierto.
    * \post Retorna el nombre de la última ciudad con la que se ha comerciado.
   */
   string getLastTrade() const;

   /**
    * @brief Consultora de la longitud del viaje
    * \pre Cierto
    * \post Retorna la longitud del viaje.
   */
   int getLength() const;

   /**
    * @brief Consultora del identificador del producta a vender.
    * \pre Cierto.
    * \post Retorna el identificador del producta a vender.
   */
   int getProductForSaleId() const;

   /**
    * @brief Consultora del identificador del producta a comprar.
    * \pre Cierto.
    * \post Retorna el identificador del producto a comprar.
   */
   int getProductToBuyId() const;

   /**
    * @brief Consultora de la cantidad disponible de producto a vender.
    * \pre Cierto.
    * \post Retorna la cantidad disponible del producto a vender.
   */
   int getStock() const;

   /**
    * @brief Consultora de la cantidad que se debe vender para llegar al objetivo de compras.
    * \pre Cierto.
    * \post Retorna la cantidad que se debe vender para llegar al objetivo de compras.
   */
   int getBuyTarget() const;

   /**
    * @brief Decide si se ha alcanzado el objetivo del viaje.
    * 
    * Es decir, si se ha vendido todos los productos y se ha comprado tantas unidades como se deseaba.
    * \pre Cierto.
    * \post Retorna "true" si cantidad disponible y la cantidad que se debe vender para llegar al objetivo de compras es 0, "false" en caso contrario.
   */
   bool objectiveAchived() const;

   /**
    * @brief Decide si el viaje "travel" es mejor viaje que el parámetro implícito.
    * 
    * Mejor viaje: Se ordenan en nivel de importancia de decisión. Si no deciden se comprueva la siguiente condición
    *    1. El total de productos comprados y vendidos es mayor.
    *    3. El viaje es más corto
    *    4. En caso de empate gana el parámetro implícito
    *    
    * \pre Cierto
    * \post Retorna "true" si el parámetro implícito es mejor, "false" en caso contrario.
   */
   bool betterTravelThan(const Travel &travel) const;

};

#endif