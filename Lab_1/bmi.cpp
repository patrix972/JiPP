#include <iostream>
#include <math.h>
using namespace std;
int main() {

    double weight;
    double height;
    double bmi;

    cout << "podaj mase ciala [kg]: " << endl;
    cin >> weight;

    cout << "podaj wzrost [cm]: " << endl;
    cin >> height;

    bmi = (weight / pow (height / 100, 2));
 
    if (bmi < 16) 
        cout << "wyglodzenie";
    else if (bmi < 17)
        cout << "wychudzenie";
    else if (bmi < 18.5)
        cout << "niedowaga";
    else if (bmi < 25)
        cout << "wartosc prawidlowa";
    else if (bmi < 30)
        cout << "nadwaga";
    else if (bmi < 35)
        cout << "I stopien otylosci";
    else if (bmi < 40)
        cout << "II stopien otylosci";   
    else
        cout << "otylosc skrajna";   
}