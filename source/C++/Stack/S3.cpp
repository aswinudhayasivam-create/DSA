#include<iostream>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    
public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newnode = new Node();
        if(newnode == nullptr) {
            cout << "Overflow!" << endl;
            return;
        }

        newnode->data = value;
        newnode->next = top;

        top = newnode; 

        cout << value << " Pushed into Stack" << endl;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        Node* temp = top;
        int poppedvalue = temp->data;
        top = top->next;
        
        delete temp; 

        return poppedvalue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data; 
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack: ";
        Node* current = top;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.Display();

    cout << "The top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.Display();

    return 0;
}