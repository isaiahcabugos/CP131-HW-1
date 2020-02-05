//Isaiah Cabugos

#include "groceryItemBeta.hpp"

int main() {
       GroceryItem items("Supreme", "Brick", "$WAGP1N0", 21.50);
       std::string itemList = "\"Wow\", \"Yes\", \"ABCDEFG\"";
       std::cout << items << std::endl;

       GroceryItem items2;

       std::cout << "Before: " << items2 << std::endl;
       std::cin >> items2;
       std::cout << "After: " << items2 << std::endl;
       return 0;
}
