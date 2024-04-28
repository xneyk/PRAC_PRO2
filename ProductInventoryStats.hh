/**
 * @file ProductInventoryStats.hh
 * @brief Especificación de un producto dentro de un inventario
 * 
 * Dentro de un inventario la información almacenada sobre el producto es cuantas unidades de dicho producto hay y cuantas se necesitan.
*/

#ifndef _PRODUCT_INVENTORY_STATS_HH_
#define _PRODUCT_INVENTORY_STATS_HH_

class ProductInventoryStats {
private:

   int needed;
   int owned;

public:

   // Constructoras

   /**
    * @brief Creadora de productos dentro de un inventario
    * \pre "needed" > 0 y "owned" >= 0.
    * \post Se ha creado una instancia de ProductInventoryStats con sus correspondientes unidades requeridas: "needed", unidades en tenencia: "owned".
   */
   ProductInventoryStats(int needed, int owned);

   // Modificadores

   /**
    * @brief Modificadora de unidades necesarias.
    * \pre "newNeeded" > 0
    * \post El atributo unidades necesarias del parámetro implícito ahora es "newNeeded".
   */
   void setNeeded(int newNeeded);
   
   /**
    * @brief Modificadora de unidades disponibles del producto en el inventario.
    * \pre "newOwned" >= 0
    * \post El atributo unidades disponibles en el inventario del parámetro implícito ahora es "newOwned".
   */
   void setOwned(int newOwned);

   // Consultoras

   /**
    * @brief Consultora de unidades necesarias.
    * \pre Cierto.
    * \post Retorna el numero de unidades necesarias del parametro implícito
   */
   int getNeeded() const;

   /**
    * @brief Consultora de unidades disponibles.
    * \pre Cierto.
    * \post Retorna el numero de unidades disponibles del parametro implícito
   */
   int getOwned() const;

};

#endif