#include <iostream>
#include <string.h>

class Grocery_Item{
    protected: 
        std::string name;
        int price, quantity;
    public:
        // Constructor 
        Grocery_Item(std::string name = "None", int price = 0, int quantity = 0){
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }
        // The virtual keyword is used to allow derived classes to override this function. Plus allowing the other classes to use this function as well without the need to 
        // redefine it in the derived classes.
        virtual int sub_total(){
            return price * quantity;
        }
        virtual ~Grocery_Item(){
            std::cout << "Destructor called for " << name << std::endl;
        }
        // Copy constructor
        Grocery_Item(const Grocery_Item &copyGrocery_Item){
            std::cout << "Copy constructor called" << std::endl;
            name = copyGrocery_Item.name;
            price = copyGrocery_Item.price;
            quantity = copyGrocery_Item.quantity;
        }
        // Copy assignment operator
        Grocery_Item& operator=(const Grocery_Item &copyGrocery_Item){
            std::cout << "Copy Assignment operator called" << std::endl;
            if(this != &copyGrocery_Item){
                name = copyGrocery_Item.name;
                price = copyGrocery_Item.price;
                quantity = copyGrocery_Item.quantity;
            }
            return *this;
        }
        // Print details
        void print_details(){
            std::cout << "Name: " << name << std::endl;
            std::cout << "Price: " << price << std::endl;
            std::cout << "Quantity: " << quantity << std::endl;
        }

};
class Fruit : public Grocery_Item{
    public:
        // Constructor
        Fruit(std::string name = "None", int price = 0, int quantity = 0) : Grocery_Item(name, price, quantity) {}
        // Copy constructor
        Fruit(const Fruit &copyFruit) : Grocery_Item(copyFruit){
            std::cout << "Copy constructor called" << std::endl;
        }
        // Copy assignment operator
        Fruit& operator=(const Fruit &copyFruit){
            std::cout << "Copy Assignment operator called" << std::endl;
            Grocery_Item::operator=(copyFruit);
            return *this;
        }
        // The deconstructor was removed due to already having the grocery item destructor in the base class.
};

class Vegetable : public Grocery_Item{
    public:
        // Constructor
        Vegetable(std::string name = "None", int price = 0, int quantity = 0) : Grocery_Item(name, price, quantity) {}
        // Copy constructor
        Vegetable(const Vegetable &copyVegetable) : Grocery_Item(copyVegetable){
            std::cout << "Copy constructor called" << std::endl;
        }
        // Copy assignment operator
        Vegetable& operator=(const Vegetable &copyVegetable){
            std::cout << "Copy Assignment operator called" << std::endl;
            Grocery_Item::operator=(copyVegetable);
            return *this;
        }
};

int Total_sum(Grocery_Item *GroceryList[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
       if (GroceryList[i] != nullptr){
            total += GroceryList[i]->sub_total();
       }
    }
    return total;
}

int main(){
    Grocery_Item *GroceryList[4];
    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    for (int i = 0; i < 4; i++){    
        GroceryList[i]->print_details();
        std::cout << "Subtotal: " << GroceryList[i]->sub_total() << std::endl;
    }

    int total = Total_sum(GroceryList, 4);
    std::cout << "Total: " << total << std::endl;

    delete GroceryList[3];
    GroceryList[3] = nullptr;
    std::cout << "Lettuce has been deleted." << std::endl;

    return 0;
}