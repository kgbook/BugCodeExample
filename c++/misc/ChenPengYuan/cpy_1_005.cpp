#include <iostream>
#include <vector>

class Product {
public:
    Product(std::string name, double price)
            : name_(name), price_(price) {}

    std::string GetName() const { return name_; }
    double GetPrice() const { return price_; }

private:
    std::string name_;
    double price_;
};

class ShoppingCart {
public:
    void AddProduct(const Product& product) {
        products_.push_back(product);
    }

    double CalculateTotal() const {
        double total = 0.0;
        for (auto& p : products_) {
            total += p.GetPrice();
        }
        return total;
    }

    Product GetMostExpensiveProduct() const {
        if (products_.empty()) return Product("None", 0.0);

        Product most_expensive_product = products_.at(0);
        for (const auto& p : products_) {
            if (p.GetPrice() > most_expensive_product.GetPrice()) {
                most_expensive_product = p;
            }
        }
        return most_expensive_product;
    }

private:
    std::vector<Product> products_;
};

int main() {
    ShoppingCart cart;
    cart.AddProduct(Product("Laptop", 999.99));
    cart.AddProduct(Product("Smartphone", 599.99));
    cart.AddProduct(Product("Book", 19.99));

    std::cout << "Total cost of products: " << cart.CalculateTotal() << std::endl;
    Product expensive = cart.GetMostExpensiveProduct();
    std::cout << "The most expensive product is: " << expensive.GetName() << " Price: " << expensive.GetPrice() << std::endl;

    return 0;
}
