#include <iostream>
#include "Employee.hpp"
#include <list>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>


using namespace std;

#ifndef HRMS_HPP
#define HRMS_HPP

class HRMS {

    map<string, Employee> employeesMap;
    map<string, list<string>> employeesDepartments;
    map<string, double> employeesSalary;

    static bool compareRecords(const pair<string, double> &a, const pair<string, double> &b);

   
    public:
        void add(Employee employee, string departmentId, double salary);
        void printDepartment(string departmentId);
        void changeSalary(string employeeId, double salary);
        void printSalaries();
        void printSalariesSorted();
};
#endif