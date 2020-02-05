// Isaiah Cabugos CPSC131 HW 1

#include "GroceryItem.hpp"

class GroceryItem {
public:
  /* ===== Constructors ===== */
  GroceryItem(const std::string& pName) : productName(pName) {}
  GroceryItem(const std::string& pName, const std::string& bName)
             : productName(pName), brandName(bName) {}
  GroceryItem(const std::string& pName, const std::string& bName,
    const std::string& upc)
             : productName(pName), brandName(bName), upc_(upc) {}
  GroceryItem(const std::string& pName, const std::string& bName,
    const std::string& upc, const double& price)
             : productName(pName), brandName(bName), upc_(upc),
               price_(price) {}

private:
  std::string upc_;
  std::string brandName;
  std::string productName;
  double price_ = 0.0;
};

/* ===== Accessors ===== */
std::string GroceryItem::upcCode() const{ return upc_; }
std::string GroceryItem::brandName() const{ return brandName; }
std::string GroceryItem::productName() const{ return productName; }
double GroceryItem::price() const{ return price_; }

/* ===== Mutators ===== */
void GroceryItem::upcCode(const std::string& upcCode) { upc_ = upcCode; }
void GroceryItem::brandName(const std::string& bName) { brandName = bName; }
void GroceryItem::productName(const std::string& pName) { productName = pName; }
void GroceryItem::price(const double& price) { price_ = price;}

/* ===== Insertion/Extraction ===== */
friend std::ostream & GroceryItem::operator<<( std::ostream & stream,
  const GroceryItem & groceryItem ) {
    std::string concat = {};
    concat << std::quoted(groceryItem.upcCode()) + ", "
            + std::quoted(groceryItem.brandName()) + ", "
            + std::quoted(groceryItem.productName()) + ", "
            + std::quoted(groceryItem.price()) << std::endl;

    stream << concat;
    return stream;
}

friend std::istream & GroceryItem::operator>>( std::istream & stream,
  GroceryItem & groceryItem ) {

}
