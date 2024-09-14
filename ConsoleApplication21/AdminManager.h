#pragma once
#include "Client.h"
#include "PrintMessage.h"
#include "Validation.h"
#include "Parser.h"
#include <vector>
#include "FilesHelper.h"
#include <sstream>
#include <string>
#include "Employee.h"
#include "TimeMangment.h"
#include <string>
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "Admin.h"


class AdminManager
{
	static vector<string> info_segments;
	static int loggedAdminSteps;
	static vector <string> info_of_found_client;



public:
	static Employee AdminLogin() {

		Parser::create_info_vector("3");

		info_segments = Parser::get_info_segments();

		PrintMessage::EnterEmployeePass();

		string Adminpassword;

		cin >> Adminpassword;

		if (info_segments.size() > 0) {

			if (info_segments[2] == Adminpassword) {

				Admin loggedEmployee = Admin::Admin(stoi(info_segments[0]), info_segments[1], info_segments[2], stod(info_segments[3]));

				loggedAdminSteps = Parser::return_steps();

				printAdminOperations();

				return loggedEmployee;

			}
			else {


				PrintMessage::invalidPassOrID();


				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				AdminLogin();
			}
		}
		else
		{
			printAdminOperations();

		}

	}

	static Admin getLoggedAdmin() {
		Admin loggedClient = Admin::Admin(stoi(info_segments[0]), info_segments[1], info_segments[2], stod(info_segments[3]));
		return loggedClient;
	}



	static void printAdminOperations() {

		PrintMessage::printAdminMenu();

		AdminChoice();
	}

	static void AdminChoice() {
		int EmployeeChoice;

		cin >> EmployeeChoice;

		if (Validation::AdminChoiceValidation(EmployeeChoice)) {

			switch (EmployeeChoice) {
			case 1:
				addNewClient();
				break;

			case 2:
				listAllClients();
				break;

			case 3:
				searchClients();
				break;
			case 4:
				editClient();
				break;
			case 5:
				checkSalary();
				break;
			case 6:
				lisAllEmployees();
				break;
			case 7:
				editEmployee();
				break;
			case 8:
				addNewEmployee();
				break;
			case 9:
				exit(0);
				break;
			default:
				PrintMessage::invalid_choice();
				break;
			}

		}
		else
		{
			PrintMessage::invalid_choice();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printAdminOperations();
		}

		
	}
	static void addNewClient() {

		auto isNewClientAdded = EmployeeManager::addNewClient(2);

		if (isNewClientAdded.first == true) {

			
			
			FilesHelper::saveEveryOperation(5, "Admin", "Client Added", info_segments[0], 0, to_string(isNewClientAdded.second.get_id()));
			printAdminOperations();

		}
		else {

			printAdminOperations(); 
		}
	}

	static void listAllClients() {
		FilesHelper::getClients();

		printAdminOperations();


	}

	static void searchClients() {
		info_of_found_client = EmployeeManager::searchClients(2);

		if (info_of_found_client.size() < 0) {

			PrintMessage::Wrong_id();

		}

		printAdminOperations();

	}


	static void editClient() {
		 auto result = EmployeeManager::editClient(2);

		if (result.first == true) {

			FilesHelper::saveEveryOperation(6, "Employee", "Client Edited", info_segments[0], result.second.first, result.second.second[0]);

			printAdminOperations();

		}
		else
		{
			printAdminOperations();
		}

	}


	static void checkSalary(){
		cout << getLoggedAdmin().get_salary();

		printAdminOperations();

	}
	
	

	
	static void lisAllEmployees() {
		FilesHelper::getEmployees();
		printAdminOperations();

	}


	static void addNewEmployee() {

		auto isEmployeeAdded = Admin::addEmployee();


		if (isEmployeeAdded.first == true) {



			FilesHelper::saveEveryOperation(7, "Admin", "Employee Added", info_segments[0], 0, to_string(isEmployeeAdded.second.get_id()));

			printAdminOperations();


		}
		else
		{
			printAdminOperations();

		}


	}

	static void editEmployee() {

		auto isEmployeeEdited = Admin::editEmployee();



		if (isEmployeeEdited.first == true) {


			Employee::update_client_data_base(2, isEmployeeEdited.second);


			FilesHelper::saveEveryOperation(8, "Admin", "Employee Edited", info_segments[0], 0, isEmployeeEdited.second[0]);

			printAdminOperations();


		}
		else
		{
			printAdminOperations();

		}
	}


};

