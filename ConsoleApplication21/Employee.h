#pragma once
#include "Person.h"
#include "Client.h"
class Employee :public Person {
protected:
    void doSomething() override;
    double salary;
public:

    Employee(string name, string password, double salary);


    Employee(int id, string name, string password, double salary);

    void set_salary(double salary);
    double get_salary();
    void display_info();
    static pair<bool, Client> add_client();
    static vector<string> searchClient();
    void listClient();
    void editClient();
    static void update_client_data_base(int choice, vector<string> edited_client);
};

