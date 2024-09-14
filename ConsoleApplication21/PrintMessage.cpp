#include "PrintMessage.h"


 void PrintMessage::invalid_operation() {
    cout << "Invalid operation" << endl;
}

 void PrintMessage::invalidPassOrID() {
     cout << "Invalid Password or ID, try again" << endl;
 }

 void PrintMessage::invalid_Balance() {
     cout << "Invalid operation" << endl;
 }

 void PrintMessage::sucsessful_operation() {
    cout << "SUCCESSFUL OPERATION" << endl;
}

 void PrintMessage::invalid_name() {
    cout << "Invalid name. Please try again." << endl;
}

 void PrintMessage::invalid_Currency() {

    cout << "Invalid Currency!" << endl;
}


 void PrintMessage::invalid_password() {
   cout << "Invalid password. Please try again." << endl;
}

 void PrintMessage::invalid_balance() {
    cout << "Invalid input.Please enter a valid balance amount." << endl;
}

 void PrintMessage::maximum_attempts() {
   cout << "Maximum attempts reached." << endl;
}

// starting a new account (creating new clints)
 void PrintMessage::start_account() {
   cout << "Invalid operation, The minimum balance to start an account is 1500." << endl;
}

 void PrintMessage::salary_error() {
   cout << "Not accepted, Minimum salary is 5000." << endl;
}

 void PrintMessage::invalid_choice() {
     cout << "Invalid Choice" << endl;
 }

 void PrintMessage::choice_message() {
     cout << "Please choose: " << endl <<
         "1- Client" << endl <<
         "2- Employee" << endl <<
         "3- Admin" << endl;

 }

 void PrintMessage::wrong_choice() {
     cout << "Wrong Choice" << endl;
 }

 void PrintMessage::enter_id() {
     cout << "Enter the ID: ";
 }

 void PrintMessage::Wrong_id() {
     cout << "Invalid ID" << endl;
 }

 void PrintMessage::Corrupted_data() {
     cout << "Corrupted data!" << endl;

 }

 void PrintMessage::EnterClientName() {
     cout << "Enter Client's Name: ";
  }
 void PrintMessage::EnterClientPass() {
     cout << "Enter Client's Pass: ";
  }

 void PrintMessage::EnterEmployeePass() {
     cout << "Enter your Password: ";
 }
 void PrintMessage::EnterClientBalance() {
     cout << "Enter Client's Balance: ";
  }
 void PrintMessage::EnterClientID() {
     cout << "Enter Client's ID: ";
 }

 void PrintMessage::EnterEmployeeName() {
     cout << "Enter Employee's Name: ";
 }
 
 void PrintMessage::EnterEmployeeID() {
     cout << "Enter Employee's ID: ";
 }
    
 void PrintMessage::EnterEmployeeSalary() {
     cout << "Enter Employee's Salary: ";
 }

 void PrintMessage::login_options() {
     cout << "Please select an option to login." << endl << "1. Client" << endl << "2. Employee" << endl << "3. Admin" << endl;

 }

 void PrintMessage::printClientMenu() {
     cout << "Menu:\n"
         << "1. Withdraw\n"
         << "2. Transfer\n"
         << "3. Deposit\n"
         << "4. Change Password\n"
         << "5. Check Balance\n"
         << "6. Logout\n";
 }

 void PrintMessage::EnterWithdrawAmount() {
     cout << "Please enter am amount to withdraw";
 }


 void PrintMessage::EnterTransferAmount() {
     cout << "Please enter an amount to transfer: ";
 }

 void PrintMessage::EnterDepositeAmount() {
     cout << "Please enter an amount to deposite: ";
 }


 void PrintMessage::enterNewPassword() {
     cout << "Enter new Password: ";
 }

 void PrintMessage::paasswordUpdated() {
     cout << "Password Updated Successfully";
  }


 void PrintMessage::askingForAnotherOperation() {
     cout << "Press ( 1 ) for operations menu\n" << "Press anything to logout: " << endl;
 }

 void PrintMessage::printEmployeeMenu() {
     cout << "Menu:\n"
         << "1. Add new Client\n"
         << "2. List all Clients\n"
         << "3. Search for a Client\n"
         << "4. Edit Client\n"
         << "5. Check Salary\n"
         << "6. Logout\n";
 }

 void PrintMessage::printAdminMenu() {
     cout << "Operations:\n"
         << "1. Add New Client\n"
         << "2. List All Clients\n"
         << "3. Search Clients\n"
         << "4. Edit Client\n"
         << "5. Check Salary\n"
         << "6. List All Employees\n"
         << "7. Edit Employee\n"
         << "8. Add Employee\n"  
         << "9. Exit\n";
 }

 void PrintMessage::OTPMessage() {
     cout << "Please Enter a new Password instead of the temporary OTP" << endl;
 }

