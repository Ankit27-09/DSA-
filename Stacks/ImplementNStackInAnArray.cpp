// N Stack in An Array 
// we have to implement any number of stack with the help of an Array

// Here we make the array with the Nsize 
// like if there is N stacks :-- 3 stacks then the size of an array will be 3 
// each arrray index will hold the index posiiton in the linked list 

// Here we will gonna use one stack that stores the empty posiiton in the array 

#include <bits/stdc++.h> 

struct Node {
    int index;
    Node* next;

    Node(int i) {
        index = i;
        next = NULL;
    }
};

class NStack
{
public:
    stack<int> st; // Empty Index
    int* arr; // oriignal Array
    Node **Top; // Top Element's index of particular index;

    // Initialize your data structure.
    NStack(int N, int S) // S is the size of Array and N is the number of stack
    {
        // Write your code here.
        arr = new int[S];
        Top = new Node*[N];

        for(int i = 0; i < N; i++) {
            Top[i] = NULL;
            for(int i = 0; i < S; i++) {
                st.push(i);
            }
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(st.empty()) {
            return 0;
        }

        arr[st.top()] = x;
        Node* temp = new Node(st.top());
        temp -> next = Top[m - 1];
        Top[m - 1] = temp;
        st.pop();
        return 1;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(Top[m - 1] == NULL) {
            return -1;
        }

        int element = arr[Top[m - 1] -> index];
        st.push(Top[m - 1] -> index);
        Top[m - 1] = Top[m - 1] -> next;
        return element;
    }
};