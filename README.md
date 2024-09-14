# Banking System Project

## Overview
This C++ project simulates a banking system with three main roles: **Admin**, **Employee**, and **Client**. Each role has different functionalities, and all operations are logged with timestamps in text files for record-keeping. The system uses text files to store and retrieve data like client information, employee details, and transaction records.


### Features by Role

#### Client
A **client** can perform the following actions:
1. **Withdraw**: Withdraw money from their account.
2. **Transfer**: Transfer money to another client.
3. **Deposit**: Deposit money into their account.
4. **Change Password**: Update their account password.
5. **Check Balance**: View the balance of their account.
6. **Logout**: End the session.

#### Employee
An **employee** has access to the following operations:
1. **Add New Client**: Register a new client.
2. **List All Clients**: View a list of all registered clients.
3. **Search for a Client**: Search for a client by name or ID.
4. **Edit Client**: Modify the details of an existing client.
5. **Check Salary**: View the employee's salary details.
6. **Logout**: End the session.

#### Admin
An **admin** can perform all the tasks that employees can, with additional administrative capabilities:
1. **Add New Client**: Register a new client.
2. **List All Clients**: View a list of all registered clients.
3. **Search Clients**: Search for clients by name or ID.
4. **Edit Client**: Modify a client’s information.
5. **Check Salary**: View the salary details of employees.
6. **List All Employees**: View a list of all employees.
7. **Edit Employee**: Modify an employee’s information.
8. **Add Employee**: Register a new employee.
9. **Exit**: Exit the admin session.

### Data Management
- **Text Files**: All data, including client and employee details, is stored in text files (e.g., `client.txt`, `employee.txt`). Each action taken by users is logged with a timestamp in `operations.txt`.
- **Unique Identifiers**: Last used client and employee IDs are stored in `LastIdClient.txt` and `LastIdEmployee.txt` to ensure new users are assigned unique IDs.

### Utility Classes
This project contains various utility classes to support operations such as file management, validation, time management, and more:
- **FilesHelper**: Handles file reading and writing.
- **Validation**: Ensures that user inputs are valid.
- **TimeMangment**: Manages timestamps for logging operations.
- **PrintMessage**: Displays system messages to the console.
- **DataSourceInterface**: Interface for handling data storage and retrieval.

### Build and Run
To build and run this project, you need:
- A C++ compiler (e.g., Visual Studio).
- The project files (`ConsoleApplication21.vcxproj`, `.vcxproj.filters`, `.vcxproj.user`) for configuration.

### Conclusion
This banking system is a robust platform for managing clients, employees, and administrative tasks. With proper logging and data management, it ensures that all operations are secure and transparent.
