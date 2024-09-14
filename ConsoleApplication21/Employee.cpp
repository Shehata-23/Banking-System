#include "Employee.h"
#include "FilesHelper.h"
#include <fstream>


void Employee::doSomething() {
    cout << "Employee doing something." << endl;
}

// Constructors
Employee::Employee(string name, string password, double salary) {

    if (password.substr(0, 3) == "OTP") {
        this->password = password;
    }
    else
    {
        Employee::set_password(password);

    }

    // sending the  attributes to inherited setter in person class
    Employee::set_name(name);

    // not inherited 
    Employee::set_salary(salary);

    id = FilesHelper::GetLast("Employeelastid.txt") + 2;
}

Employee::Employee(int id, string name, string password, double salary) {


    // sending the  attributes to inherited setter in person class
    this->name = name;
    this->id = id;
    this->password = password;
    this->salary = salary;

}

// it simply adds a client 

pair<bool, Client> Employee::add_client() {
    string name;
    PrintMessage::EnterClientName();
    cin >> name;
    double balance;
    PrintMessage::EnterClientBalance();
    cin >> balance;

    if (Validation::isUserName(name) && Validation::isBalance(balance)) {
        string password = "OTP" + to_string(TimeMangment::generateAutoNumbers());
        Client newClient(name, password, balance);
        FilesHelper::SaveClientInfo(newClient);
        return make_pair(true, newClient);
    }
}



// by invoking this method it will invoke create_info_vector("1") and it sends 1 as an attribute to open client.txt  


 vector<string> Employee::searchClient() {
    
    Parser::create_info_vector("1"); // will open client.txt and create a vector with the file lines of information
                                       // under the hood of this method it will ask for id and it will search for it
                                       // if found it will return a vector with the segments we searched for 
    
    // vector information will hold the value of the segments which is returned by the parser 
    // which is the object we want....
    // if the search done okay then for sure information.size will = 4 as it holds the info id/name/pass/balance

    vector<string> information = Parser::get_info_segments();

    if (information.size() >= 4) {
       
        return information; // it returns the vector that holds the information so we can edit it easily 
    }
    else {
        
    }
}


// edit method 


void Employee::editClient() {

    // client_to_be_edited is a vector that will hold information the will be returned by searchclient method (the above method)

    vector<string> client_to_be_edited = Employee::searchClient();


    // start editing the info by direct assignation 

    if (client_to_be_edited.size() > 0) {
        PrintMessage::EnterClientID();

        cin >> client_to_be_edited[0];

        PrintMessage::EnterClientName();
        cin >> client_to_be_edited[1];

        PrintMessage::EnterClientPass();
        cin >> client_to_be_edited[2];

        PrintMessage::EnterClientBalance();
        cin >> client_to_be_edited[3];

        Employee::update_client_data_base(1, client_to_be_edited);

    }
    else {
        return;
    }
    

}


//  this method invokes listclient method from fileshelper

void Employee::listClient() {
    FilesHelper::getClients();
}



// this method makes sure that the data base of the clients is saved by the same order after each edit 

                                        // vector od info that we edited // 
void Employee::update_client_data_base(int choice,  vector<string> edited_client) {

    string file;

    switch (choice)
    {
    case 1:
        file = "client.txt";
        break;
    case 2:
        file = "employee.txt";
        break;
    default:
        break;
    }


    string lines; // new declaration of a string 

    vector<string> clients_data; // new declaration of a vector string

    int steps = Parser::return_steps(); // it comes from parser to know where i should add the info string ( that was edited)


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

        if (i == steps) { // this conditions will make sure if we reached the line we want to edit 
            // will add the edited info 
            outputFile << edited_client[0] << "|" << edited_client[1] << "|" << edited_client[2] << "|" << edited_client[3] << endl;
        }
        else { // else it appends the stored info we save before deleting it....
            outputFile << clients_data[i] << endl;
        }
    }

    outputFile.close(); // now we saved our data + we edited the info line // close the file // 

}
   




// Setters
void Employee::set_salary(double salary)
{
    if (Validation::is_salary(salary))
    {
        this->salary = salary;
    }
    else
    {
        PrintMessage::salary_error();
    }
}



// Getters
double Employee::get_salary()
{
    return salary;
}

void Employee::display_info() {
    cout << "Name: " << name << endl
        << "password: " << password << endl
        << "id: " << id << endl
        << "salary: " << salary << endl;
}

