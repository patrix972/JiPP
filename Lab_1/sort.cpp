#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {

    if (argc == 1) {
		cout << "Brak argumentow";
		return 0;
	}

	for (int i = 0; i < argc; i++)
		for (int j = 2; j < argc - i; j++)
		    if (atoi(argv[j - 1]) > atoi(argv[j]))
                swap(argv[j - 1], argv[j]);
            			    
	cout << "out = ";		
	for (int i = 1; i < argc; i++) {
		cout << argv[i] << " ";  
	}
}