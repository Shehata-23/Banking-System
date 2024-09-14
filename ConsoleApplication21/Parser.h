#pragma once
using namespace std;
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <string>
#include <sstream>
#include <string>

class Parser
{
private:

	static string employee_file;
	static string admin_file;
	static string client_file;
	static string ID;
	static string user_choice;
	static string info_line;
	static string segment;
	static vector<string> info_vector;
	static vector<string> segments;
	static fstream file;
	static int steps;

public:

	// as log in message 

	static void get_user_choice() {
		PrintMessage::choice_message();
		cin >> user_choice; // users enters his choice 

		if (Validation::isUserValidation(user_choice)) {

			create_info_vector(user_choice); // this onvoke create info vector based on user choice 
		}
		else {
			PrintMessage::wrong_choice();
			get_user_choice();
			return;
		}

	}

	// takes information from files and append it in a vector called ( info_vector ) based on user choice from the above

	// ( will be invoked in search methods in employees and admins)

	static void create_info_vector(string user_choice) {

		info_vector.clear(); // to make sure it is empty each time 

		if (user_choice == "1") {
			file.open("client.txt"); // if user choice was 1 it will append clients info 
		}
		else if (user_choice == "2") {
			file.open("employee.txt"); // if user choice was 2 it will append employee info 
			file.seekg(0, ios::beg);
		}
		else if (user_choice == "3") { // if user choice was 3 it will append admins info 
			file.open("admin.txt");
			file.seekg(0, ios::beg);
		}

		while (getline(file, info_line)) 
		{
			// in this loop the opened file is pushed line by line in the vector called info_vector

			info_vector.push_back(info_line);
		}

		file.close(); // close the file 


		get_id_to_be_searched(); // invoke a method that asks for the ID to be searched or edited 

	
	}

	// ask the user to put an ID to be searched

	static void get_id_to_be_searched() {
		PrintMessage::enter_id();
		cin >> ID;
		steps = 0;
		search_info_vector(ID);

	}


	// steps here related to method below called search_info_vector, it increments till the the method find the line 

	static int return_steps() {
		return steps;
	}


	// at this method we search each element at the vector called info_vector which holds data from files


	static bool search_info_vector(string ID) {
		
		for (int i = 0; i < info_vector.size(); i++, steps++) { // for loop to traverse over information lines 

			segments.clear();  // we clear the vector after each iteration the maintain index 0 holding the ID 

			Parser::parse_info(info_vector[i]); // send each info line in info vector that hold files-
												//informations to parser method  
			

			if (ID == segments[0]) { // parser method takes each line and cut it to 4 pieces 
									// each pieces represents id name password salary or balance 
									// the  index [0] always hold the Id so we will check if
									// the ID the user entered equals the id in each line ( segments[0] ).....
				return true;
			}
			

		}

		segments.clear(); // if it is false (didn't found) we clear the segments vector again to be ready for next usage 
		steps = 0;
		info_vector.clear();
		return false;
	
	}

	static vector<string> parse_info(string info_line) { // this method cuts te information in each line to 4 pieces 
														// ID/name/password/balance or salary based on this sign ( | ) 

		stringstream ss(info_line); 

		while (getline(ss, info_line, '|')) {

			segments.push_back(info_line); // the parsed info are pushed into vecctor calles segments 
											// segments[0] = ID 
											// segments[1] = Name
											// segments[2] = password
											// segments[3] = salary or balance 
		}

		return segments;

		/*if (user_choice == "1") {
			parseToClient(segments);
		}*/
	}



	static vector<string> get_info_segments() { // this method return information from parser method will be used in other classes

		return segments;
	}


	// these 3 methods below  will take info from parser and create an object by it 

	static void parseToClient(vector<string> segments) {
		if (Validation::isUserName(segments[1]) && Validation::isPassWord(segments[2]) && Validation::isBalance(stod(segments[3]))) {
			Client c(segments[1], segments[2], stod(segments[3]));
			c.display_info();
		}
		else {
			PrintMessage::Corrupted_data();
		}
		
	}

	static void parseToEmployee(vector<string> segments) {
		if (Validation::isUserName(segments[1]) && Validation::isPassWord(segments[2]) && Validation::is_salary(stod(segments[3]))) {
			Employee e(segments[1], segments[2], stod(segments[3]));
		}
		else {
			PrintMessage::Corrupted_data();
		}

	}

	static void parseToAdmin(vector<string> segments) {
		if (Validation::isUserName(segments[1]) && Validation::isPassWord(segments[2]) && Validation::is_salary(stod(segments[3]))) {
			Admin a(segments[1], segments[2], stod(segments[3]));
		}
		else {
			PrintMessage::Corrupted_data();
		}

	}
};

