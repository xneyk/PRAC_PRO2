/**
 * @file ProductSet.hh
 * @brief Especificación de la classe ProductSet
*/
#ifndef _PRODUCT_SET_HH_
#define _PRODUCT_SET_HH_

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "Product.hh"
using namespace std;

/**
 * @class ProductSet
 * @brief Representa un conjunto de productos (clase Product). Cada producto se identifica mediante un id numérico.
*/
class ProductSet {
private:

   // Se ha decidido representar el conjunto de productos como 
   // un mapa de nombre del producto --> características del producto
   map<int,Product> setOfProducts;
   int lastIdAdded;

public:

   // Constructoras

   /**
    * @brief Creadora por defecto
    * \pre Cierto.
    * \post Crea un nuevo conjunto de producto vacío (sin producto)
   */
   ProductSet();

   // Modificadoras

   /**
    * @brief Añade un producto al conjunto.
    * \pre Cierto.
    * \warning En ningún momento se ha aclarado que peso y volumen deban ser > 0.
    * \post se ha añadido un nuevo producto al parámetro implícito, con su peso y volumen correspondiente, al conjunto de productos. el identificador de éste es el identificador del anterior + 1 en caso de que el conjunto no esté vacío, 1 en otro caso.
   */
   void addProduct(Product product);

   // Consultoras

   /**
    * @brief Consultora del nombre de productos diferentes en el conjunto.
    * \pre Cierto.
    * \post Retorna el múmero de productos diferents en el parámetro implícito.
   */
   int getTotalProducts() const;

   /**
    * @brief Consultora del peso de un producto perteneciente al conjunto
    * \pre el producto con identificador "id" pertenece al conjunto.
    * \post Retorna el peso del producto con con identificador "id" contenido en el parámetro ímplicito
   */
   int getWeightById(int id) const;

   /**
    * @brief Consultora del volument de un producto perteneciente al conjunto
    * \pre el producto con identificador "id" pertenece al conjunto.
    * \post Retorna el volument del producto con con identificador "id" contenido en el parámetro ímplicito
   */
   int getVolumebyId(int id) const;
};

#endif