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




class EmployeeManager
{
	static vector <string> info_segments;
	static vector <string> info_of_found_client;

	static int loggedEmployeeSteps;

public:

	static Employee EmployeeLogin() {

		Parser::create_info_vector("2");

		info_segments = Parser::get_info_segments();

		PrintMessage::EnterEmployeePass();

		string Employeepassword;

		cin >> Employeepassword;

		if (info_segments.size() > 0) {
			
			if (info_segments[2] == Employeepassword) {

				Employee loggedEmployee = Employee::Employee(stoi(info_segments[0]), info_segments[1], info_segments[2], stod(info_segments[3]));

				if (Employeepassword.substr(0, 3) == "OTP") {

					PrintMessage::OTPMessage();

					string newPass;

					cin >> newPass;

					loggedEmployee.set_password(newPass);

					newPass = loggedEmployee.get_password();

					info_segments[2] = newPass;

					Employee::update_client_data_base(2, info_segments);

					FilesHelper::saveEveryOperation(1, "Employee", "Password Changed", info_segments[0]);


				}

				loggedEmployeeSteps = Parser::return_steps();

				printEmployeeOperations();

				return loggedEmployee;

			}
			else {

				PrintMessage::invalidPassOrID();

				EmployeeLogin();
			}
		}

		PrintMessage::invalidPassOrID();

		EmployeeLogin();
	}

	static Employee getLoggedClient() {
		Employee loggedClient = Employee::Employee(stoi(info_segments[0]), info_segments[1], info_segments[2], stod(info_segments[3]));
		return loggedClient;
	}

	static void printEmployeeOperations() {
		PrintMessage::printEmployeeMenu();
		employeeChoice();
	}

	static void employeeChoice() {
		while (true) {
			int employeeChoice;
			cin >> employeeChoice;

			if (Validation::userChoiceValidation(employeeChoice)) {
				switch (employeeChoice) {
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
					exit(0);
				default:
					PrintMessage::invalid_choice();
					break;
				}
			}
			else {
				PrintMessage::invalid_choice();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				printEmployeeOperations(); 
			}
		}
	}

	static pair <bool, Client> addNewClient(int saveTheOperation = 1) {

		pair<bool, Client> addResult = Employee::add_client();

		bool isAdded = addResult.first;

		if (isAdded == true) {

			if (saveTheOperation == 1 ) {
				FilesHelper::saveEveryOperation(5, "Employee", "Client Added", info_segments[0], 0, to_string(addResult.second.get_id()));
				doingAnotherOperation();
			}

			return make_pair(true, addResult.second);
		}
		else {
			PrintMessage::invalid_operation();
			addNewClient(); 

			return make_pair(true, addResult.second);
		}
	}



	static void listAllClients() {
		FilesHelper::getClients();

		doingAnotherOperation();


	}


	static vector<string> searchClients(int saveTheOperation = 1) {
		info_of_found_client = Employee::searchClient();

		if (info_of_found_client.size() > 0) {

		return info_of_found_client;
		}
		else
		{
			PrintMessage::Wrong_id();

			if (saveTheOperation == 1) {

				doingAnotherOperation();

			}

		}
	}

	static vector<string> get_found_client() {
		return info_of_found_client;

	}

	static pair<bool, pair<double, std::vector<string>>> editClient(int saveTheOperation = 1) {

		vector<string> information_to_edit = searchClients();
		
		string name;
		PrintMessage::EnterClientName();
		cin >> name;

		double balance;

		PrintMessage::EnterClientBalance();
		cin >> balance;

		if (Validation::isUserName(name)) {

			information_to_edit[1] = name;
			information_to_edit[3] = to_string(balance);

			Employee::update_client_data_base(1, information_to_edit);

			PrintMessage::sucsessful_operation();


			if (saveTheOperation == 1) {

				FilesHelper::saveEveryOperation(6, "Employee", "Client Edited", info_segments[0], balance, information_to_edit[0]);

				doingAnotherOperation();
			}
			
			return make_pair(true, make_pair(balance, information_to_edit));

		}
		else
		{
			PrintMessage::invalid_name();

			if (saveTheOperation == 1) {
				doingAnotherOperation();

			}
			return make_pair(false, make_pair(balance, information_to_edit));
		}
	}

	static void checkSalary() {
		cout << getLoggedClient().get_salary();
		doingAnotherOperation();

	}


	static void doingAnotherOperation() {
		PrintMessage::askingForAnotherOperation();
		int answer;
		cin >> answer;

		if (answer == 1) {
			printEmployeeOperations();
		}
		else
		{
			
			exit(0);
		}

	}


};

