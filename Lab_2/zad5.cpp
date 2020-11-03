#include <iostream>

using namespace std;

template <typename T>
void swapArguments(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 20, b = 10;
    string c = "jeden", d = "dwa";
    char e = 'e', f = 'f';
    float g = 2.5, h = 3.1;


    cout << "Test dla int" << endl;
    cout << "wartosc a przed zamiana: " << a << endl;
    cout << "wartosc b przed zamiana: " << b << endl;
    swapArguments(a, b);
    cout << "wartosc a po zamianie: " << a << endl;
    cout << "wartosc b po zamianie: " << b << endl;

    cout << "Test dla string" << endl;
    cout << "wartosc c przed zamiana: " << c << endl;
    cout << "wartosc d przed zamiana: " << d << endl;
    swapArguments(c, d);
    cout << "wartosc c po zamianie: " << c << endl;
    cout << "wartosc d po zamianie: " << d << endl;

    cout << "Test dla char" << endl;
    cout << "wartosc e przed zamiana: " << e << endl;
    cout << "wartosc f przed zamiana: " << f << endl;
    swapArguments(e, f);
    cout << "wartosc e po zamianie: " << e << endl;
    cout << "wartosc f po zamianie: " << f << endl;

    cout << "Test dla float" << endl;
    cout << "wartosc g przed zamiana: " << g << endl;
    cout << "wartosc h przed zamiana: " << h << endl;
    swapArguments(g, h);
    cout << "wartosc g po zamianie: " << g << endl;
    cout << "wartosc h po zamianie: " << h << endl;
    


    return 0;
}