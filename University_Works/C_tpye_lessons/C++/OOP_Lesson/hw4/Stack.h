#ifndef stack111
#define stack111
// =============== Stack.h ====================
const int MaxStackSize = 2; // initial value of _stackSize

template <class T>       // type of data items in the stack
class Stack{
    private:
        T *_stackList; // array of DataTypes
        int _stackSize;       // the size of _stackList
        int _top;             // the index of the top element

        // push item on top of the stack and extend the stack if necessary
        void PushExtend(const T &item);

    public:
        // constuct the stack
        Stack(void); 

        // push item on top of the stack
        void Push(const T &item);
        // pop the stack
        T Pop(void);    
        // reset the value of _top to -1
        void ClearStack(void); 
        // return item on top of the stack
        T Top(void) const;
        // check if the stack is empty
        bool IsStackEmpty(void) const;
        // check if the stack is full
        bool IsStackFull(void) const; 
};
// =============== Stack.h ends =================
#endif
