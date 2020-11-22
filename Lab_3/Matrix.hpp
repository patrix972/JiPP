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

        void store(string filename, string path);

        Matrix (string filename, string path);

        void fill ();

        static void test();
};