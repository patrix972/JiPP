#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <time.h>


using namespace std;

Matrix::Matrix(int n, int m) {
    if (n < 1 || m < 1) {
        cout << "Bledna liczba kolumn lub wierszy" << endl;
    } else {
        this -> n = n;
        this -> m = m;
        this -> tab = new double [n * m];
        for (int i = 0 ; i < n * m; i++) {
            this -> tab[i] = 0;
        }
    }
}

Matrix::Matrix(int m) {
    if (m < 1) {
        cout << "Bledna liczba kolumn i wierszy" << endl;
    } else {
        this -> n = m;
        this -> m = m;
        this -> tab = new double [m * m];
        for (int i = 0 ; i < m * m; i++) {
            this -> tab[i] = 0;
        }
    }
}

void Matrix::set(int n, int m, double val) {
    if (n < 0 || m < 0 || n >= this->n || m >= this->m) {
        cout << "bledna liczba kolumn lub wierszy" << endl;
    } else {

        tab[this -> m * n + m] = val;
    }
}

double Matrix::get(int n, int m) {
    if (n < 0 || m < 0 || n >= this->n || m >= this->m) {
        cout << "bledna liczba kolumn lub wierszy" << endl;
        return 0;
    } else {
        return tab[this->m * n + m];
    }
    
}

Matrix Matrix::add(Matrix m2) {

    Matrix temp = Matrix(m2.n, m2.m);

    if (this->m != m2.m || this->n != m2.n) {
        cout << "Macierze musza miec taka sama liczbe kolumn i wierszy" << endl;
        return temp;
    } else {

        for (int i = 0; i < n * m; i++) {
            int size = n*m;
            temp.tab[i] = this -> tab[i] + m2.tab[i];
        }
        return temp;
    }
}

void Matrix::print() {
    for (int i = 1; i <= n * m; i++) {
        if (i % m == 1)
            cout << endl;
                
        cout << this -> tab[i - 1] << " ";
    }
    cout << endl;
}

Matrix Matrix::subtract(Matrix m2) {
    Matrix temp = Matrix(m2.n, m2.m);

    if (this->m != m2.m || this->n != m2.n) {
        cout << "Macierze musza miec taka sama liczbe kolumn i wierszy" << endl;
        return temp;
    } else {

        for (int i = 0; i < n * m; i++) {
            int size = n*m;
            temp.tab[i] = this -> tab[i] - m2.tab[i];
        }
        return temp;
    }
}

Matrix Matrix::multiply(Matrix m2) {
    Matrix temp = Matrix(this->n, m2.m);

    if (this->m != m2.n) {
        cout << "nie mozna pomnozyc tych macierzy" << endl;
        return temp;
    } else {

        int x = 0;
        int y = 0;
        int z = 0;
        double sum = 0;
        for (int i = 0; i < this->n; i++) {   
            for (int j = 0; j < m2.m; j++) {       
                x = this -> m * i;
                y = j; 
                for (int k = 0; k < this -> m; k++) { 
                    sum += this -> tab[x] * m2.tab[y];
                    x++;
                    y += m2.m;
                }
                temp.tab[z] = sum;
                sum = 0;
                z++;
            }
        }
        return temp;
    }
}


        

int Matrix::cols() {
    return this -> m;
}

int Matrix::rows() {
    return this -> n;
}

void Matrix::store(string filename, string path) {
    
    string filePath = path + '/' + filename;
    ofstream file;

    file.open(filePath, ios_base::out);
    if (file.good() == true) {
        file << this->n << " " << this->m << endl;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                file << this->tab[temp++] << " ";
            }
            file << endl;
        }
        file.close();
        cout << "Zapis do pliku: " << filePath << " powiodl sie." << endl;
    }
    else {
        cout << "Problem z zapisem do pliku" << endl;
    }

}

Matrix::Matrix(string filename, string path) {

    string filePath = path + '/' + filename;
    ifstream file;
    
    file.open(filePath, ios_base::in);
    
    if (file.good() == true) {

        file >> this->n >> this->m;
        this -> tab = new double [n * m];

        for (int i = 0 ; i < n * m; i++) {
            file >> this -> tab[i];
        }
        file.close();
        cout << "Odczyt z pliku: " << filePath <<  " powiodl sie" << endl;
    } else {
        cout << "Problem z odczytem z pliku" << endl;
    }
}

void Matrix::fill() {
 
    int randomValue;

    for (int i = 0; i < n * m; i++) {
        this->tab[i] = rand() % 100 + 1; 
    }
}


void Matrix::test() {
    srand (time(NULL));

    cout << "TEST PIERWSZEGO KONSTRUKTORA";
    Matrix m1 = Matrix(4, 5);
    m1.print();

    cout << "TEST DRUGIEGO KONSTRUKTORA";
    Matrix m2 = Matrix(4);
    m2.print();

    cout << "TEST METODY SET DLA 3 WIERSZA I 4 KOLUMNY ";
    m1.set(2, 3, 15);
    m1.print();

    cout << "TEST METODY GET DLA 4 WIERSZA 1 KOLUMNY PODANEJ MACIERZY:";
    m1.fill();
    m1.print();
    cout << "Wartosc 3,0 tej macierzy to: " << m1.get(3, 0) << endl;

    cout << "TEST METODY ADD DLA PONIZSZYCH MACIERZY: " << endl;
    cout << "Pierwsza macierz: " << endl;
    m1.print();
    cout << " Druga macierz: " << endl;
    Matrix m3 = Matrix(4, 5);
    m3.fill();
    m3.print();
    cout << "Macierz wynikowa: " << endl;
    Matrix m4 = m1.add(m3);
    m4.print();

    cout << "TEST METODY SUBTRACT DLA PONIZSZYCH MACIERZY: " << endl;
    cout << "Pierwsza macierz: " << endl;
    m1.print();
    cout << " Druga macierz: " << endl;
    m3.fill();
    m3.print();
    cout << "Macierz wynikowa: " << endl;
    m4 = m1.subtract(m3);
    m4.print();

    cout << "TEST METODY MULTIPLY DLA PONIZSZYCH MACIERZY: " << endl;
    cout << "Pierwsza macierz: " << endl;
    m1.print();
    cout << " Druga macierz: " << endl;
    Matrix m5 = Matrix(5, 4);
    m5.fill();
    m5.print();
    cout << "Macierz wynikowa: " << endl;
    Matrix m6 =  m1.multiply(m5);
    m6.print();

    cout << "TEST METOD COLS i ROWS DLA PONIZSZEJ MACIERZY: " << endl;
    m1.print();
    cout << "liczba wierszy: " << m1.rows() << endl;
    cout << "liczba kolumn: " << m1.cols() << endl;

    cout << "TEST METODY STORE DLA PONIZSZEJ MACIERZY: " << endl;
    m1.print();
    m1.store("file.txt", ".");

    cout << "TEST KONSTRUKTORA ODCZYTUJACEGO Z PLIKU: " << endl;
    Matrix m7 = Matrix("file.txt", ".");
    m7.print();

}


