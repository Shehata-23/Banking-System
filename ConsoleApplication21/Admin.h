#pragma once
#include "Employee.h"

class Admin : public Employee {


    int id;

public:
    Admin(string name, string password, double salary);

    Admin(int id, string name, string password, double salary);






    static pair<bool, Employee> addEmployee();
    static vector<string> searchEmployee();
    static pair<bool, vector<string>> editEmployee();
    static void update_Employee_data_base(vector<string> edited_Employee);
    static void listEmployee();



};


