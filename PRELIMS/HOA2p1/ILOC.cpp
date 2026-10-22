#include <iostream>

// Problem 1
class GroceryList{
    private:
        std::string name;
        int price;
        int quantity;
    
    public:
        // Constructor
        GroceryList(std::string productName, int productPrice, int productQuantity){
            name = productName;
            price = productPrice;
            quantity = productQuantity; 
        };

        // Deconstructor
        virtual ~GroceryList(){
            std::cout << "Destructor Was Called" << std::endl;
        };

        // Copy Constructor
        GroceryList(const GroceryList &other){
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        };

        // Copy Assignment Operator
        GroceryList& operator = (const GroceryList& other){
            if (this!= &other){
                name = other.name;
                price = other.price;
                quantity = other.quantity;
        }
        return *this;
    }

        int calculateSum(){
            return price*quantity;  
        }

        void display(){
            std::cout << name << "\tPHP " << price << "\tx" << quantity << std::endl;
        }
};

class Fruit:public GroceryList{
    public:
    // Constructor
    Fruit(std::string productName, int productPrice, int productQuantity)
        : GroceryList(productName, productPrice, productQuantity){}
    
    // Destructor
    ~Fruit() override{
        std::cout << "Fruit Destroyed, ";
    }

    // Copy Constructor
    Fruit(const Fruit& other)
        : GroceryList(other){}

    // Copy Assignment Operator
    Fruit& operator = (const Fruit& other){
        GroceryList::operator = (other);
        return *this;
    }
};

class Vegetable:public GroceryList{
    public:
    // Constructor
    Vegetable(std::string productName, int productPrice, int productQuantity)
        : GroceryList(productName, productPrice, productQuantity){}
    
    // Destructor
    ~Vegetable() override{
        std::cout << "Vegetable Destroyed, ";
    }

    // Copy Constructor
    Vegetable(const Vegetable& other)
        : GroceryList(other){}

    // Copy Assignment Operator
    Vegetable& operator = (const Vegetable& other){
        GroceryList::operator = (other);
        return *this;
    }
};


//Problem 3
int totalSum(GroceryList* list[], int size);



int main(){
    // Problem 2
    GroceryList* groceryList[4];

    groceryList[0] = new Fruit("Apple", 10 ,7);
    groceryList[1] = new Fruit("Banana", 10, 8);
    groceryList[2] = new Vegetable("Broccoli", 60, 12);
    groceryList[3] = new Vegetable("Lettce", 50, 10);

    // Output Complete List
    std::cout << "Grocery List:" << std::endl;
    for (int i=0; i<4; i++){
        groceryList[i] -> display();
    }

    std::cout << "Total: PHP " << totalSum(groceryList, 4) << std::endl << std::endl;

    // Problem 4
    delete groceryList[3];
    groceryList[3] = nullptr;
    std::cout << "\n";

    // Output with lettuce deleted
    std::cout << "Grocery List:" << std::endl;
    for (int i=0; i<3; i++){
        groceryList[i] -> display();
    }
    
    std::cout << "Total: PHP " << totalSum(groceryList, 3) << std::endl << std::endl;

    std::cout << "\n";
    
    for (int i=0; i<4; i++){
        delete groceryList[i];
        std::cout << "\n";
    }

    return 0;
}


// Problem 3
int totalSum(GroceryList* list[], int size){
    int total = 0;

    for(int i=0; i<size; i++){
        total += list[i] -> calculateSum();
    }
    return total;
}