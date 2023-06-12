/*
    Christian Chacon | 6/10/2023

    CIS 230 01
*/

#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>


class Pizza{
private:
    std::string size;//s/m/l
    std::string type;
    std::vector <std::string> toppings;
    double price;

//private fns
    double calcPrice(){
        if(size == "Small") price = 10.00;
        if(size == "Medium") price = 14.00;
        if(size == "Large") price = 17.00;

        price += ((double)toppings.size()) * 2.00;
        return price;
    }

public:
//non-default
    Pizza(std::string size, std::string type, std::vector <std::string> toppings){
        this->size = size;
        this->type = type;
        this->toppings = toppings;
        this->price = calcPrice();
    }

//overloaded fns
    void operator<<(int x){
        std::cout<<std::fixed<<std::setprecision(2);
    }

//accessors
    std::string getSize(){return this->size;}
    std::string getType(){return this->type;}
    std::vector <std::string> getToppings(){return this->toppings;}
    double getPrice(){return this->price;}
};
// - - - - - - End Pizza Class - - - - - - 

class DeliveredPizza : public Pizza{
private:
    double deliveryFee;
    double totalPrice;
    std::string deliveryAddress;

public:
//non-default
    DeliveredPizza(std::string size, std::string type, std::vector <std::string> toppings, std::string deliveryAddress)
    :Pizza(size, type, toppings){
        this->deliveryAddress = deliveryAddress;

        if(Pizza::getPrice() > 20.00) deliveryFee = 3.50;
        else deliveryFee = 5.00;

        totalPrice = (deliveryFee + Pizza::getPrice());
    }

//overloaded fns
    void operator<<(int x){
        Pizza::operator<<(0);

        std::cout<<"You ordered a "<<Pizza::getSize()<<" "<<Pizza::getType()<<" with ";
        for(std::string oneTopping : Pizza::getToppings()){
            std::cout<<oneTopping<<" ";
        }
        std::cout<<"\n - - - - - - - - - - - - - - - - - - - "<<std::endl;
        std::cout<<"Pizza Price:   $"<<Pizza::getPrice()<<std::endl;
        std::cout<<"Delivery Fee:  $"<<deliveryFee<<std::endl;
        std::cout<<"Total Price:   $"<<totalPrice<<std::endl;

        if(deliveryAddress != "Pick Up"){
            std::cout<<" - - - - - - - - - - - - - - - - - - - "<<std::endl;
            std::cout<<"Delivered to: "<<deliveryAddress<<std::endl;            
        }
    }
};
// - - - - - - End DeliveredPizza Class - - - - - - 

void getOrder(std::string &size, std::string &type, std::vector <std::string> &toppings, std::string toppingSelections[]);

int main(){
    std::string toppingSelections[6] = {"Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"};
    //- - -
    int selectLocation;
    std::string size, type, deliveryAddress;
    std::vector <std::string> toppings;

    getOrder(size, type, toppings, toppingSelections);

    std::cout<<"Would you like 1 - pick up or 2 - delivery? "; std::cin>>selectLocation;

    while(std::cin.fail() || (selectLocation < 1 || selectLocation > 2)){
            std::cout<<"\n  Invalid.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"Would you like 1 - pick up or 2 - delivery? "; std::cin>>selectLocation;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(selectLocation == 2){
        std::cout<<"Please enter your address:\n\t"; getline(std::cin, deliveryAddress);
    }
    else{
        deliveryAddress = "Pick Up";
    }

    std::cout<<"\n - - - - - - - - - - - - - - - - - - - "<<std::endl;

    DeliveredPizza pizzaOrder(size, type, toppings, deliveryAddress);

    pizzaOrder.operator<<(0);

    return 0;
}

void getOrder(std::string &size, std::string &type, std::vector <std::string> &toppings, std::string toppingSelections[]){
    int selectSize, selectType, selectToppings;
    
    std::cout<<"What size pizza would you like to order? "<<std::endl;
    std::cout<<"  1 - Small\n  2 - Medium\n  3 - Large"<<std::endl;
        std::cout<<"-->"; std::cin>>selectSize;

        while(std::cin.fail() || (selectSize < 1 || selectSize > 3)){
            std::cout<<"\n  Invalid.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"What size pizza would you like to order? "<<std::endl;
            std::cout<<"  1 - Small\n  2 - Medium\n  3 - Large"<<std::endl;
                std::cout<<"-->"; std::cin>>selectSize;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(selectSize == 1) size = "Small";
    if(selectSize == 2) size = "Medium";
    if(selectSize == 3) size = "Large";

    std::cout<<"What type of crust would you like to order? "<<std::endl;
    std::cout<<"  1 - Classic\n  2 - Deep Dish\n  3 - Thin Crust"<<std::endl;
        std::cout<<"-->"; std::cin>>selectType;

        while(std::cin.fail() || (selectType < 1 || selectType > 3)){
            std::cout<<"\n  Invalid.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"What type of crust would you like to order? "<<std::endl;
            std::cout<<"  1 - Classic\n  2 - Deep Dish\n  3 - Thin Crust"<<std::endl;
                std::cout<<"-->"; std::cin>>selectType;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(selectType == 1) type = "Classic";
    if(selectType == 2) type = "Deep Dish";
    if(selectType == 3) type = "Thin Crust";

    while(selectToppings != 0){
        std::cout<<"Choose from the following toppings or 0 to quit"<<std::endl;
        for(int x = 0; x < 6; x++){
            std::cout<<" "<<(x+1)<<": "<<toppingSelections[x]<<std::endl;
        }
        std::cout<<"-->"; std::cin>>selectToppings;

        while(std::cin.fail() || (selectToppings < 0 || selectToppings > 6)){
            std::cout<<"\n  Invalid.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"Choose from the following toppings or 0 to quit"<<std::endl;
            for(int x = 0; x < 6; x++){
                std::cout<<" "<<(x+1)<<": "<<toppingSelections[x]<<std::endl;
            }
            std::cout<<"-->"; std::cin>>selectToppings;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(selectToppings == 0) break;

        toppings.push_back(toppingSelections[selectToppings-1]);
    }
}
