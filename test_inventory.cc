#include <iostream>
using namespace std;

#include "Inventory.hh"
#include "ProductSet.hh"

int main() {
   ProductSet product_set;
   Inventory inventory;

   string cmd;
   int id, need, own;
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
      // INVENTORY
      else if (cmd == "addProduct") {
         cin >> id >> own >> need;
         cout << "#addProduct{" << id << "}<--[" << own << "," << need << "]" << endl;
         inventory.addProduct(id, product_set, own, need);
      }
      else if(cmd == "setProductStatus") {
         cin >> id >> own >> need;
         cout << "#setProductStatus{" << id << "}<--[" << own << "," << need << "]" << endl;
         inventory.setProductStatus(id, product_set, own, need);
      }
      else if(cmd == "removeProduct") {
         cin >> id;
         cout << "#removeProduct{" << id << "}" << endl;
         inventory.removeProduct(id, product_set);
      }
      else if(cmd == "getTotalWeight") {
         cout << "#getTotalWeight" << endl;
         cout << inventory.getTotalWeight() << endl;
      }
      else if(cmd == "getTotalVolume") {
         cout << "#getTotalVolume" << endl;
         cout << inventory.getTotalVolume() << endl;
      }
      else if(cmd == "getOwnedById") {
         cin >> id;
         cout << "#getOwnedById{" << id << "}" << endl;
         cout << inventory.getOwnedById(id) << endl;
      }
      else if(cmd == "getNeededById") {
         cin >> id;
         cout << "#getNeededById{" << id << "}" << endl;
         cout << inventory.getNeededById(id) << endl;
      }
      else if(cmd == "read") {
         cout << "#read" << endl;
         inventory.read(product_set);
      }
      else if(cmd == "print") {
         cout << "#print" << endl;
         inventory.print();
      }
   }
}