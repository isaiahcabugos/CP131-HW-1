// Isaiah Cabugos CPSC131 HW 1

#include "GroceryItem.hpp"

class GroceryItem {
public:
  /*===== Constructors ===== */
  GroceryItem(const std::string& productName) : _product_name(productName) {};
  GroceryItem(const std::string& productName, const std::string& brandName) : _product_name(productName), _brand_name(brandName) {};
  GroceryItem

private:
  std::string _product_name = {};
  std::string _brand_name = {};
  std::string _UPC = {};
  double _price = 0;
};
