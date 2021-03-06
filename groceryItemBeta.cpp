//Isaiah Cabugos

#include "groceryItemBeta.hpp"
#include <sstream>
#include <iomanip>

/* ===== Constructors ===== */
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
       std::string pricestr = {};
       std::string trash = {};

       stream >> std::quoted(groceryItem._upcCode) >> trash
              >> std::quoted(groceryItem._brandName) >> trash
              >> std::quoted(groceryItem._productName) >> trash
              >> std::quoted(pricestr);

       groceryItem._price = std::stod(pricestr);

       return stream;
}

/* ===== Logic Operators ===== */
// Check if these are right
bool operator== (const GroceryItem& lhs, const GroceryItem& rhs) {
       int rounded = (lhs.price()*10000 - rhs.price()*10000);

       return lhs.upcCode() == rhs.upcCode()
              && lhs.brandName() == rhs.brandName()
              && lhs.productName() == rhs.productName()
              && rounded == 0;
}

bool operator< (const GroceryItem& lhs, const GroceryItem& rhs) {
       int rounded = (lhs.price()*10000 - rhs.price()*10000);

       return lhs.upcCode() < rhs.upcCode()
              || lhs.brandName() < rhs.brandName()
              || lhs.productName() < rhs.productName()
              || rounded < 0;
}

bool operator!=( const GroceryItem & lhs, const GroceryItem & rhs ){
       return !(lhs == rhs);
}

bool operator<=( const GroceryItem & lhs, const GroceryItem & rhs ){
       return lhs < rhs || lhs == rhs;
}

bool operator> ( const GroceryItem & lhs, const GroceryItem & rhs ){
       return !(lhs <= rhs);
}

bool operator>=( const GroceryItem & lhs, const GroceryItem & rhs ){
       return !(lhs < rhs);
}
