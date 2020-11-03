#include <iostream>

using namespace std;

void swapValues(int &a, int *b) {
       int temp = a;
       a = *b;
       *b = temp;
    
}

int main() {
    int first_value, second_value;

    cout << "podaj pierwsza zmienna: ";
    cin >> first_value;
    cout << "podaj druga zmienna: ";
    cin >> second_value;

    swapValues(first_value, &second_value);

    cout << "zmienna a = " << first_value << " zmienna b = " << second_value;

    return 0;

}