// Bank Management System
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Fixed structure definition with char array for name
// struct Account
// {
//     int accNo;
//     char name[50]; 
//     float balance;
// };

// // Function prototypes
// void createAccount();
// void depositMoney();
// void withdrawMoney();
// void checkBalance();
// void deleteAccount();

// const char *FILENAME = "accounts.txt";

// int main() 
// {
//     int choice;
    
//     while (1) 
//     {
//         printf("\n=== BANK MANAGEMENT SYSTEM ===\n");
//         printf("1. Create Account\n");
//         printf("2. Deposit\n");
//         printf("3. Withdraw\n");
//         printf("4. Check Balance\n");
//         printf("5. Delete Account\n");
//         printf("6. Exit\n");
//         printf("Enter your choice (1-6): ");
        
//         if (scanf("%d", &choice) != 1) 
//         {
//             printf("Invalid input! Please enter a number.\n");
//             while (getchar() != '\n'); // Clear input buffer
//             continue;
//         }

//         switch (choice) 
//         {
//             case 1: createAccount(); break;
//             case 2: depositMoney(); break;
//             case 3: withdrawMoney(); break;
//             case 4: checkBalance(); break;
//             case 5: deleteAccount(); break;
//             case 6: printf("Thank you for using our banking system!\n"); exit(0);
//             default: printf("Invalid choice! Please try again.\n");
//         }
//     }
//     return 0;
// }

// // 1. Create Account Feature
// void createAccount() 
// {
//     FILE *fp = fopen(FILENAME, "a");
//     if (fp == NULL) 
//     {
//         printf("Error opening database file!\n");
//         return;
//     }

//     struct Account acc;
//     printf("\nEnter Account Number: ");
//     scanf("%d", &acc.accNo);
    
//     // Check if account number already exists
//     FILE *chk = fopen(FILENAME, "r");
//     if (chk != NULL) 
//     {
//         struct Account temp;
//         while (fscanf(chk, "%d %49s %f", &temp.accNo, temp.name, &temp.balance) != EOF) 
//         {
//             if (temp.accNo == acc.accNo) 
//             {
//                 printf("Error: Account number %d already exists!\n", acc.accNo);
//                 fclose(chk);
//                 fclose(fp);
//                 return;
//             }
//         }
//         fclose(chk);
//     }

//     printf("Enter Account Holder Name (no spaces): ");
//     scanf("%49s", acc.name);
//     printf("Enter Initial Deposit Balance: ");
//     scanf("%f", &acc.balance);

//     // Save structured data cleanly in accounts.txt
//     fprintf(fp, "%d %s %.2f\n", acc.accNo, acc.name, acc.balance);
//     fclose(fp);
    
//     printf("Account created successfully!\n");
// }

// // 2. Deposit Feature
// void depositMoney() 
// {
//     FILE *fp = fopen(FILENAME, "r");
//     FILE *tempFp = fopen("temp.txt", "w");
//     if (fp == NULL || tempFp == NULL) 
//     {
//         printf("Database file is empty or cannot be opened!\n");
//         if (fp) fclose(fp);
//         if (tempFp) fclose(tempFp);
//         return;
//     }

//     int targetAccNo, found = 0;
//     float amount;
//     struct Account acc;

//     printf("\nEnter Account Number for Deposit: ");
//     scanf("%d", &targetAccNo);

//     while (fscanf(fp, "%d %49s %f", &acc.accNo, acc.name, &acc.balance) != EOF) 
//     {
//         if (acc.accNo == targetAccNo) 
//         {
//             found = 1;
//             printf("Current Account Details: ID: %d | Name: %s | Balance: %.2f\n", acc.accNo, acc.name, acc.balance);
//             printf("Enter Amount to Deposit: ");
//             scanf("%f", &amount);
//             if (amount <= 0) 
//             {
//                 printf("Invalid deposit amount!\n");
//             } 
//             else 
//             {
//                 acc.balance += amount;
//                 printf("Deposit successful! New Balance: %.2f\n", acc.balance);
//             }
//         }
//         fprintf(tempFp, "%d %s %.2f\n", acc.accNo, acc.name, acc.balance);
//     }

//     fclose(fp);
//     fclose(tempFp);

//     remove(FILENAME);
//     rename("temp.txt", FILENAME);

//     if (!found) 
//     {
//         printf("Account number %d not found.\n", targetAccNo);
//     }
// }

// // 3. Withdraw Feature
// void withdrawMoney() 
// {
//     FILE *fp = fopen(FILENAME, "r");
//     FILE *tempFp = fopen("temp.txt", "w");
//     if (fp == NULL || tempFp == NULL) 
//     {
//         printf("Database file is empty or cannot be opened!\n");
//         if (fp) fclose(fp);
//         if (tempFp) fclose(tempFp);
//         return;
//     }

//     int targetAccNo, found = 0;
//     float amount;
//     struct Account acc;

//     printf("\nEnter Account Number for Withdrawal: ");
//     scanf("%d", &targetAccNo);

//     while (fscanf(fp, "%d %49s %f", &acc.accNo, acc.name, &acc.balance) != EOF) 
//     {
//         if (acc.accNo == targetAccNo) 
//         {
//             found = 1;
//             printf("Current Account Details: ID: %d | Name: %s | Balance: %.2f\n", acc.accNo, acc.name, acc.balance);
//             printf("Enter Amount to Withdraw: ");
//             scanf("%f", &amount);
//             if (amount > acc.balance) 
//             {
//                 printf("Insufficient Funds! Withdrawal failed.\n");
//             } 
//             else if (amount <= 0) 
//             {
//                 printf("Invalid withdrawal amount!\n");
//             } 
//             else 
//             {
//                 acc.balance -= amount;
//                 printf("Withdrawal successful! New Balance: %.2f\n", acc.balance);
//             }
//         }
//         fprintf(tempFp, "%d %s %.2f\n", acc.accNo, acc.name, acc.balance);
//     }

//     fclose(fp);
//     fclose(tempFp);

//     remove(FILENAME);
//     rename("temp.txt", FILENAME);

//     if (!found) 
//     {
//         printf("Account number %d not found.\n", targetAccNo);
//     }
// }

// // 4. Check Balance Feature
// void checkBalance() 
// {
//     FILE *fp = fopen(FILENAME, "r");
//     if (fp == NULL) 
//     {
//         printf("Database file is empty or cannot be opened!\n");
//         return;
//     }

//     int targetAccNo, found = 0;
//     struct Account acc;

//     printf("\nEnter Account Number: ");
//     scanf("%d", &targetAccNo);

//     while (fscanf(fp, "%d %49s %f", &acc.accNo, acc.name, &acc.balance) != EOF) 
//     {
//         if (acc.accNo == targetAccNo) 
//         {
//             printf("\n--- ACCOUNT DETAILS ---\n");
//             printf("Account Number : %d\n", acc.accNo);
//             printf("Account Holder : %s\n", acc.name);
//             printf("Current Balance: %.2f\n", acc.balance);
//             found = 1;
//             break;
//         }
//     }

//     fclose(fp);
//     if (!found) 
//     {
//         printf("Account number %d not found.\n", targetAccNo);
//     }
// }

// // 5. Delete Account Feature
// void deleteAccount() 
// {
//     FILE *fp = fopen(FILENAME, "r");
//     FILE *tempFp = fopen("temp.txt", "w");
//     if (fp == NULL || tempFp == NULL) 
//     {
//         printf("Database file is empty or cannot be opened!\n");
//         if (fp) fclose(fp);
//         if (tempFp) fclose(tempFp);
//         return;
//     }

//     int targetAccNo, found = 0;
//     struct Account acc;

//     printf("\nEnter Account Number to Delete: ");
//     scanf("%d", &targetAccNo);

//     while (fscanf(fp, "%d %49s %f", &acc.accNo, acc.name, &acc.balance) != EOF) 
//     {
//         if (acc.accNo == targetAccNo) 
//         {
//             found = 1; 
//             printf("Account %d held by %s has been deleted.\n", acc.accNo, acc.name);
//         } 
//         else 
//         {
//             fprintf(tempFp, "%d %s %.2f\n", acc.accNo, acc.name, acc.balance);
//         }
//     }

//     fclose(fp);
//     fclose(tempFp);

//     remove(FILENAME);
//     rename("temp.txt", FILENAME);

//     if (!found) 
//     {
//         printf("Account number %d not found.\n", targetAccNo);
//     }
// } 
