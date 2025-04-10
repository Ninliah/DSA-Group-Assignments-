#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class Stack {

    int TOP;
    string arr[MAX];

public:
    Stack() {
        TOP = -1; // Initialize the stack as empty
    }

    // Push operation
    void push(const string& word) {
        if (TOP == MAX - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            TOP = TOP + 1;
            arr[TOP] = word;
            cout << word << " pushed onto stack." << endl;
        }
    }

    // Pop operation
    string pop() {
        if (TOP == -1) {
            cout << "Stack Underflow" << endl;
            return "";
        }
        string val = arr[TOP];
        TOP = TOP - 1;
        return val;
    }

    // Peek operation
    string peek() {
        if (TOP == -1) {
            cout << "Stack Underflow" << endl;
            return "";
        } else {
            return arr[TOP];
        }
    }

    // Print all elements in the stack
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
    int choice;
    string word;

    // Menu loop
    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after entering choice

        switch (choice) {
        case 1:
            cout << "Enter word to push: ";
            getline(cin, word);
            s.push(word);
            break;
        case 2:
            word = s.pop();
            if (!word.empty())
                cout << "Popped: " << word << endl;
            break;
        case 3:
            word = s.peek();
            if (!word.empty())
                cout << "Top element: " << word << endl;
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
    } while (choice != 5);  // Repeat the menu until choice 5 is selected to exit

    return 0;
}
