#include <iostream>
#include <stdlib.h>
#include "Stack.h"
using namespace std;

int main(int argc, char **argv)
{
    Stack<int> s;
    Stack<double> s2;
    int i;
    double j;
    for (i = 0; i < 10; i++)
        s.Push(i);
    for (i = 0; i < 10; i++)
        cout << s.Pop() << endl;
    if (s.IsStackEmpty())
        cout << "Stack is empty" << endl;
    for (i = 0; i < 10; i++){
        j = i * 1.1;
        s2.Push(j);
    }
    for (i = 0; i < 10; i++)
        cout << s2.Pop() << endl;
    if (s2.IsStackEmpty())
        cout << "Stack is empty" << endl;
    return 0;
}