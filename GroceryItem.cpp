// Isaiah Cabugos CPSC131 HW 1

#include "GroceryItem.hpp"
#include <cstdlib>
#include <iomanip>
#include <sstream>


const double EPSILON = 0.0001;

/* ===== Constructors ===== */
GroceryItem::GroceryItem(const std::string& productName, const std::string& brandName,
  const std::string& upcCode, double price)
           : _productName(productName), _brandName(brandName), _upcCode(upcCode),
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
           << std::to_string(groceryItem.price()) << std::endl;

   return stream;
}

std::istream& operator>>( std::istream& stream, GroceryItem& groceryItem ) {
       std::string comma = {};

       stream >> std::quoted(groceryItem._upcCode) >> comma
              >> std::quoted(groceryItem._brandName) >> comma
              >> std::quoted(groceryItem._productName) >> comma
              >> groceryItem._price;

       return stream;
}

/* ===== Logic Operators ===== */
bool operator== (const GroceryItem& lhs, const GroceryItem& rhs) {

       return lhs.upcCode() == rhs.upcCode()
              && lhs.brandName() == rhs.brandName()
              && lhs.productName() == rhs.productName()
              && std::abs(lhs.price() - rhs.price()) < EPSILON;
}

bool operator< (const GroceryItem& lhs, const GroceryItem& rhs) {

       return lhs.upcCode() < rhs.upcCode()
              || lhs.brandName() < rhs.brandName()
              || lhs.productName() < rhs.productName()
              || lhs.price() < rhs.price();
}

bool operator!=( const GroceryItem & lhs, const GroceryItem & rhs ){
       return !(lhs == rhs);
}

bool operator<=( const GroceryItem & lhs, const GroceryItem & rhs ){
       return !(lhs > rhs);
}

bool operator> ( const GroceryItem & lhs, const GroceryItem & rhs ){
       return rhs < lhs;
}

bool operator>=( const GroceryItem & lhs, const GroceryItem & rhs ){
       return !(lhs < rhs);
}
