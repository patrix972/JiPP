#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {

    if (argc == 1) {
        cout << "Brak argumentu";
        return 0;
    }

    string word = argv[1];
    
    
    for (int i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - 1 - i]) {
            cout << "Slowo nie jest palindromem." << endl;
            return 0;
        }
    }
    cout << "Slowo jest palindromem." << endl;
    return 0;
}
