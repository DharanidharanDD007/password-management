#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

// Structure to hold account information
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

// Function prototypes
void addAccount(Account accounts[], int *count);
void displayAccounts(Account accounts[], int count);
void saveAccounts(Account accounts[], int count);
void loadAccounts(Account accounts[], int *count);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    loadAccounts(accounts, &count);

    do {
        printf("\nPassword Manager System\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Save Accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accounts, &count);
                break;
            case 2:
                displayAccounts(accounts, count);
                break;
            case 3:
                saveAccounts(accounts, count);
                break;
            case 4:
                saveAccounts(accounts, count);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addAccount(Account accounts[], int *count) {
    if (*count < MAX_ACCOUNTS) {
        printf("Enter username: ");
        scanf("%s", accounts[*count].username);
        printf("Enter password: ");
        scanf("%s", accounts[*count].password);
        (*count)++;
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void displayAccounts(Account accounts[], int count) {
    printf("\nAccounts:\n");
    for (int i = 0; i < count; i++) {
        printf("Username: %s, Password: %s\n", accounts[i].username, accounts[i].password);
    }
}

void saveAccounts(Account accounts[], int count) {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", accounts[i].username, accounts[i].password);
    }

    fclose(file);
}

void loadAccounts(Account accounts[], int *count) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("File does not exist. Creating new file.\n");
        return;
    }

    while ((*count < MAX_ACCOUNTS) && (fscanf(file, "%s %s", accounts[*count].username, accounts[*count].password) != EOF)) {
        (*count)++;
    }

    fclose(file);
}