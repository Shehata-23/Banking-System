#include "Admin.h"
#include "FilesHelper.h"


Admin::Admin(string name, string password, double salary)
    :Employee(name, password, salary)
    {
    id = id = FilesHelper::GetLast("Adminlastid.txt");

    FilesHelper::SaveEmployeeInfo("admin.txt", "Adminlastid.txt", *this);
}


Admin::Admin(int id, string name, string password, double salary)
    : Employee(name, password, salary), id(id) {

    this->id = id;
    this->name = name;
    this->password = password;
    this->salary = salary;
}



pair<bool, Employee>  Admin::addEmployee(){
    string name;
    PrintMessage::EnterEmployeeName();
    cin >> name;
    double salary;
    PrintMessage::EnterEmployeeSalary();
    cin >> salary;

    if (Validation::isUserName(name) && Validation::is_salary(salary)) {
        string password = "OTP" + to_string(TimeMangment::generateAutoNumbers());
        Employee newEmployee(name, password, salary);

        FilesHelper::SaveEmployeeInfo("employee.txt", "Employeelastid.txt", newEmployee);

        return make_pair(true, newEmployee);
    }
}


vector<string> Admin::searchEmployee() {

    Parser::create_info_vector("2");
    vector<string> information = Parser::get_info_segments();

    if (information.size() >= 4) {
        /*cout << "ID: " << information[0] << endl
            << "Name: " << information[1] << endl
            << "Password: " << information[2] << endl
            << "Balance: " << information[3];*/
        return information;
    }
    else {

    }
}


pair<bool, vector<string>> Admin::editEmployee() {

    vector<string> client_to_be_edited = Admin::searchEmployee();

    if (client_to_be_edited.size() > 0) {


        PrintMessage::EnterEmployeeName();
        cin >> client_to_be_edited[1];

        PrintMessage::EnterEmployeeSalary();
        cin >> client_to_be_edited[3];

        Admin::update_Employee_data_base(client_to_be_edited);

        return make_pair(true, client_to_be_edited);
    }
    else {
        return make_pair(false, client_to_be_edited);
    }


}

 void Admin::update_Employee_data_base(vector<string> edited_Employee) {
    string lines;
    vector<string> Employee_data;
    int steps = Parser::return_steps(); // to know where i should add the info string 


    ifstream inputFile("employee.txt");

    while (getline(inputFile, lines)) {
        Employee_data.push_back(lines);
    }
    inputFile.close();


    ofstream outFile("employee.txt", ios::trunc);
    outFile.close();

    ofstream outputFile("employee.txt", ios::app);

    for (int i = 0; i < Employee_data.size(); i++) {
        if (i == steps) {
            outputFile << edited_Employee[0] << "|" << edited_Employee[1] << "|" << edited_Employee[2] << "|" << edited_Employee[3] << endl;
        }
        else {
            outputFile << Employee_data[i] << endl;
        }
    }

    outputFile.close();

}




