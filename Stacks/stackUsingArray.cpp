/* It is a linear data structure, in which insertion and deletion only
allowed at the end, called at the top of the stack.*/

/* Stacks are a type of container adaptors with LIFO(Last In First Out)*/

/* When we define a stack as an Abstract data type, then we are only intrested
in know the stack operation from user pov.*/

/* It is simply mean we are not intrested in knowing the details , we
only intrested in what type of output we can perform. */

/* Key Operations on Stack Data Structures
Push: Adds an element to the top of the stack.
Pop: Removes the top element from the stack.
Peek: Returns the top element without removing it.
IsEmpty: Checks if the stack is empty.
IsFull: Checks if the stack is full (in case of fixed-size arrays).*/

/* A stack overflow is a type of buffer overflow error that occurs
when a computer program tries to use more memory space in the call
stack than has been allocated to that stack.*/

// Implement the stack with the array

#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;
    

public:
    bool flag;
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
    }
    // Push
    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow \n";

            return;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " in to the stack" << endl;
            flag = 0;
        }
    }
    // Pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow";
            return;
        }
        else
        {
            cout << "Popped " << arr[top] << " from the stack \n";
            if(top == -1) {
                flag = 1;
            }
        }
        top--;
    }
    // Peek
    int peek() {
        if(top == -1) {
            cout << "Stack is empty ";
            return -1;
        }
        else {
            return arr[top];
        }
    }

    //IsEmpty
    bool isEmpty() {
        return top == -1;
    }

    // IsSize
    int isSize() {
        return top + 1;
    }
};

#include <iostream>
using namespace std;

int main()
{

    Stack S(5);
  
    int value = S.peek();
    if(S.flag == 0) {
       cout << value <<endl;
    }

    S.push(5);
    S.push(1);
    S.pop();
    S.pop();
    S.pop();
    // S.push(9);
    // S.push(4);
    // S.push(7);
    
    // cout << S.peek() << "\n";
    // cout << S.isSize() << "\n";
    // cout << S.isEmpty() << "\n";
}