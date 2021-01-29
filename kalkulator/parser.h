#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <math.h>
#include <string>

using namespace std;




    bool isOperator(int x);
    bool isNumber(int x);
    bool isNegative(string x);
    bool isFunction(int x);
    void convertExpression(string &expression);
    int expressionToArray(string expression, string tab[]);
    int priority ( char c );
    int expressionToRPN(string tab[], string ONP[]);
    double ONPToResult(string ONP[]);
    bool validation (string tab[], int size);










#endif // PARSER_H
