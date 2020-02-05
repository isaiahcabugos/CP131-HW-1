//Isaiah Cabugos

#include "groceryItemBeta.hpp"
#include <sstream>

/* ===== Constructors ===== */
/*GroceryItem::GroceryItem(const std::string& pName) : _productName(pName) {}
GroceryItem::GroceryItem(const std::string& pName, const std::string& bName)
           : _productName(pName), _brandName(bName) {}
GroceryItem::GroceryItem(const std::string& pName, const std::string& bName,
  const std::string& upc)
           : _productName(pName), _brandName(bName), _upc(upc) {} */
GroceryItem::GroceryItem(const std::string& pName, const std::string& bName,
  const std::string& upc, double price)
           : _productName(pName), _brandName(bName), _upcCode(upc),
             _price(price) {}

/* ===== Accessors ===== */
std::string GroceryItem::upcCode() const{ return _upcCode; }
std::string GroceryItem::brandName() const{ return _brandName; }
std::string GroceryItem::productName() const{ return _productName; }
double GroceryItem::price() const{ return _price; }

/* ===== Mutators ===== */
void GroceryItem::upcCode(const std::string& upcCode) { _upcCode = upcCode; }
void GroceryItem::brandName(const std::string& bName) { _brandName = bName; }
void GroceryItem::productName(const std::string& pName) { _productName = pName; }
void GroceryItem::price(double price) { _price = price; }

/* ===== Insertion/Extraction ===== */
std::ostream & operator<<( std::ostream& stream, const GroceryItem& groceryItem ) {
    stream << std::quoted(groceryItem.upcCode()) << ", "
           << std::quoted(groceryItem.brandName()) << ", "
           << std::quoted(groceryItem.productName()) << ", "
           << std::quoted(std::to_string(groceryItem.price())) << std::endl;

   return stream;
}

std::istream& operator>>( std::istream& stream, GroceryItem& groceryItem ) {
       std::string attribute = {};
       std::getline(stream, attribute, ',');
       groceryItem.upcCode(attribute);    // Populates

       std::getline(stream, attribute, ',');
       groceryItem.brandName(attribute);

       std::getline(stream, attribute, ',');
       groceryItem.brandName(attribute);

       /*std::getline(stream, attribute, ',');
       groceryItem.price(attribute);*/
       return stream;
}
