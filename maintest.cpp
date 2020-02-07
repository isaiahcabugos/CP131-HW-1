//Isaiah Cabugos

#include "groceryItemBeta.hpp"
#include <fstream>
#include <iomanip>

int main() {
       GroceryItem items("Supreme", "Brick", "$WAGP1N0", 21.50);
       GroceryItem itemsTwin("Supreme", "Brick", "$WAGP1N0", 21.50001);
       GroceryItem items3("Timberland");
       GroceryItem items4("Wack", "Stack");
       GroceryItem items5("Lack", "Mac", "Back");
       std::string itemList = "\"Wow\", \"Yes\", \"ABCDEFG\", \"10.01\"";
       std::ifstream inFile;
       std::cout << items << std::endl;

       GroceryItem items2;

       inFile.open("test.txt");

       std::cout << "Before: " << items2 << std::endl;
       //std::cin >> items2;
       inFile >> items2;

       std::cout << "After: " << items2 << std::endl;

       std::cout << "Constructors: \n" << items3 << "\n" << items4
                 << "\n" << items5 << std::endl;

       /* ========== Testing equality
       long double x = 10.00012;
       long double y = 10.00014;
       int eq = x*10000 - y*10000;

       std::cout << std::setprecision(6) << std::fixed;
       std::cout << x << " and " << y << std::endl;
       std::cout << x*10000.000 << " and " << y*10000.000 << std::endl;
       std::cout << "\n" << eq << std::endl;
          ========== */

       if(items == itemsTwin) {
              std::cout << "Equals Success!" << std::endl;
       } else {
              std::cout << "Not equal." << std::endl;
       }

       if(items < itemsTwin) {
              std::cout << "items is less than itemsTwin" << std::endl;
       } else
              std::cout << "items not less than itemsTwin" << std::endl;

       return 0;
}
