#include <iostream>
#include <string>
#include "Admin.h"
#include "Client.h"
#include "Parser.h"
#include "FilesHelper.h"
#include "Employee.h"
#include "Screens.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
using namespace std;

string Parser::employee_file = "employee.txt";
string Parser::admin_file = "admin.txt";
string Parser::client_file = "client.txt";
string Parser::ID;
string Parser::user_choice;
string Parser::info_line;
string Parser::segment;
vector<string> Parser::info_vector;
vector<string> Parser::segments;
fstream Parser::file;
int Parser::steps{};
vector <string> ClientManger::info_segments;
int ClientManger::loggedClientSteps;
vector <string> EmployeeManager::info_of_found_client;
vector <string>  EmployeeManager::info_segments;
int EmployeeManager::loggedEmployeeSteps;
vector<string> AdminManager::info_segments;
 int AdminManager::loggedAdminSteps;
 vector <string> AdminManager::info_of_found_client;







int main() {

    
    /*Employee shehata("Shehata", "asw@36261AAAa", 85046);

    cout << shehata.get_id();*/


    Screens::runApp();
    

}