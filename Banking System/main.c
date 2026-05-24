#include <stdio.h>
#include <string.h>

// Banking System.
// A small in-memory bank. You can open accounts, deposit and withdraw money,
// and check a balance. Each account is stored in a struct, which is a neat
// way to keep related pieces of data (name, number, balance) together.

#define MAX_ACCOUNTS 100

struct account
{
    int number;
    char name[50];
    double balance;
};

struct account accounts[MAX_ACCOUNTS];
int account_count = 0;

// find the position of an account by its number, or -1 if it does not exist
int find_account(int number)
{
    for (int i = 0; i < account_count; i++)
    {
        if (accounts[i].number == number)
        {
            return i;
        }
    }
    return -1;
}

void create_account()
{
    if (account_count >= MAX_ACCOUNTS)
    {
        printf("\nThe bank is full, cannot open more accounts.\n");
        return;
    }

    struct account new_account;
    new_account.number = 1000 + account_count; // simple unique account number
    new_account.balance = 0;

    printf("Enter the account holder's name: ");
    getchar(); // clear the leftover newline
    fgets(new_account.name, sizeof(new_account.name), stdin);
    new_account.name[strcspn(new_account.name, "\n")] = '\0';

    accounts[account_count] = new_account;
    account_count++;

    printf("Account created. Your account number is %d.\n", new_account.number);
}

void deposit()
{
    int number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &number);

    int index = find_account(number);
    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0)
    {
        printf("Deposit must be more than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposited. New balance: %.2lf\n", accounts[index].balance);
}

void withdraw()
{
    int number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &number);

    int index = find_account(number);
    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0)
    {
        printf("Withdrawal must be more than zero.\n");
        return;
    }

    if (amount > accounts[index].balance)
    {
        printf("Not enough money in the account.\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawn. New balance: %.2lf\n", accounts[index].balance);
}

void check_balance()
{
    int number;

    printf("Enter account number: ");
    scanf("%d", &number);

    int index = find_account(number);
    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Account holder: %s\n", accounts[index].name);
    printf("Balance: %.2lf\n", accounts[index].balance);
}

int main()
{
    int choice;

    printf("\n. . . . . SIMPLE BANKING SYSTEM . . . . .\n");

    while (1)
    {
        printf("\n1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nGoodbye!\n");
            break;
        }

        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            printf("\nThanks for banking with us. Goodbye!\n");
            return 0;
        default:
            printf("Please pick a number between 1 and 5.\n");
        }
    }

    return 0;
}
