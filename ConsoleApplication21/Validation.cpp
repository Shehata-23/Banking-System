#include "Validation.h"
#include <vector>
#include <string>

//  user name validation 
 bool Validation::isUserName(string name) {
    if (5 <= name.size() && name.size() <= 20) {
        for (int i = 0; i < name.size(); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') {

                PrintMessage::invalid_name();

                return false;
            }
        }
        return true;
    }

    PrintMessage::invalid_name();
    return false;

}

// password validation

 bool Validation::isPassWord(string password) {
    int countSpecialChar{};
    if (password.size() >= 8 && password.size() <= 20) {
        for (int i = 0; i < password.size(); i++) {
            if ((password[i] >= 'A' && password[i] <= 'Z')
                || (password[i] >= 'a' && password[i] <= 'z')
                || (password[i] >= 0 && password[i] <= 9)
                || (password[i] == '@' || password[i] == '_' || password[i] == '&' || password[i] == '$' || password[i] == '#')) {
                countSpecialChar++;
            }
        }
    }
    return countSpecialChar >= 4;


}

// balance validation

 bool Validation::isBalance(double balance) {
    if (balance >= 1500) {
        return true;
    }

    PrintMessage::start_account();
    return false;
}

//sallary validation
 bool Validation::is_salary(double salary) {
    return (salary >= 5000);
}

// withdraw validation
 bool Validation::canWithdraw(double withdraw, double balance) {
    if (balance >= withdraw && withdraw > 0) {
        return true;
    }
    PrintMessage::invalid_operation();
    return false;
}


// deposite validation 
 bool Validation::canDeposit(double deposit) {

    if (deposit > 0) {
        return true;
    }
    return false;
}

 bool Validation::isUserValidation(string choice) {

     return (choice == "1" || choice == "2" || choice == "3");

 }


  bool  Validation::userChoiceValidation(int choice) {
     return (choice == 1 || choice == 2 || choice == 3 ||
         choice == 4 || choice == 5 || choice == 6);
 }

  bool  Validation::AdminChoiceValidation(int choice) {
      return (choice == 1 || choice == 2 || choice == 3 ||
          choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9);
  }
