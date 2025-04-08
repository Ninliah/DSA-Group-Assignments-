#include <iostream>
using namespace std;
#define MAX 5

class Stack {
    int TOP;
    int arr[MAX];

public:
    Stack() {
        TOP = -1;
    }

    void push(int x) {
        if (TOP == MAX - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            TOP = TOP + 1;
            arr[TOP] = x;
        }
    }

    int pop() {
        if (TOP == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = arr[TOP];
        TOP = TOP - 1;
        return val;
    }

    int peek() {
        if (TOP == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            return arr[TOP];
        }
    }

    void printStack() const {
        if (TOP == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= TOP; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            value = s.pop();
            if (value != -1)
                cout << "Popped: " << value << endl;
            break;
        case 3:
            value = s.peek();
            if (value != -1)
                cout << "Top element: " << value << endl;
            break;
        case 4:
            s.printStack();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
