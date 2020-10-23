#include <iostream>     
#include <iomanip> 

using namespace std;

void filling_matrix (double tab[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tab[i][j];
        }
    }
}

void print_matrix (double tab[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tab[i][j]<< " ";
        }
    cout << endl;
    }    
}

int main () 
{
    double matrix_one[2][3];
    double matrix_two[2][3];
    double matrix_result[2][3];
    
    cout << "podaj macierz pierwsza: ";
    filling_matrix(matrix_one);

    cout << "podaj macierz druga: ";
    filling_matrix(matrix_two);
    
    cout << "Macierz pierwsza: " << endl;
    print_matrix(matrix_one);

    cout << "Macierz druga: " << endl;
    print_matrix(matrix_two);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            matrix_result[i][j] = matrix_one[i][j] + matrix_two[i][j];
        } 
    }

    cout << "Macierz wynikowa: " << endl;
    print_matrix(matrix_result);

    return 0;
}