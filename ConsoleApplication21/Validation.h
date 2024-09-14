#pragma once
#include "PrintMessage.h"
#include <vector>

class Validation {
public:
    static bool isUserName(string name);
    static bool isPassWord(string password);
    static bool isBalance(double balance);
    static bool is_salary(double salary);
    static bool canWithdraw(double withdraw, double balance);
    static bool canDeposit(double deposit);
    static bool isUserValidation(string choice);
    static bool userChoiceValidation(int choice);
    static bool AdminChoiceValidation(int choice);



};
