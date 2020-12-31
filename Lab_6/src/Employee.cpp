#include "Employee.hpp"


Employee::Employee(){};
Employee::Employee(string name, string surname, string departmentId, string position) {

    this -> id = to_string(++id_counter);
    this -> name = name;
    this -> surname = surname;
    this -> departmentId = departmentId;
    this -> position = position;
}

string Employee::getId() {
    return this -> id;
}

string Employee::getName() {
    return this -> name;
}

string Employee::getSurname() {
    return this -> surname;
}

string Employee::getPosition() {
    return this -> position;
}

string Employee::getDepartmentId() {
    return this -> departmentId;
}