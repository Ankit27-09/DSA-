#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

public:
    Queue(int sizee)
    {
        front = -1;
        rear = -1;
        size = sizee;
        arr = new int[sizee];
    }

    void push(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow \n";

        }
        else
        {
            if(front == -1) {
                front = 0;
            }
            rear++;        
            arr[rear] = x;
        }
    }

    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow \n";
        }
        else
        {
            front = front + 1;
        }
    }

    int getSize()
    {
        if (front == -1 || front > rear)
        {
            return 0;
        }
        else {
            return (rear - front + 1);
        }
    }
};

int main() {
    Queue q(5);
    q.push(5);
    q.push(4);
    q.push(51);
    q.push(0);
    q.push(76);
    q.pop();
    cout << q.getSize() << endl; 
    return 0;
}
