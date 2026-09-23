#include<iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() {
        top = 0;
    }

    bool isFull() {
        return top == MAX;
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(int value) {
        if(isFull()){
            cout << "Stack Overflow! " << value << endl;
            return;
        }
        arr[top] = value;
        top++;
        cout << value << " pushed to stack" << endl;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        top--; 
        int poppedValue = arr[top];
        return poppedValue;
    }

    int peek() {
        if(isEmpty()){ 
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top-1];
    }

    void display() { 
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for(int i = top - 1; i >= 0; i--) { 
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10); 
    s.push(20);
    s.push(30);
    
    s.display(); 

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;

    s.display();

    s.pop();
    s.pop();
    s.pop();

    return 0;
}