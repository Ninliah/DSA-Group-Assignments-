#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMESTAMP_LENGTH 20

// Structure to represent a Transaction
typedef struct Transaction {
    double amount;
    char type[10]; // "deposit" or "withdrawal"
    char timestamp[MAX_TIMESTAMP_LENGTH];
    struct Transaction* next;
} Transaction;

// Structure to represent a Linked List for storing transactions
typedef struct LinkedList {
    Transaction* head;
} LinkedList;

// Structure to represent a Farmer
typedef struct Farmer {
    int farmerID;
    double balance;
    LinkedList* transactions;
} Farmer;

// Structure to represent the Sacco Management System
typedef struct SaccoManagementSystem {
    Farmer* farmers[1000];  // Array of pointers to farmers (using a simple array for demo)
} SaccoManagementSystem;

// Function to create a new transaction
Transaction* createTransaction(double amount, const char* type, const char* timestamp) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    newTransaction->amount = amount;
    strcpy(newTransaction->type, type);
    strcpy(newTransaction->timestamp, timestamp);
    newTransaction->next = NULL;
    return newTransaction;
}

// Function to create a new linked list of transactions
LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    return newList;
}

// Function to append a transaction to the linked list
void appendTransaction(LinkedList* list, Transaction* newTransaction) {
    if (list->head == NULL) {
        list->head = newTransaction;
    } else {
        Transaction* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTransaction;
    }
}

// Function to create a new farmer
Farmer* createFarmer(int id) {
    Farmer* newFarmer = (Farmer*)malloc(sizeof(Farmer));
    newFarmer->farmerID = id;
    newFarmer->balance = 0.0;
    newFarmer->transactions = createLinkedList();
    return newFarmer;
}

// Function to deposit money for a farmer
void deposit(Farmer* farmer, double amount) {
    farmer->balance += amount;
    Transaction* newTransaction = createTransaction(amount, "deposit", "2025-04-02 12:01:30");
    appendTransaction(farmer->transactions, newTransaction);
}

// Function to withdraw money for a farmer
int withdraw(Farmer* farmer, double amount) {
    if (farmer->balance >= amount) {
        farmer->balance -= amount;
        Transaction* newTransaction = createTransaction(amount, "withdrawal", "2025-04-02 12:01:30");
        appendTransaction(farmer->transactions, newTransaction);
        return 1;  // Successful withdrawal
    }
    return 0;  // Insufficient funds
}

// Function to check balance of a farmer
double checkBalance(Farmer* farmer) {
    return farmer->balance;
}

// Function to print the transaction statement of a farmer
void printStatement(Farmer* farmer, int n) {
    Transaction* temp = farmer->transactions->head;
    int count = 0;
    while (temp != NULL && count < n) {
        printf("Amount: %.2f, Type: %d, Timestamp: %s\n", temp->amount, temp->type, temp->timestamp);
        temp = temp->next;
        count++;
    }
}

// Function to show the menu to the user
void showMenu() {
    printf("\n SACCO MANAGEMENT SYSTEM \n");
    printf("  1. Check Balance\n");
    printf("  2. Deposit Money\n");
    printf("  3. Withdraw Money\n");
    printf("  4. Get Transaction Statement\n");
    printf("  5. Exit\n");
    printf("  Enter your Best option: ");
}

// Function to find or create a farmer in the system
Farmer* findOrCreateFarmer(SaccoManagementSystem* system, int farmerID) {
    for (int i = 0; i < 1000; i++) {
        if (system->farmers[i] && system->farmers[i]->farmerID == farmerID) {
            return system->farmers[i];
        }
    }
    // Farmer not found, create a new one
    Farmer* newFarmer = createFarmer(farmerID);
    for (int i = 0; i < 1000; i++) {
        if (system->farmers[i] == NULL) {
            system->farmers[i] = newFarmer;
            return newFarmer;
        }
    }
    return NULL;  // System is full (which should not happen in this simple case)
}

int main() {
    SaccoManagementSystem sacco;
    memset(&sacco, 0, sizeof(sacco));  // Initialize all farmer slots to NULL
    int farmerID, option;
    double amount;
    int n;

    printf("\n  ENTER YOUR FARMER ID: ");
    scanf("%d", &farmerID);

    Farmer* farmer = findOrCreateFarmer(&sacco, farmerID);

    while (1) {
        showMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Check Balance
                printf("Your balance is: %.2f\n", checkBalance(farmer));
                break;
            case 2:
                // Deposit Money
                printf("  Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(farmer, amount);
                printf("  Deposit successful!\n");
                break;
            case 3:
                // Withdraw Money
                printf("  Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (withdraw(farmer, amount)) {
                    printf("  Withdrawal successful!\n");
                } else {
                    printf("  Insufficient funds!\n");
                }
                break;
            case 4:
                // Get Transaction Statement
                printf("  Enter number of transactions to display: ");
                scanf("%d", &n);
                printStatement(farmer, n);
                break;
            case 5:
                // Exit
                printf("  Exiting the system.\n");
                return 0;
            default:
                printf("  Invalid choice, please try again.\n");
        }
    }

    return 0;
}
