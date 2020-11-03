#include <iostream>

using namespace std;

template <typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int a = 20, b = 10;
    int* ptrA = &a, *ptrB = &b;
    string c = "jeden", d = "dwa";
    string *ptrC = &c, *ptrD = &d;

    cout << "Test dla int" << endl;
    cout << "wartosc a przed zamiana: " << *ptrA << endl;
    cout << "wartosc b przed zamiana: " << *ptrB << endl;
    swap(&ptrA, &ptrB);
    cout << "wartosc a po zamianie: " << *ptrA << endl;
    cout << "wartosc b po zamianie: " << *ptrB << endl;

    cout << "Test dla string" << endl;
    cout << "wartosc c przed zamiana: " << *ptrC << endl;
    cout << "wartosc d przed zamiana: " << *ptrD << endl;
    swap(&ptrC, &ptrD);
    cout << "wartosc c po zamianie: " << *ptrC << endl;
    cout << "wartosc d po zamianie: " << *ptrD << endl;


    return 0;
}