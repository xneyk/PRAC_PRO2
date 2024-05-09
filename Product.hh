/**
 * @file Product.hh
 * @brief Especificación de la clase Product
 */

#ifndef _PRODUCT_HH_
#define _PRODUCT_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/**
 * @class Product
 * @brief Representa un producto con su correspondiente peso y volumen
*/
class Product {
private:

   int weight;
   int volume;

public:

   // Constructoras

   /**
    * @brief Creadora de productos no inicializados.
    * \pre Cierto.
    * \post Se ha creado una instancia de producto sin un peso y un volumen assignado.
   */
   Product();

   /**
    * @brief Creadora de productos.
    * 
    * Cualquier producto tiene un peso y un volumen concretos.
    * \pre Cierto.
    * \warning En ningún momento se ha aclarado que peso y volumen deban ser > 0.
    * \post Se ha creado una instancia de producto con peso = "weight" i volumen = "volume".
   */
   Product(int weight, int volume); // el identificador es natural en un conjunto de productos.

   // Consultoras

   /**
    * @brief Consultora del peso de un producto
    * \pre Cierto.
    * \post Retorna el peso del parámetro implícito
   */
   int getWeight() const;

   /**
    * @brief Consultora del volumen de un producto
    * \pre Cierto.
    * \post Retorna el volumen del parámetro implícito
   */
   int getVolume() const;

   // I/O

   /**
    * @brief Método de output de un producto.
    * \pre Cierto.
    * \post Se ha escrito por el canal estándar el peso y volumen del producto (en dicho orden siguiendo el formato: "peso volumen")
   */
   void print() const;
};

#endif