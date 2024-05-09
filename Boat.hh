/**
 * @file Boat.hh
 * @brief Especificación de la clase Boat.
 */

#ifndef _BOAT_HH_
#define _BOAT_HH_ 

/**
 * @class Boat
 * @brief Un barco (Boat) se dedica a hacer viajes, donde intenta vender una cantidad de un cierto producto y comprar una cantidad de otro cierto producto. Estos dos productos siempre son distintos. Ambas cantidades serán no negativas y al menos una de ellas será estrictamente positiva
*/
class Boat {
private:

   int productForSaleId;
   int availible;
   int productToBuyId;
   int purchased;

public:

   // Constructoras

   /**
    * @brief Creadora de barcos inicializados
    * 
    * Un barco inicializado es aquel que tiene definidos que producto vende, cual compra, y cuantos dispone de cada uno.
    * \pre "productForSaleId" != "productToBuyId" y ambos son productos existentes. "availible" y "purchased" deben ser mayores que cero y al menos uno estirictamente mayor que cero.
    * \post Se ha creado un barco inicializado. La cantidad de productos "productForSaleId" que tiene el barco es "availible" y la cantidad de productos "productToBuyId" que tiene el barco es "purchased"
   */
   Boat(int productForSaleId, int availible, int productToBuyId, int purchased);

   /**
    * @brief Creadora copiadora de barcos
    * 
    * Crea una nueva instancia de Boat como copia de una ya existente.
    * \pre Cierto.
    * \post Los atributos de la nueva instancia son iguales a los del parámetro de referencia uno a uno.
   */
   Boat(const Boat &boat);

   // Modificadoras

   /**
    * @brief Modifica la cantidad del producto a vender que tiene el barco.
    * \pre "amount" <= que la cantidad disponible del producto a la venta.
    * \post La cantidad de producto disponible a la venta del paràmetro implícito ha disminuido "amount" unidades.
   */
   void sellProduct(int amount);

   /**
    * @brief Modifica la cantidad del producto comprado que tiene el barco.
    * \pre Cierto.
    * \post La cantidad de producto comprado por el paràmetro implícito ha aumentado "amount" unidades.
   */
   void buyProduct(int amount);

   /**
    * @brief Modificadora de la información del barco.
    * \pre "productForSaleId" != "productToBuyId" y ambos son productos existentes. "availible" y "purchased" deben ser mayores que cero y al menos uno estirictamente mayor que cero.
    * \post Se ha moidificado el parámetro implícito. La cantidad de productos "productForSaleId" que tiene es "availible" y la cantidad de productos "productToBuyId" es "purchased"
   */
   void setBoat(int productForSaleId, int availible, int productToBuyId, int purchased);

   // Consultoras

   /**
    * @brief Consultora de la cantidad disponible del producto a la venta.
    * \pre Cierto.
    * \post Retorna la cantidad que tiene el parámetro implícito de producto a la venta.
   */
   int getAvailible();

   /**
    * @brief Consultora de la cantidad de producto de compra que tiene.
    * \pre Cierto.
    * \post Retorna la cantidad que tiene el parámetro implícito del producto que tiene que comprar.
   */
   int getPurchased();
   
   /**
    * @brief Consultora del identificador del producto que se debe vender.
    * \pre Cierto.
    * \post Retorna el identificador del producto que vende el parámetro implícito.
   */
   int getProductToBuyId();

   /**
    * @brief Consultora del identificador del producto que se debe comprar.
    * \pre Cierto.
    * \post Retorna el identificador del producto que compra el parámetro implícito.
   */
   int getProductForSaleId();

   // I/O

   /**
    * @brief Output de la clase Boat
    * \pre El barco esta inicializado.
    * \post Se escribe el contenido del barco siguiendo el formato: "producto_vender" "cantidad" "producto_comprar" "cantidad"
   */
   void print();
};

#endif