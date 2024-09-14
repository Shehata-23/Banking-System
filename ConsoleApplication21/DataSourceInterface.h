#pragma once
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"




class DataSourceInterface
{

	virtual void addClient(Client&) = 0;
	virtual void addEmployee(Employee&) = 0;
	virtual void addAdmin(Admin&) = 0;

	// read
	virtual vector<string> getAllClients() = 0;
	virtual vector<string> getAllEmployees() = 0;
	virtual vector<string> getAllAdmins() = 0;

	// delete
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};