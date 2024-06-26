/**
 * @file Travel.hh
 * @brief Especificación de la clase Travel
*/

#ifndef _TRAVEL_HH_
#define _TRAVEL_HH_

#ifndef NO_DIAGRAM
#include <string>
using namespace std;
#endif

#include "Boat.hh"

/**
 * @class Travel
 * @brief Un viaje (Travel) representa y almacena toda la información relevante de un viaje comercial por la cuenca fluvial.
 * 
 * Es decir, este almacena cúal es su longitud, cúal ha sido la última ciudad con la que ha habido comercio y, el estado del barco una vez hecha la ruta hasta dicha ciudad (esta también incluida).
*/
class Travel {

private:
   int product_to_buy_id;
   int buy_target; // Cantidad que queda por comprar.
   int product_for_sale_id;
   int stock; // Cantidad que se quiere vender.
   int length;
   string last_trade;

public:
   // Constructoras

   /**
    * @brief Creadora de viajes a partir de las propiedades de un barco.
    * \pre Cierto
    * \post el producto que se vende, el que se compra, la cantidad disponible y el objetivo de compra es el mismo que para el barco "boat". La longitud del viaje es cero y el nombre de la última ciudad con la que se ha comerciado no esta definido.
   */
   Travel(const Boat &boat);

   // Modificadoras

   /**
    * @brief Actualiza la cantidad disponible y el objetivo de compra.
    * \pre Cierto.
    * \post El objetivo de compra ha disminuido "bought" y la cantidad disponible ha disminuido sold.
   */
   void updateStatus(int bought, int sold);

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
    * @brief Consultora del identificador del producta a comprar.
    * \pre Cierto.
    * \post Retorna el identificador del producto a comprar.
   */
   int getProductToBuyId() const;

   /**
    * @brief Consultora del identificador del producta a vender.
    * \pre Cierto.
    * \post Retorna el identificador del producta a vender.
   */
   int getProductForSaleId() const;

   /**
    * @brief Consultora de la cantidad que se debe vender para llegar al objetivo de compras.
    * \pre Cierto.
    * \post Retorna la cantidad que se debe vender para llegar al objetivo de compras.
   */
   int getBuyTarget() const;

   /**
    * @brief Consultora de la cantidad disponible de producto a vender.
    * \pre Cierto.
    * \post Retorna la cantidad disponible del producto a vender.
   */
   int getStock() const;

   /**
    * @brief Decide si se ha alcanzado el objetivo del viaje.
    * 
    * Es decir, si se ha comprado tantas unidades como se deseaba y se ha vendido todos los productos.
    * \pre Cierto.
    * \post Retorna "true" si la cantidad que se debe vender para llegar al objetivo de compras y la cantidad disponible es 0, "false" en caso contrario.
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