#include <iostream>
using namespace std;

#include "ProductSet.hh"

int main() {
   ProductSet product_set;

   string cmd;
   int id;
   while (cin >> cmd and cmd != "end") {

      if (cmd == "addProductToSet") {
         int weight, volume;
         cin >> weight >> volume;
         product_set.addProduct(Product(weight, volume));
      }
      else if (cmd == "existsProductWithId") {
         cin >> id;
         cout << "#existsProductWithId{" << id << "}" << endl;
         cout << product_set.existsProductWithId(id) << endl;
      }
      else if (cmd == "getTotalProducts") {
         cout << "#getTotalProducts" << endl;
         cout << product_set.getTotalProducts() << endl;
      }
      else if (cmd == "getWeightById") {
         cin >> id;
         cout << "#getWeightById{" << id << "}" << endl;
         cout << product_set.getWeightById(id) << endl;
      }
      else if (cmd == "getVolumeById") {
         cin >> id;
         cout << "#getVolumeById{" << id << "}" << endl;
         cout << product_set.getVolumeById(id) << endl;
      }
   }
}