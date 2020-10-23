#include <iostream>
using namespace std;

int sum_dividers (int number) {

    int sum = 0;

    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        } 
    }
    return sum;    
}

int main() {
    int a, b, sum_a, sum_b;
    cout << "Podaj liczby a i b: ";
    cin >> a >> b;

    if (a <= 1 || b <= 1) {
        cout << "Liczby nie sa skojarzone.";
        return 0;
    } else {
        sum_a = sum_dividers(a);
        sum_b = sum_dividers(b);
    }

    if (sum_a == b + 1 && sum_b == a + 1) {
        cout << "Liczby sa skojarzone.";
    } else {
        cout << "Liczby nie sa skojarzone.";
    }   
    return 0;
}