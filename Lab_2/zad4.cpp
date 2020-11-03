#include <iostream>

using namespace std;

int doOperations(int a, int b, int &suma) {
    suma = a + b;
    return a * b;
}

int main() {
    int first_value, second_value, iloczyn, suma = 0;

    cout << "podaj pierwsza zmienna: ";
    cin >> first_value;
    cout << "podaj druga zmienna: ";
    cin >> second_value;

    iloczyn = doOperations(first_value, second_value, suma);

    cout << "Iloczyn wynosi: " << iloczyn << ", a suma wynosi: " << suma;

    return 0;
}