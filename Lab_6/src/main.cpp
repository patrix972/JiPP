#include <iostream>
#include "HRMS.hpp"
using namespace std;



int main() {

    HRMS system = HRMS();

    Employee first("Jody", "Morales", "D_ID_1", "Advertising Director");
    Employee second("Rosalie", "French", "D_ID_1", "Advertising Executive");
    Employee third("Blanche", "Miles", "D_ID_2", "Advertising Manager");
    Employee fourth("Guy", "Copeland", "D_ID_2", "Promotions Director");
    Employee fifth("Vernon", "Owens", "D_ID_3", "Banking Manager");
    Employee sixth("Shelia", "Cunningham", "D_ID_3", "Financial Director");
    Employee seventh("Ervin", "Conner", "D_ID_4", "Financial Officer");
    Employee eigth("Bruce", "Pearson", "D_ID_4", "Fiscal Manager");
    Employee ninth("Mitchell", "Mccormick", "D_ID_4", "Personnel Director");
    Employee tenth("Donnie", "Porter", "D_ID_5", "Personnel Manager");

    system.add(first, "D_ID_1", 11100);
    system.add(second, "D_ID_1", 16400);
    system.add(third, "D_ID_2", 8110);
    system.add(fourth, "D_ID_2", 2300);
    system.add(fifth, "D_ID_3", 1550);
    system.add(sixth, "D_ID_3", 23150);
    system.add(seventh, "D_ID_4", 2210);
    system.add(eigth, "D_ID_4", 21300);
    system.add(ninth, "D_ID_4", 11200);
    system.add(tenth, "D_ID_5", 13700);


    system.printSalaries();

    system.changeSalary("3", 21300);
    system.changeSalary("6", 13220);
    system.changeSalary("7", 13450);
    
    system.printSalaries();

    
    cout  << "Printing department D_ID_1 employees" << endl;
    system.printDepartment("D_ID_1");

    cout << "Printing departments: D_ID_2" << endl;
    system.printDepartment("D_ID_2");

    cout  << "Printing departments: D_ID_3" << endl;
    system.printDepartment("D_ID_3");

    cout  << "Printing departments: D_ID_4" << endl;
    system.printDepartment("D_ID_4");

    cout  << "Printing departments: D_ID_5" << endl;
    system.printDepartment("D_ID_5");



    cout << endl
         << "Printing sorted salaries"
         << endl;

    system.printSalariesSorted(); 
    
}