#include <iostream>
#include <string>
#include <stack>

using namespace std;

int myPow(int x, int p){
    if (p == 0) return 1;
    if (p == 1) return x;
  
    int tmp = myPow(x, p/2);
    if (p%2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}

int main(void){
    bool Evaluting = true;
    while (Evaluting){
        cout << "Enter the postfix expression: " ;
        
        stack<int> expression; //stack for evaluting answer
        string str; //
        getline( cin, str );
        for(string::iterator it = str.begin(); it!= str.end(); it++){
            char tmp = *it;
            if( tmp== ' ') //skip if null (to speed up)
                continue;
            if( tmp >= '0' && tmp <= '9' ){ //if number , push
                expression.push((tmp - '0'));
            }
            else if( tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp =='%' || tmp == '^'){ //if symbol, pop pop and push the evaluate number
                int second = expression.top();
                expression.pop();
                int first = expression.top();
                expression.pop();
                if(tmp == '+')
                    first = first + second;
                else if (tmp == '-')
                    first = first - second;
                else if (tmp == '*')
                    first = first * second;
                else if (tmp == '/')
                    first = first / second;
                else if (tmp == '%')
                    first = first / second;
                else
                    first = myPow( first, second );

                expression.push(first);
            }
        }
        int answer = expression.top();

        //output
        cout << "The value of the expression is: " << answer << endl;
        cout << "Continue?" << endl;
        cout << "Y/y" << endl;
        //check repeat
        char c = 'n';
        cin >> c ;
        if( c != 'Y' && c != 'y' )
            Evaluting = false;
        cin.ignore();
    }
    
    exit(0);
}