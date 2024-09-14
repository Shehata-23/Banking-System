#include "Client.h"
#include "FilesHelper.h"
#include "Parser.h"

void Client::doSomething(){
    cout << "Employee doing something." << endl;
}
Client::Client(string name, string password, double balance) {
    
    if (password.substr(0, 3) == "OTP") {
        this->password = password;
    }
    else
    {
        Client::set_password(password);

    }

    // sending the  attributes to inherited setter in person class
    Client::set_name(name);

    // not inherited 
    Client::set_balance(balance);

    id = FilesHelper::GetLast("Clientlastid.txt") + 2;


}



Client::Client(int id, string name, string password, double balance) {


    // sending the  attributes to inherited setter in person class
    this->name = name;
    this->id = id;
    this->password = password;
    this-> balance = balance;

}

// balance seeter send the attribute to the utility class to check its validation 

void Client::set_balance(double balance) {

    if (Validation::isBalance(balance)) {
        this->balance = balance;
    }
    else {
    }
}

// getters

double Client::get_balance() {
    return balance;
}
void Client::checkBalance() {
    cout << balance << endl;
}

// withdraw sends the attribute for validation 
void Client::withdraw(double withdraw) {
    if (Validation::canWithdraw(withdraw, balance)) {
        balance -= withdraw;
    }
}

// deposite sends the attribute for validation 

void Client::deposit(double deposit) {
    if (Validation::canDeposit(deposit)) {
        balance += deposit;
    }
}

// transfer sends the attribute fo validation 


void Client::transfer_to(double amount, Client& recipient) {
    if (Validation::canWithdraw(amount, balance)) {
        recipient.deposit(amount);
        this->withdraw(amount);
    }
    Client::checkBalance();
}

double Client::convertToUSD(double amount, double exchangeRate) {
    return amount *= exchangeRate;
}

void Client::convertToUSD(string currency, double amount) {

    if (currency == "EGP" || currency == "egp") {
        exchangeRate = 0.021106315;
    }
    else if (currency == "EUR" || currency == "eur") {
        exchangeRate = 1.0834677;
    }
    else if (currency == "GBP" || currency == "gbp") {
        exchangeRate = 1.2634833;
    }
    else if (currency == "JPY" || currency == "jgy") {
        exchangeRate = 0.0065981324;
    }
    else {
        PrintMessage::invalid_Currency();

    }

    balance = balance * exchangeRate;
}

void Client::display_info() {
    cout << "Name: " << name << endl
        << "password: " << password << endl
        << "id: " << id << endl
        << "balance" << balance << endl;
}


void Admin::listEmployee() {
    FilesHelper::getEmployees();
}