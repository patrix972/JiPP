#include <string>
using namespace std;

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

static int id_counter; 

class Employee {

    private:  
        string id;
        string name;
        string surname;
        string departmentId;
        string position;
        
    public:
        Employee();
        Employee(string name, string surname, string departmentId, string position);

        string getId();
        string getName();
        string getSurname();
        string getDepartmentId();
        string getPosition();

};
#endif