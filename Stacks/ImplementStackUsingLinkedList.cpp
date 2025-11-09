// Implementing Stack Using Linked List 

class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int x) {
        data = x;
    }
};

class Stack {
    public:
    Node* top;
    int size;
    public:
    Stack(int sizee) {
        size = sizee;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp -> next = top;
        top = temp;
        size = size + 1;
    }
};

int main() {
    Stack st(5);

}