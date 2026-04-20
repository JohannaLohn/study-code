

#include <iostream>
#include <string>

class BankAccount
{
    private:
        std::string owner;
        double balance;
    
    public:
        void setOwner(std::string newOwner);
        std::string getOwner();
        void deposit(double amount);
        void withdraw(double amount);
        double getBalance();
        void getAccountInfo();

};
