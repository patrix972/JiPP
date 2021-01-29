
#include "parser.h"

bool isOperator(int x) {
	if(x < 48 ||  x > 57) 
		return 1;
	else 
		return 0;	
}

bool isNumber(int x) {
	if(x > 47 && x < 58)
		return 1;
	else
		return 0;
}


bool isNegative(string x) {
    if (x.size() > 1 && x[0] == '-')
        return 1;
    else
        return 0;
}

bool isFunction(int x) {
    if (x > 102 && x < 117)
        return 1;
    else
        return 0;
}




 void convertExpression(string &expression){
	
    string functions[] = {"sin","cos", "ctg", "tg", "sqrt"};
    for(int i = 0; i < 5 ; i++) {
		int searchIndex;
        while((searchIndex = expression.find(functions[i])) != -1) {
            expression.replace(searchIndex, functions[i].length(),string(1,functions[i].at(1)));
		}
    }
}


int expressionToArray(string expression, string tab[]) {
		
		int tabIndex = 0;
		int character;
		bool negation = 0;
		bool dot = 0;
		string temp;
		
		
        for(int i = 0; i < expression.length(); i++) {
		character = expression.at(i);
		if(isOperator(character)) {
			if(character == '-' && (i == 0 || (expression.at(i-1) == '(' && isNumber(expression.at(i+1))))){
				negation = 1;
				
			} else if(character == '.') {
				dot = 1;	
			} else {
				tab[tabIndex] = character;
			}
			
		} else {
			temp = "";
			while(isNumber(character)) {
				temp+=character;
				i++;
				character = expression.at(i);
			}
			if (negation){
				negation = 0;
				temp.insert(0,"-");
				tabIndex--;
			}
			if(dot == 1){
				tabIndex-=2;
				dot = 0;
				tab[tabIndex].push_back('.');
				tab[tabIndex]+=temp;
				temp = tab[tabIndex];
			}
			tab[tabIndex] = temp;
			i--;	
		}
		
		tabIndex++;
	} 
    return tabIndex;
}

int priority ( char c )
{
  switch ( c )
  {
    case '+': ;
    case '-': 
		return 1;
    case '*': ;
    case '/': 
		return 2;
    case '^': 
		return 3;
    case 'q': ;
	case 'i': ;
	case 'o': ;
	case 't': ;	
	case 'g': 
		return 4;	
  }
  return 0;
}





int expressionToRPN(string tab[], string ONP[]) {
	string stack[100];
	int stackCount = 0;
	int tabCount = 0;
	int ONPCount = 0;
	string element;
	
	while(true) {
		
		
		element = tab[tabCount++];
		if(element == "=") {
			while (stackCount > 0){
				ONP[ONPCount++] = stack[--stackCount];
			}
			break;
		}
		
		if(element.size() == 1) {
			switch(element[0]) {
				case '(': 
					stack[stackCount++] = '(';
					break;
				
				case ')': 
					while(stack[stackCount - 1][0] != '(') {
						ONP[ONPCount++] = stack[--stackCount];
					}
					stackCount--;
					break;	
				
				case '+': ;				
				case '-': ;
				case '*': ;
				case '/': ;
				case '^': ;
				case 'q': ;
				case 'i': ;
				case 'o': ;
				case 'g': ;
				case 't': 
					while(stackCount >= 0) {
						if (stackCount != 0 && priority(stack[stackCount - 1][0]) >= priority(element[0])){
							ONP[ONPCount++] = stack[--stackCount];
						} else {
							break;
						}		
					}
					stack[stackCount++] = element;
					break;
				default:
					ONP[ONPCount++] = element;
					break;	
			}
		} else {
			ONP[ONPCount++] = element;
		}
		
		
		
	}
    ONP[++ONPCount]="=";
	return ONPCount;	
}


double ONPToResult(string ONP[]) {
	
	double result[100];
	double a;
	double b;
	int ONPCount = 0;
	int resultCount = 0;
	string element;	
	const double PI = 3.14159265;

	while(true) {
		
		element = ONP[ONPCount++];
		
	
		if(element == "=") {

            return result[--resultCount];
			
		} else if(isNumber(element[0]) || (element[0] == '-' && element.size() > 1)) {
			
			result[resultCount++] = stod(element);

		} else {

            if ((element[0] > 41 && element[0] < 48) || element[0] == 94){

				b = result[--resultCount];
				a = result[--resultCount];

				switch(element[0]) {
					
					case '+': a += b; break;
					case '-': a -= b; break;	
					case '*': a *= b; break;
					case '/': a /= b; break;
					case '^': a = pow(a, b); break;
					default: break;
			
				}
			} 	else {
					a = result[--resultCount];
					switch(element[0]) {

					case 'i': a = sin(a*(PI/180)); break;
					case 'o': a = cos(a*(PI/180)); break;
					case 'g': a = tan(a*(PI/180)); break;
					case 't': a = 1/tan(a*(PI/180)); break;
					case 'q': a = sqrt(a); break;
					default: break;
					}
				}	
		result[resultCount++] = a;
		}

	}

}


bool validation (string tab[], int size) {

    int leftBracket = 0;
    int rightBracket = 0;
    string element;


    for (int i = 0; i < size; i++) {
        element = tab[i];

        if (element[0] == '=')
            return true;

        if (isOperator(element[0]) && !isNegative(element)) {

        if (element[0] == '(') {
            if (isOperator(tab[i + 1][0]) && !isNegative(tab[i + 1]) && !isFunction(tab[i + 1][0]) && tab[i + 1][0] != '(')
                return false;
            if ( i != 0 && (isNumber(tab[i - 1][0]) || isNegative(tab[i -1])))
                return false;
            leftBracket++;
        } else if (element[0] == ')') {
            if (i == 0)
                return false;
            else if (isOperator(tab[i - 1][0]) && !isNegative(tab[i - 1]) && !isFunction(tab[i - 1][0]) && tab[i - 1][0] != ')')
                return false;

            else if (isNumber(tab[i + 1][0]) || isNegative(tab[i + 1]))
                return false;

            rightBracket++;
        } else if (element[0] == '.')
            return false;

            else {
                if (i == 0 && !isFunction(element[0]))
                    return false;

                else if (!isNegative(tab[i - 1]) && isOperator(tab[i - 1][0]) && tab[i - 1][0] != ')' &&  !isFunction(tab[i][0]))
                    return false;

                else if (!isNegative(tab[i + 1]) && isOperator(tab[i + 1][0]) && tab[i + 1][0] != '(' && !isFunction(tab[i + 1][0]) )
                    return false;

                else if (isFunction(tab[i][0]) && (isFunction(tab[i - 1][0]) || isFunction(tab[i + 1][0]) ))
                    return false;
            }
        }
        else {

            if (element.find('.') != -1) {
                int counter = 0;
                for (int i = 0; i < element.size(); i++) {
                    if (element[i] == '.')
                        counter ++;
                }
                if (counter > 1)
                    return false;
            }
        }


    }
    if (leftBracket != rightBracket) {
        return false;
    }
    return true;
}


