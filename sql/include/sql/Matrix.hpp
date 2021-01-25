#ifndef MATRIX
#define MATRIX

#include <sqlite3/sqlite3.h>
#include <iostream>
using namespace std;

class Matrix {
    private:
        int n,m;
        double *tab;


    public:

        Matrix(int n, int m);

        Matrix(int m);

        void set(int n, int m, double val);

        double get(int n, int m);

        Matrix add(Matrix m2);
        
        void print();

        Matrix subtract(Matrix m2);

        Matrix multiply(Matrix m2);

        int cols();

        int rows();

        void store(string name);

        Matrix (string name);

        void fill ();

        static void test();

};
#endif