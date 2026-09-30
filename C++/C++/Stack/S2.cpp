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

    void push(int x) {
        if(!isFull()) {
            arr[top] = x;
            top++;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void display() {
        for(int i = 0; i < top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void displayOdd() {
        for(int i = 0; i < top; i++) {
            if(arr[i] % 2 != 0) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void displayEven() {
        for(int i = 0; i < top; i++) {
            if(arr[i] % 2 == 0) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void pop() {
        if(!isEmpty()) {
            top--;
        } else {
            cout << "Stack Underflow!" << endl;
        }
    }
};

int main() {
    Stack s;

    int n;
    cout << "Enter the number of elements to push: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cout << "Enter element " << i + 1 << ": ";
        cin >> x;
        s.push(x);
    }

    cout << "All elements: ";
    s.display();

    cout << "Odd elements: ";
    s.displayOdd();

    cout << "Even elements: ";
    s.displayEven();

    return 0;
}