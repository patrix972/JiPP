#include "Lab_5/Matrix.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>


using namespace std;

class MyException : public exception
{
    virtual const char *what() const throw()
    {
        return "Bledna liczba kolumn lub wierszy";
    }
};

Matrix::Matrix(int n, int m) {

        this -> n = n;
        this -> m = m;

        try {
            this -> tab = new double [n * m];
            for (int i = 0 ; i < n * m; i++) {
                this -> tab[i] = 0;
            }
        } catch (const bad_array_new_length &e) {
            cout << e.what() << endl;
        }
}

Matrix::Matrix(int m) {

        this -> n = m;
        this -> m = m;
    try {
        if (m <= 0 ) {
            throw bad_array_new_length();
        }
        this -> tab = new double [m * m];
        for (int i = 0 ; i < m * m; i++) {
            this -> tab[i] = 0;
        }
    } catch (const bad_array_new_length &e ) {
        cout << e.what() << endl;
    }
}

void Matrix::set(int n, int m, double val) {
    MyException myEx;
    try{
        if (n < 0 || m < 0 || n >= this->n || m >= this->m) {
            throw myEx;
        }
        
    }  catch (exception &e) {
        cout << e.what() << endl;
    }
    tab[this -> m * n + m] = val;
}

double Matrix::get(int n, int m) {
    MyException myEx;
    try{
        if (n < 0 || m < 0 || n >= this->n || m >= this->m) {
            throw myEx;
        }
    } catch (exception &e){
        cout << e.what() << endl;
        return 0;
    }
    return tab[this->m * n + m];
}

Matrix Matrix::add(Matrix m2) {
    MyException myEx;
    Matrix temp = Matrix(m2.n, m2.m);

    try{
        if (this->m != m2.m || this->n != m2.n) {
            throw myEx;
        }
    } catch (exception &e) {
        cout << e.what() << endl;
        return temp;
    }

        for (int i = 0; i < n * m; i++) {
            int size = n*m;
            temp.tab[i] = this -> tab[i] + m2.tab[i];
        }
        return temp;
    
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
    MyException myEx;
    Matrix temp = Matrix(m2.n, m2.m);

    try{
        if (this->m != m2.m || this->n != m2.n) {
            throw myEx;
        }
    } catch (exception &e) {
        cout << e.what() << endl;
        return temp;
    }
    for (int i = 0; i < n * m; i++) {
        int size = n*m;
        temp.tab[i] = this -> tab[i] - m2.tab[i];
    }
    return temp;
}

Matrix Matrix::multiply(Matrix m2) {
    MyException myEx;
    Matrix temp = Matrix(this->n, m2.m);

    try{
        if (this->m != m2.n) {
            throw myEx;
        }
    } catch (exception &e) {
        cout << e.what() << endl;
        return temp;
    }

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


    try {
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
        throw file.good();
    }
    }  catch (bool &e) {
            cout << "problem z zapisem do pliku" << endl;
        }
}

Matrix::Matrix(string filename, string path) {

    string filePath = path + '/' + filename;
    ifstream file;
    
    file.open(filePath, ios_base::in);
    
    try {
    if (file.good() == true) {

        file >> this->n >> this->m;
        this -> tab = new double [n * m];

        for (int i = 0 ; i < n * m; i++) {
            file >> this -> tab[i];
        }
        file.close();
        cout << "Odczyt z pliku: " << filePath <<  " powiodl sie" << endl;
    } else {
        throw file.good();
    }
    }  catch (bool &e) {
            cout << "problem z odczytem do pliku" << endl;
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


