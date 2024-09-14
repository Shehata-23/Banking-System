#pragma once
#include "Validation.h"
#include <string>
class Person {
protected:
    string name, password;
    int id;

    virtual void doSomething() = 0;


public:
    virtual void display_info() = 0;
    void set_name(string name);
    void set_password(string password);
    string get_name();
    string get_password();
    int get_id();
};

