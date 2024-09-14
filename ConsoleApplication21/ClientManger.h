#pragma once
#include "Client.h"
#include "PrintMessage.h"
#include "Validation.h"
#include "Parser.h"
#include <vector>
#include "FilesHelper.h"
#include <sstream>
#include <string>



class ClientManger
{

	static vector <string> info_segments;
	static int loggedClientSteps;

public:

	static Client clientLogin() {

		Parser::create_info_vector("1");

		info_segments = Parser::get_info_segments();

		loggedClientSteps = Parser::return_steps();

		PrintMessage::EnterClientPass();

		string clientpassword;

		cin >> clientpassword;

		if (info_segments.size() > 0) {
		

			if (info_segments[2] == clientpassword) {

				Client loggedClient = Client::Client(stoi(info_segments[0]), info_segments[1], info_segments[2], stod(info_segments[3]));

				if (clientpassword.substr(0, 3) == "OTP") {

					PrintMessage::OTPMessage();

					string newPass;

					cin >> newPass;

					loggedClient.set_password(newPass);

					FilesHelper::update_client_data_base(1, loggedClientSteps, loggedClient);

					FilesHelper::saveEveryOperation(1, "Client", "Password Changed", info_segments[0]);


				}

				printClientOperations();

				return loggedClient;

			}
			else {

				PrintMessage::invalidPassOrID();

				clientLogin();
			}
		}
		else
		{

			PrintMessage::invalidPassOrID();

			clientLogin();
		}
		

	}


	static Client getLoggedClient() {
		Client loggedClient = Client::Client(stoi(info_segments[0]), info_segments[1], info_segments[2], stod(info_segments[3]));
		return loggedClient;
	}

	static void printClientOperations() {

		PrintMessage::printClientMenu();

		clientChoice();
	}


	static void clientChoice() {
		int clientChoice;

		cin >> clientChoice;

		if (Validation::userChoiceValidation(clientChoice)) {

			switch (clientChoice) {
			case 1:
				withdraw();
				break;
			case 2:
				transfer();
				break;
			case 3:
				deposite();
				break;
			case 4:
				changePassword();
				break;
			case 5:
				checkBalance();
				break;
			case 6:
				exit(0);
				break;
			}
		}
		else
		{
			PrintMessage::invalid_choice();
			printClientOperations();
		}
	}

	static void withdraw() {

		PrintMessage::EnterWithdrawAmount();
		int amount;

		cin >> amount;

		// get the object who logged in 

		Client loggedClient = getLoggedClient();

		//invoking withdraw method
		if (loggedClient.get_balance() > amount) {
			
			loggedClient.withdraw(amount);

			//update balance of the client account owner (in the vector that contains the info)
			updateLoggedClientBalance(amount, 1);

			// update client object info in the txt file 

			FilesHelper::update_client_data_base(1, loggedClientSteps, loggedClient);


			FilesHelper::saveEveryOperation(2, "Client", "Withdraw", info_segments[0], amount);
			doingAnotherOperation();


		}
		else
		{
			PrintMessage::invalid_operation();

			doingAnotherOperation();
		}

	}


	static void transfer() {

		double transferAmount;
		PrintMessage::EnterTransferAmount();
		cin >> transferAmount;

		Client loggedClient = getLoggedClient();


		if (Validation::canWithdraw(transferAmount, loggedClient.get_balance())) {

			//update balance of the client account owner (in the vector that contains the info)

			updateLoggedClientBalance(transferAmount, 1);

			// getting the receiever information
			Parser::create_info_vector("1");

			// save receiever info in this vector
			vector<string> transferToInfo = Parser::get_info_segments();

			if (transferToInfo.size() > 0) {

				// update client object balance
				loggedClient.withdraw(transferAmount);


				// updating receiever blanace inside the vector that contains its info segments 

				double recieverBalance = stod(transferToInfo[3]) + transferAmount;

				transferToInfo[3] = to_string(recieverBalance);

				// update receiever info in the txt file 

				Employee::update_client_data_base(1, transferToInfo);

				// update client object info in the txt file 

				FilesHelper::update_client_data_base(1, loggedClientSteps, loggedClient);

				FilesHelper::saveEveryOperation(3, "Client", "Transfer", info_segments[0], transferAmount, transferToInfo[0]);

				doingAnotherOperation();
			}
			
			

		}
		else
		{
			doingAnotherOperation();

		}
	}




	static void deposite() {

		double depositeAmount;

		PrintMessage::EnterDepositeAmount();

		cin >> depositeAmount;

		Client loggedClient = getLoggedClient();

		if (Validation::canDeposit(depositeAmount)) {

			loggedClient.deposit(depositeAmount);

			updateLoggedClientBalance(depositeAmount, 2);

			FilesHelper::saveEveryOperation(4, "Client", "Deposite", info_segments[0], depositeAmount);

			doingAnotherOperation();


		}
	}

	static void changePassword() {

		Client loggedClient = getLoggedClient();

		PrintMessage::enterNewPassword();

		string newPassword;

		cin >> newPassword;


		if (Validation::isPassWord(newPassword)) {

			loggedClient.set_password(newPassword);

			PrintMessage::paasswordUpdated();

			FilesHelper::update_client_data_base(1, loggedClientSteps, loggedClient);

		}

		info_segments[2] = newPassword;

		FilesHelper::saveEveryOperation(1, "Client", "Password Changed", info_segments[0]);

		doingAnotherOperation();

	}


	static void checkBalance() {
		Client loggedClient = getLoggedClient();

		loggedClient.checkBalance();

		doingAnotherOperation();
	}


	static void doingAnotherOperation() {
		PrintMessage::askingForAnotherOperation();
		int answer;
		cin >> answer;

		if (answer == 1) {
			printClientOperations();
		}
		else
		{
			return;
		}

	}


	static void updateLoggedClientBalance(double amount, int i) {

		if (i == 1) {
			
			double newBalance = stod(info_segments[3]) - amount;

			info_segments[3] = to_string(newBalance);

		}
		else
		{

			double newBalance = stod(info_segments[3]) + amount;

			info_segments[3] = to_string(newBalance);

		}
	}
};

