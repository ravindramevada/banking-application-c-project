#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0, i = 1001;

// structure declaration
struct BankAccount {
	char bank_name[25];
	char bank_branch[20];
	char account_holder_name[30];
	int account_number;
	char account_holder_address[100];
	float available_balance;
} account[51]; // array of structure

void display_options();
void create_new_account();
void cash_deposit();
void cash_withdraw();
void account_information();

// main function
int main() {
	int option;
	
	printf("Welcome to Banking Application!\n");
	
	while (1) {
		printf("Please select one from the following options:\n");
		display_options();
		
		printf("Enter the value: ");
		scanf("%d", &option);
		fgetc(stdin);
		
		printf("₹---------------------------------------------------------------------₹\n");
		
		switch (option) {
		    case 1:
				create_new_account();
				break;
		    case 2:
				cash_deposit();
				break;
		    case 3:
				cash_withdraw();
				break;
		    case 4:
				account_information();
				break;
		    case 5:
				printf("Thanks for banking with us!\n");
				return 0;
		    case 6:
				system("clear");
				break;
		    default:
				system("clear");
				printf("Please select only from the following options.\n");
				printf("₹---------------------------------------------------------------------₹\n");
				break;
	    }		  
	}
	return 0;
}

// function to display options
void display_options() {
	printf("1. Create a new account\n");
	printf("2. Cash deposit\n");
	printf("3. Cash withdraw\n");
	printf("4. Account information\n");
	printf("5. Log out\n");
	printf("6. Clear the screen and display options\n");
}

// function to create a new account
void create_new_account() {
	char bank_name[25];
	char bank_branch[20];
	char account_holder_name[30];
	int account_number;
	char account_holder_address[100];
	float available_balance = 0;
	
	printf("Enter the details to create a new account...\n");
	printf("Enter the bank name: ");
	fgets(bank_name, sizeof(bank_name), stdin);
	printf("Enter the bank branch: ");
	fgets(bank_branch, sizeof(bank_branch), stdin);
	printf("Enter the account holder name: ");
	fgets(account_holder_name, sizeof(account_holder_name), stdin);
	printf("Enter the account holder address: ");
	fgets(account_holder_address, sizeof(account_holder_address), stdin);
	printf("Minimum cash deposit is Rs. 500/-\n");
	account[n].available_balance = 500;
	printf("Your account number: %d\n", i);
	account[n].account_number = i;
	
	strcpy(account[n].bank_name, bank_name);
	strcpy(account[n].bank_branch, bank_branch);
	strcpy(account[n].account_holder_name, account_holder_name);
	strcpy(account[n].account_holder_address, account_holder_address);
	
	printf("Account has been created successfully!\n");
	printf("₹---------------------------------------------------------------------₹\n");
	printf("Here are the details...\n");
	printf("→ Bank name: %s", account[n].bank_name);
	printf("→ Bank branch: %s", account[n].bank_branch);
	printf("→ Account holder name: %s", account[n].account_holder_name);
	printf("→ Account number: %d\n", account[n].account_number);
	printf("→ Account holder address: %s", account[n].account_holder_address);
	printf("→ Account balance: %.2f/-\n", account[n].available_balance);
	printf("Thanks for banking with us!\n");
	printf("₹---------------------------------------------------------------------₹\n");
	
	n++;
	i++;
}

// function to deposit cash
void cash_deposit() {
	auto int account_number, amount, m = 0;
	
	printf("Enter the account number to deposit cash: ");
	scanf("%d", &account_number);
	
	for (int j = 0; j < 50; j++) {
		if (account[j].account_number == account_number) {
			m = j;
		}
	}
	if (account[m].account_number == account_number) {
		printf("→ The current balance for account %d is %.2f/-\n", account_number, account[m].available_balance);

		printf("Enter amount to deposit: ");
		scanf("%d", &amount);
		
		account[m].available_balance += amount;
		printf("→ The available balance for account %d is %.2f/-\n", account_number, account[m].available_balance);
		printf("₹---------------------------------------------------------------------₹\n");
	} else {
		printf("[Account number is invalid!]\n");
		printf("₹---------------------------------------------------------------------₹\n");
	}
}

// function to withdraw cash
void cash_withdraw() {
	auto int account_number, amount, m = 0;
	
	printf("Enter the account number to withdraw cash: ");
	scanf("%d", &account_number);
	
	for (int j = 0; j < 50; j++) {
		if (account[j].account_number == account_number) {
			m = j;
		}
	}
	if (account[m].account_number == account_number) {
		printf("→ The current balance for account %d is %.2f/-\n", m, account[m].available_balance);

		printf("Enter amount to withdraw: ");
		scanf("%d", &amount);
		
		if (account[m].available_balance < (500 + amount)) {
			printf("[Insufficient balance!]\n");
     		printf("₹---------------------------------------------------------------------₹\n");
		} else {
			account[m].available_balance -= amount;
			printf("→ The available balance for account %d is %.2f/-\n", n, account[m].available_balance);
			printf("₹---------------------------------------------------------------------₹\n");
		}
	} else {
		printf("[Account number is invalid!]\n");
		printf("₹---------------------------------------------------------------------₹\n");
	}
}

// function to display account information
void account_information() {
    auto int account_number, m = 0;
	
	printf("Enter the account number to get information: ");
	scanf("%d", &account_number);
	
	for (int j = 0; j < 50; j++) {
		if (account[j].account_number == account_number) {
			m = j;
		}
	}
	if (account[m].account_number == account_number) {
		printf("Here are the details...\n");
		printf("→ Bank name: %s", account[m].bank_name);
		printf("→ Bank branch: %s", account[m].bank_branch);
		printf("→ Account holder name: %s", account[m].account_holder_name);
		printf("→ Account number: %d\n", account[m].account_number);
		printf("→ Account holder address: %s", account[m].account_holder_address);
		printf("→ Account balance: %.2f/-\n", account[m].available_balance);
		printf("₹---------------------------------------------------------------------₹\n");
		n++;
	} else {
		printf("[Account number is invalid!]\n");
		printf("₹---------------------------------------------------------------------₹\n");
	}
}