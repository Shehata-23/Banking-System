#pragma once
#include "Person.h"

class Client : public Person {

    double balance{}, exchangeRate{};

    void doSomething() override;

public:
    Client(string name, string password, double balance);

    Client(int id, string name, string password, double balance);


    void set_balance(double balance);
    double get_balance();
    void checkBalance();
    void withdraw(double withdraw);
    void deposit(double deposit);
    void transfer_to(double amount, Client& recipient);
    double convertToUSD(double amount, double exchangeRate);
    void convertToUSD(string currency, double amount);
    void display_info();
};

// allocate the count in the memory to be incremented inside the constrcutor 
