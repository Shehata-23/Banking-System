#pragma once
#include"Person.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Admin.h"
#include "Client.h"
#include "Parser.h"
#include"PrintMessage.h"
#include "Employee.h"
#include <vadefs.h>
#include "TimeMangment.h"
using namespace std;

class FilesHelper
{

private:

	// to write id and Saves the last id to file will be invoked in save clients info method 

	static void SaveLastId(string fileName, int lastId) {
		ofstream file(fileName, ios::out);
		if (file.is_open()) {
			file << lastId;
			file.close();
		}
		
	}
public:
	//  to get the last id from a file.
	static int GetLast(string fileName) {
		int lastId = 0;
		fstream file;
		file.open(fileName);
		file >> lastId; // get the last id from the files clientlastid.txt / employeelastid.txt / adminlastid.txt
		return lastId;
	}
	// Save info clients

	static void SaveClientInfo(Client c) { // will get invoked with each constructor 

		int lastId = GetLast("Clientlastid.txt"); // get last id 
		fstream file("Client.txt", ios::app); // open file in appending mode 
		if (file.is_open()) {
			int newId = lastId + 1; // create new unique id odd numbers 
			if (newId % 2 == 0) {
				newId++;
			}

			//writing in the file client.txt
			file << newId << "|" << c.get_name() << "|" << c.get_password() << "|" << c.get_balance() <<  endl; 
			file.close();

			SaveLastId("Clientlastid.txt", newId); // invoke save last id 
		}
		
	}
	// Save info Employee, it takes the file name as it works with employees and admins 

	static void SaveEmployeeInfo(string fileName, string LastIdFile, Employee e) {
		int lastId = GetLast(LastIdFile);
		fstream file(fileName, ios::app);
		if (file.is_open()) {
			int newId = lastId + 1;
			if (newId % 2 != 0) {
				newId++;
			}

			//writing in the file admin.txt or employee.txt

			file << newId << "|" <<  e.get_name() << "|" << e.get_password() << "|" << e.get_salary()  << endl;
			file.close();


			SaveLastId(LastIdFile, newId); //invoke save last id
		}
		
	}
	// get the  info for client


	static void getClients() { // all you gotta do to invoke it in the int main and all the magic happens automatically 
								// it will opens the client.txt file and get each line and send it to parser method
								// parser will sace each line in a vector called segments and return that vector 
		fstream file;
		string info_line;
		file.open("client.txt");

		while (getline(file, info_line)) {
			Parser::parse_info(info_line);


		}

		// after getting each line and cutting it with parser then display_data_base method will be invoked 
		// it takse 1 attribute which is the vector calles segments that was created by parser method AND 
		// it take attrirbutes bulit in which is ( 1 ) that will play a role in that method below.....

		display_data_base(Parser::get_info_segments(), 1);

	}


	// same as get clients 

	static void getEmployees() {
		fstream file;
		string info_line;
		file.open("employee.txt");

		while (getline(file, info_line)) {
			Parser::parse_info(info_line);

			
		}

		// after getting each line and cutting it with parser then display_data_base method will be invoked 
		// it takse 1 attribute which is the vector calles segments that was created by parser method AND 
		// it take attrirbutes bulit in which is ( 2 ) that will play a role in that method below.....

		display_data_base(Parser::get_info_segments(), 2);
	}

	// same as get clients and employees 

	static void getadmins() {
		fstream file;
		string info_line;
		file.open("admin.txt");

		while (getline(file, info_line)) {
			Parser::parse_info(info_line);

		// after getting each line and cutting it with parser then display_data_base method will be invoked 
		// it takse 1 attribute which is the vector calles segments that was created by parser method AND 
		// it take attrirbutes bulit in which is ( 2 ) that will play a role in that method below.....

			display_data_base(Parser::get_info_segments(), 2);
		}

	}

	// display method it recieves vector containe information that was seperated by parcer method 
	// each client/employee/admin has a set of 4 informmation 
	// example: client-1 has info from index 0 to index 3 (4 information) so client-2 has info from index 4 to index 7
	// each 4 iteration we display a new object information whether it is client, emplouee pr admin 

	static void display_data_base(vector<string> clients, int choice) {
															// choice will control the printing operation 

		if (choice == 1) { // this choice when it is 1 the printing will say (Balance) as it for clients 

			cout << "ID\t\tName\t\t\t\tBalance" << endl;
			cout << "---------------------------------------------------------------" << endl;

			for (int i = 0; i < clients.size(); i += 4) {
				string id = clients[i];
				string name = clients[i + 1];
				string balance = clients[i + 3];

				// Calculate the spacing based on the length of the name
				int spacing = 16 - name.length();  // Adjust the number (16) based on your layout needs

				cout << id << "\t\t" << name;
				for (int j = 0; j < spacing; j++) {
					cout << " ";  // Add spaces for alignment
				}
				cout <<'\t' << '\t' << balance << "\t\t" << endl;
			}
		}
		else if (choice == 2) { // this choice when it is 1 the printing will say (salary) as it for employees and admins

			cout << "ID\t\tName\t\t\t\tBalance" << endl;
			cout << "---------------------------------------------------------------" << endl;

			for (int i = 0; i < clients.size(); i += 4) {
				string id = clients[i];
				string name = clients[i + 1];
				string salary = clients[i + 3];

				// Calculate the spacing based on the length of the name
				int spacing = 16 - name.length();  // Adjust the number (16) based on your layout needs

				cout << id << "\t\t" << name;
				for (int j = 0; j < spacing; j++) {
					cout << " ";  // Add spaces for alignment
				}
				cout << '\t' << '\t' << salary << "\t\t" << endl;
			}
		}

	}

	
	// simply clears each file..

	static void clearFile(string fileName, string lastIdFile) {
		ofstream file(fileName, ios::trunc);
		file.close();


		file.open(lastIdFile, ios::trunc);
		file.close();


	}

	

	static void update_client_data_base(int choice , int loggedClientSteps, Client loggedClient) {

		string lines; // new declaration of a string 

		vector<string> clients_data; // new declaration of a vector string

		string file;

		switch (choice)
		{
		case 1:
			file = "client.txt";
			break;
		case 2:
			file = "employee.txt";
			break;
		case 3:
			file = "admin.txt";
			break;
		default:
			break;
		}

		// at first i save the whole file before the edit in a vector...

		ifstream inputFile(file);

		while (getline(inputFile, lines)) {
			clients_data.push_back(lines);
		}
		inputFile.close(); // here saving operation is done....


		// here i delete the client.txt file ( i still have the info in vector above so we are okay we still have the data)

		ofstream outFile(file, ios::trunc);
		outFile.close(); // now file is clear


		// now we open client.txt to append info lines that we have again but with one change...


		ofstream outputFile(file, ios::app);

		for (int i = 0; i < clients_data.size(); i++) { // loop foe appending data inside the file 

			if (i == loggedClientSteps) { // this conditions will make sure if we reached the line we want to edit 
				// will add the edited info 
				outputFile << loggedClient.get_id() << "|" << loggedClient.get_name() << "|" << loggedClient.get_password() << "|" << loggedClient.get_balance() << endl;
			}
			else { // else it appends the stored info we save before deleting it....
				outputFile << clients_data[i] << endl;
			}
		}

		outputFile.close(); // now we saved our data + we edited the info line // close the file // 

	}






	static void saveEveryOperation(int choice, string authoritiy, string operation, string id, double amount = 0, string transferTo = "") {


		if (choice == 1) {
			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;
		}
		else if (choice == 2){
			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "Amount Withdrawed: " << amount <<"|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;
		}
		else if (choice == 3)
		{
			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "Amount Transferred: " << amount <<"|" << "Transferred to: " << transferTo << "|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;
		}
		else if (choice == 4){

			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "Client Deposited: " << amount <<"|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;

		}
		else if (choice == 5) {

			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "New  Client ID: " << transferTo << "|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;

		}
		else if (choice == 6) {

			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "Client Edited ID: " << transferTo << "|" <<"Balance after Edit:" << amount << "|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;

		}

		else if (choice == 7) {

			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "New  Employee ID: " << transferTo << "|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;

		}
		else if (choice == 8) {

			ofstream outputFile("operations.txt", ios::app);

			outputFile << "Operation: " << operation << "|" << "Done by: " << authoritiy << "|" << "ID: " << id << "|" << "Employee Edited ID: " << transferTo <<"|" << "Time-Stamp: " << TimeMangment::getCurrentDateTime() << endl;

		}


	}


	static void deleteLastLine(string filename) {
		ifstream inputFile(filename);
		if (!inputFile.is_open()) {
			return;
		}

		vector<string> lines;
		string line;

		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}

		inputFile.close();

		if (!lines.empty()) {
			lines.pop_back(); // Remove the last line
		}

		ofstream outputFile(filename);
		if (!outputFile.is_open()) {
			return;
		}

		for (const string& l : lines) {
			outputFile << l << std::endl;
		}

		outputFile.close();
	}


};