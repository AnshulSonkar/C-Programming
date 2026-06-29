// Contact Book 
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Required structure definition
// struct Contact
// {
//     char name[50];
//     char phone[15];
// };

// // Function prototypes
// void addContact(const char *filename);
// void searchContact(const char *filename);
// void deleteContact(const char *filename);
// void updateContact(const char *filename);

// int main() 
// {
//     const char *dbFile = "contacts.txt";
//     int choice;

//     while (1) 
//     {
//         printf("\n=== CONTACT BOOK ===\n");
//         printf("1. Add Contact\n");
//         printf("2. Search Contact\n");
//         printf("3. Delete Contact\n");
//         printf("4. Update Contact\n");
//         printf("5. Exit\n");
//         printf("Enter your choice (1-5): ");
        
//         if (scanf("%d", &choice) != 1) 
//         {
//             printf("Invalid input! Please enter a valid menu number.\n");
//             while (getchar() != '\n'); // Clear incorrect input from buffer
//             continue;
//         }

//         switch (choice) 
//         {
//             case 1: addContact(dbFile); break;
//             case 2: searchContact(dbFile); break;
//             case 3: deleteContact(dbFile); break;
//             case 4: updateContact(dbFile); break;
//             case 5: printf("Closing Contact Book. Goodbye!\n"); exit(0);
//             default: printf("Invalid option! Please pick a number from 1 to 5.\n");
//         }
//     }
//     return 0;
// }

// // 1. Add Contact Feature
// void addContact(const char *filename) 
// {
//     FILE *fp = fopen(filename, "a");
//     if (fp == NULL) 
//     {
//         printf("Error: Could not open database file!\n");
//         return;
//     }

//     struct Contact person;
//     printf("\nEnter Contact Name (use_underscores_for_spaces): ");
//     scanf("%49s", person.name);

//     // Duplicate check using string comparison
//     FILE *chk = fopen(filename, "r");
//     if (chk != NULL) 
//     {
//         struct Contact temp;
//         while (fscanf(chk, "%49s %14s", temp.name, temp.phone) != EOF) 
//         {
//             if (strcmp(temp.name, person.name) == 0) 
//             {
//                 printf("Error: A contact named '%s' already exists!\n", person.name);
//                 fclose(chk);
//                 fclose(fp);
//                 return;
//             }
//         }
//         fclose(chk);
//     }

//     printf("Enter Phone Number: ");
//     scanf("%14s", person.phone);

//     // Store record neatly inside contacts.txt
//     fprintf(fp, "%s %s\n", person.name, person.phone);
//     fclose(fp);
    
//     printf("Contact saved successfully!\n");
// }

// // 2. Search Contact Feature
// void searchContact(const char *filename) 
// {
//     FILE *fp = fopen(filename, "r");
//     if (fp == NULL) 
//     {
//         printf("Your contact book is empty.\n");
//         return;
//     }

//     char targetName[50];
//     int found = 0;
//     struct Contact person;

//     printf("\nEnter Name to search: ");
//     scanf("%49s", targetName);

//     // Loop and search using string comparison (strcmp)
//     while (fscanf(fp, "%49s %14s", person.name, person.phone) != EOF) 
//     {
//         if (strcmp(person.name, targetName) == 0) 
//         {
//             printf("\n--- Contact Found ---\n");
//             printf("Name : %s\n", person.name);
//             printf("Phone: %s\n", person.phone);
//             found = 1;
//             break;
//         }
//     }

//     fclose(fp);
//     if (!found) 
//     {
//         printf("Contact '%s' not found in records.\n", targetName);
//     }
// }

// // 3. Delete Contact Feature
// void deleteContact(const char *filename) 
// {
//     FILE *fp = fopen(filename, "r");
//     FILE *tempFp = fopen("temp_contacts.txt", "w");
//     if (fp == NULL || tempFp == NULL) 
//     {
//         printf("Database error or empty file system!\n");
//         if (fp) fclose(fp);
//         if (tempFp) fclose(tempFp);
//         return;
//     }

//     char targetName[50];
//     int found = 0;
//     struct Contact person;

//     printf("\nEnter Contact Name to Delete: ");
//     scanf("%49s", targetName);

//     while (fscanf(fp, "%49s %14s", person.name, person.phone) != EOF) 
//     {
//         if (strcmp(person.name, targetName) == 0) 
//         {
//             found = 1; // Match found, skip writing it to copy file
//             printf("Contact '%s' has been deleted successfully.\n", person.name);
//         } 
//         else 
//         {
//             fprintf(tempFp, "%s %s\n", person.name, person.phone);
//         }
//     }

//     fclose(fp);
//     fclose(tempFp);

//     // Delete old file and replace it with updated copy
//     remove(filename);
//     rename("temp_contacts.txt", filename);

//     if (!found) 
//     {
//         printf("No contact named '%s' was found.\n", targetName);
//     }
// }

// // 4. Update Contact Feature
// void updateContact(const char *filename) 
// {
//     FILE *fp = fopen(filename, "r");
//     FILE *tempFp = fopen("temp_contacts.txt", "w");
//     if (fp == NULL || tempFp == NULL) 
//     {
//         printf("Database error or empty file system!\n");
//         if (fp) fclose(fp);
//         if (tempFp) fclose(tempFp);
//         return;
//     }

//     char targetName[50];
//     int found = 0;
//     struct Contact person;

//     printf("\nEnter Contact Name to Update: ");
//     scanf("%49s", targetName);

//     while (fscanf(fp, "%49s %14s", person.name, person.phone) != EOF) 
//     {
//         if (strcmp(person.name, targetName) == 0) 
//         {
//             found = 1;
//             printf("Current Details -> Name: %s | Phone: %s\n", person.name, person.phone);
//             printf("Enter New Phone Number: ");
//             scanf("%14s", person.phone);
//             printf("Phone number updated successfully!\n");
//         }
//         fprintf(tempFp, "%s %s\n", person.name, person.phone);
//     }

//     fclose(fp);
//     fclose(tempFp);

//     remove(filename);
//     rename("temp_contacts.txt", filename);

//     if (!found) 
//     {
//         printf("No contact named '%s' was found.\n", targetName);
//     }
// }


