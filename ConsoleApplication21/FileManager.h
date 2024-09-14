#pragma once
#include "DataSourceInterface.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Parser.h"

class FileManager :
    public DataSourceInterface
{
    fstream file;
    string info_line;
    vector<string> client_data_base_info;
    vector<string> employee_data_base_info;
    vector<string> admin_data_base_info;



public:

    void addAdmin(Admin& a)  {
        file.open("admin.txt", ios::app);
        file << a.get_id() << "|" << a.get_name() << "|" << a.get_password() << "|" << a.get_salary();
        file.close();
    }

    void addClient(Client& c) {
        file.open("client.txt", ios::app);
        file << c.get_id() << "|" << c.get_name() << "|" << c.get_password() << "|" << c.get_balance();
        file.close();
    }

    void addEmployee(Employee& e) {
        file.open("employee.txt", ios::app);
        file << e.get_id() << "|" << e.get_name() << "|" << e.get_password() << "|" << e.get_salary();
        file.close();
    }

    vector<string> getAllClients() {
        file.open("client.txt");

        while (getline(file, info_line)) {

            client_data_base_info.push_back(info_line);
        }

        return client_data_base_info;
    }

    vector<string> getAllEmployees() {
        file.open("employee.txt");

        while (getline(file, info_line)) {

            employee_data_base_info.push_back(info_line);
        }

        return employee_data_base_info;
    }

    vector<string> getAllAdmins() {
        file.open("employee.txt");

        while (getline(file, info_line)) {

            admin_data_base_info.push_back(info_line);
        }

        return admin_data_base_info;
    }


    void removeAllClients() {

        ofstream file("client.txt", ios::trunc);
        file.close();
    }


    void removeAllEmployees() {
        ofstream file("employee.txt", ios::trunc);
        file.close();
    }


    void removeAllAdmins() {
        ofstream file("admin.txt", ios::trunc);
        file.close();
    }

};

