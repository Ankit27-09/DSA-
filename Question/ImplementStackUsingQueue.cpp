#include <iostream>
using namespace std;

class Stack {   
    public:
        int* arr;
        int top;
        int size;
    public:
        Stack(int sizee) {
            top = -1;
            size = sizee;
            arr = new int[size];
        }

        int push(int x) {
            if(top == size - 1) {
                cout << "The Stack is Overflow \n";
                return -1;
            }
            else {
                top++;
                arr[top] = x;
                return arr[top];
            }
        }

        void pop() {
            if(top == -1) {
                cout << "Stack is Underflow \n";
            }
            else {
                top--;
            }

        }

        bool isEmpty() {
            return top == -1;
        }

        int sizeOfStack() {
            return top + 1;
        }

        int topOfStack() {
            if(top == -1) {
                cout << "Stack is Empty \n";
                return -1;
            }
            else {
                return arr[top];
            }
        }
};


int main() {

    Stack st(5);
    cout << st.push(5) << endl;
    cout << st.push(4) << endl;
    cout << st.push(51) << endl;
    cout << st.push(0) << endl;
    cout << st.push(76) << endl;
    st.pop();
    cout << st.topOfStack() << endl;
    cout << st.sizeOfStack() << endl;

    return 0;
}