from datetime import datetime

# Transaction class
class Transaction:
    def __init__(self, amount, transaction_type, timestamp=None):
        self.amount = amount
        self.type = transaction_type  # "deposit" or "withdrawal"
        self.timestamp = timestamp if timestamp else datetime.now().strftime("%Y-%m-%d %H:%M:%S")

# Farmer class
class Farmer:
    def __init__(self, farmer_id):
        self.farmer_id = farmer_id
        self.balance = 0.0
        self.transactions = []

    def deposit(self, amount):
        self.balance += amount
        transaction = Transaction(amount, "deposit")
        self.transactions.append(transaction)
        print("  Deposit successful!")

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            transaction = Transaction(amount, "withdrawal")
            self.transactions.append(transaction)
            print("  Withdrawal successful!")
            return True
        else:
            print("  Insufficient funds!")
            return False

    def check_balance(self):
        print(f"Your balance is: {self.balance:.2f}")

    def print_statement(self, n):
        print(f"Last {n} transaction(s):")
        for transaction in self.transactions[-n:]:
            print(f"Amount: {transaction.amount:.2f}, Type: {transaction.type}, Timestamp: {transaction.timestamp}")

# SACCO Management System
class SaccoManagementSystem:
    def __init__(self):
        self.farmers = {}

    def find_or_create_farmer(self, farmer_id):
        if farmer_id not in self.farmers:
            self.farmers[farmer_id] = Farmer(farmer_id)
        return self.farmers[farmer_id]

    def show_menu(self):
        print("\n SACCO MANAGEMENT SYSTEM ")
        print("  1. Check Balance")
        print("  2. Deposit Money")
        print("  3. Withdraw Money")
        print("  4. Get Transaction Statement")
        print("  5. Exit")
        return input("  Enter your best option: ")

# Main application
def main():
    system = SaccoManagementSystem()

    while True:
        try:
            farmer_id = int(input("\n  ENTER YOUR FARMER ID: "))
            break
        except ValueError:
            print("  Please enter a valid numeric ID.")

    farmer = system.find_or_create_farmer(farmer_id)

    while True:
        choice = system.show_menu()

        if choice == "1":
            farmer.check_balance()

        elif choice == "2":
            try:
                amount = float(input("  Enter amount to deposit: "))
                farmer.deposit(amount)
            except ValueError:
                print("  Invalid input. Please enter a numeric amount.")

        elif choice == "3":
            try:
                amount = float(input("  Enter amount to withdraw: "))
                farmer.withdraw(amount)
            except ValueError:
                print("  Invalid input. Please enter a numeric amount.")

        elif choice == "4":
            try:
                n = int(input("  Enter number of transactions to display: "))
                farmer.print_statement(n)
            except ValueError:
                print("  Invalid number.")

        elif choice == "5":
            print("  Exiting the system.")
            break

        else:
            print("  Invalid choice, please try again.")

if __name__ == "__main__":
    main()
