/**
 * @file ProductInventoryStats.hh
 * @brief Especificación de la clase ProductInventoryStats.
*/

#ifndef _PRODUCT_INVENTORY_STATS_HH_
#define _PRODUCT_INVENTORY_STATS_HH_

/**
 * @class ProductInventoryStats
 * @brief Representa un producto dentro de un inventario. La información almacenada sobre el producto es cuantas unidades de dicho producto hay y cuantas se necesitan.
*/
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
    * \pre "new_needed" > 0
    * \post El atributo unidades necesarias del parámetro implícito ahora es "new_needed".
   */
   void setNeeded(int new_needed);
   
   /**
    * @brief Modificadora de unidades disponibles del producto en el inventario.
    * \pre "new_owned" >= 0
    * \post El atributo unidades disponibles en el inventario del parámetro implícito ahora es "new_owned".
   */
   void setOwned(int new_owned);

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