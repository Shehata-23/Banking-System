#include "Person.h"
// send the name to isUsername function to check it 


void Person::set_name(string name) {

        if (Validation::isUserName(name)) {
            this->name = name;
        }
        else {


            }

        

}

// send the password to ispassword function to check it 


void Person::set_password(string password) {
    for (int attempts = 1; attempts <= 3; attempts++) {

        if (Validation::isPassWord(password)) {
            this->password = password;
            break;
        }
        else {
            if (attempts == 3) {
                PrintMessage::maximum_attempts();
                break;
            }
            PrintMessage::invalid_password();
            cin >> password; // Allow the user to retry entering the password
        }
    }


}

// getters

string Person::get_name() {
    return name;
}

string Person::get_password() {
    return password;
}

int Person::get_id() {
    return id;
}