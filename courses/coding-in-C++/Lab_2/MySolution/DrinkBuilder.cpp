#include <iostream>
#include <string>

class drinkBuilder
{    
    private:
        std::string name 
        int sugar
        int temperature
        bool withMilk

    public:
        drinkBuilder& setName (std::str name){
            this->name = namespace name;
            return this*         
        }
        drinkBuilder& setSugar (int sugar){
            this->sugar = sugar;
            return this*
        }
        drinkBuilder& setTemperature (int temperature){
            this->temperature = temperature;
            return this*
        }
        drinkBuilder& setWithmilk (bool withMilk){
            this->withMilk = withMilk;
            return this*
        }
}

int main(){
    
    drinkBuilder builder;

    builder.setName("Tea")
    .setSugar(2)
    .setTemperature(65)
    .setWithMilk(true)
    .print();

    retrun (0);

}