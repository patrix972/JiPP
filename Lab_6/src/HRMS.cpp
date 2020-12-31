#include "HRMS.hpp"

using namespace std;

void HRMS::add(Employee employee, string departmentId, double salary){
    
    try {
        if (employee.getDepartmentId() != departmentId) {
            string error = "employee's departmentId does not match the given departmentId";
            throw error;
        } else if (salary <= 0) {
            throw 0;
        } else {
            employeesMap[employee.getId()] = employee;
            employeesDepartments[departmentId].push_back(employee.getId());
            employeesSalary[employee.getId()] = salary;
        }
    } catch (string e) {
        cout << e << endl;
    } catch (int e) {
        cout << "incorrect salary value" << endl;
    }

}

void HRMS::printDepartment(string departmentId) {

    list<string> EmployeesList = employeesDepartments[departmentId];

    try {
        if (EmployeesList.empty()) {
            string error = "Department doesn't exist or it's empty";
            throw error;
        } else {
            for (string n : EmployeesList) {
                cout << employeesMap[n].getName() << employeesMap[n].getSurname() << endl;      
            }
        }
    } catch (string e) {
        cout << e << endl;
    }
}

void HRMS::changeSalary(string employeeId, double salary) {

    try {
        if (employeesMap.count(employeeId) == 0) {
            string error = "Employee with id: " + employeeId + " doesn't exist";
            throw error;
        } else if (salary <= 0) {
            throw 0;
        } else {
            employeesSalary[employeeId] = salary;
        }
    } catch (string e) {
        cout << e << endl;
    } catch (int e) {
        cout << "incorrect salary value" << endl;
    }
     
}

void HRMS::printSalaries() {

    map<string, double>::iterator it;

   for (it = employeesSalary.begin(); it!=employeesSalary.end(); ++it) {
      cout << "name: " << employeesMap[it->first].getName() << ", surname: " << employeesMap[it->first].getSurname() << endl;
      cout << "position: " << employeesMap[it->first].getPosition() << ", department: " << employeesMap[it->first].getDepartmentId() << endl;
      cout << "salary: " << it->second << endl;
      cout << endl;
    }

}

void HRMS::printSalariesSorted() {


    vector<pair<string, double>> vect;
    map<string, double>::iterator it2;
    for (it2 = this->employeesSalary.begin(); it2 != this->employeesSalary.end(); it2++)
    {
        vect.push_back(make_pair(it2->first, it2->second));
    }

    sort(vect.begin(), vect.end(), compareRecords);


    vector<pair<string, double>>::iterator it;

    for (it = vect.begin(); it != vect.end(); ++it) {
        cout << "name: " << employeesMap[it->first].getName() << ", surname: " << employeesMap[it->first].getSurname() << endl;
        cout << "position: " << employeesMap[it->first].getPosition() << ", department: " << employeesMap[it->first].getDepartmentId() << endl;
        cout << "salary: " << it->second << endl;
    } 
}

bool HRMS::compareRecords(const pair<string, double> &a, const pair<string, double> &b) {
    return (a.second > b.second);
}