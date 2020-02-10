// Isaiah Cabugos

#include "GroceryItem.hpp"
#include <vector>
#include <fstream>

int main() {
  std::vector<GroceryItem*> groceryList;
  std::vector<GroceryItem*>::reverse_iterator i; // For traversing vector
  std::ofstream outFile("output.txt");
  GroceryItem tempGrocery;

  while (std::cin >> tempGrocery) {
    if(tempGrocery.upcCode() != "" && tempGrocery.brandName() != ""
       && tempGrocery.productName() != "" && tempGrocery.price() > 0){

      groceryList.push_back(new GroceryItem(tempGrocery));
      std::cin.ignore();
    } else {
      std::cout << "Invalid Entry. Ignoring.";
    }

  }

  for(i = groceryList.rbegin(); i != groceryList.rend(); ++i) {
    outFile << "Item: " << *(*i) << std::endl;
  }
  return 0;
}
