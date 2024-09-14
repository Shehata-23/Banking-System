#pragma once
#include <iostream>
using namespace std;
class PrintMessage
{
public:
        virtual void doSomething() = 0;
        static void invalid_operation();
        static void sucsessful_operation();
        static void invalid_name();
        static void invalid_password();
        static void invalid_balance();
        static void maximum_attempts();
        static void start_account();
        static void salary_error();
        static void invalid_Currency();
        static void invalid_choice();
        static void choice_message();
        static void wrong_choice();
        static void enter_id();
        static void Wrong_id();
        static void Corrupted_data();
        static void EnterClientID();
        static void EnterClientName();
        static void EnterClientPass();
        static void EnterClientBalance();

        static void EnterEmployeeID();
        static void EnterEmployeeName();
        static void EnterEmployeePass();

        static void EnterEmployeeSalary();

        static void login_options();
        static void printClientMenu();

        static void EnterWithdrawAmount();
        static void EnterTransferAmount();

        static void EnterDepositeAmount();

        static void enterNewPassword();

        static void paasswordUpdated();

        static void askingForAnotherOperation();


        static void printEmployeeMenu();

        static void OTPMessage();

        static void invalid_Balance();

        static void printAdminMenu();

        static void invalidPassOrID();




};

