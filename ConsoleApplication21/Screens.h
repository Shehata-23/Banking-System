#pragma once
#include "Person.h"
#include <chrono> 
#include <thread> 
#include "Validation.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"



class EmployeeManager;


class Screens
{
   friend class EmployeeManager;
public:
    static void runApp() {
        cout << "Despairing Dollars Bank: Where Wealth Meets Its End" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));

        welcome();
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        loginoptions();
    }

    static void welcome() {
        cout << "Welcome to Despairing Dollars Bank!" << endl;
    }

    static void loginoptions() {
        PrintMessage::login_options();

        string user_login_choice;
        cin >> user_login_choice;

        if (Validation::isUserValidation(user_login_choice)) {
            loginAs(user_login_choice);
        }
        else {
            PrintMessage::invalid_choice();
            loginoptions(); // Consider using a loop instead of recursion
        }
    }

    static void loginAs(string user_login_choice) {
        switch (stoi(user_login_choice)) {
        case 1:
            ClientManger::clientLogin();
            break;
        case 2:
            EmployeeManager::EmployeeLogin();
            break;
        case 3:
            AdminManager::AdminLogin();
            break;
        default:
            PrintMessage::invalid_choice();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loginoptions(); // Handle invalid choices
            break;
        }
    }

    static void logout() {
        Screens::runApp();
    }





};
