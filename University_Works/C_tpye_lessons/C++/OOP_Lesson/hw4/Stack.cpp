#include <iostream>
#include <stdlib.h>
#include "Stack.h"
using namespace std;

template<class T>
Stack<T>::Stack(void): _stackSize(MaxStackSize), _top(-1) {// constuct the stack
    _stackList = new T[MaxStackSize];
};

template<class T>
void Stack<T>::PushExtend(const T &item){
    T *oldList = _stackList;
    _stackList = new T[_stackSize * 2];
    for(int i=0; i< _stackSize; i++)
        _stackList[i] = oldList[i];
    delete oldList;
    _stackSize *= 2;

};

template<class T>
void Stack<T>::Push(const T &item){// push item on top of the stack
    if(IsStackFull())
        PushExtend(_stackList);
    ++_top;
    _stackList[_top] = item;
};

template<class T>
T Stack<T>::Pop(void){// pop the stack
    T data = _stackList[_top];
    --_top;
    return data;
};

template<class T>
void Stack<T>::ClearStack(void){// reset the value of _top to -1
    _top = -1;
};

template<class T>
T Stack<T>::Top(void)const{// return item on top of the stack
    return _stackList[_top];
};

template<class T>
bool Stack<T>::IsStackEmpty(void) const{// check if the stack is empty
    if(_top == -1)
        return true;
    return false;
};

template<class T>
bool Stack<T>::IsStackFull(void) const{// check if the stack is full
    if( _stackSize - 1 == _top)
        return true;
    return false;
};
