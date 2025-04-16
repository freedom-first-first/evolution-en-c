//main.c file 
#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    list user_list = NULL; // Initialize the list properly
int choice;
float user_float[7];

do {
    printf("\nMenu:\n");
    printf("1. Add a new set of 7 floats to the list\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Exiting program.\n");
        break;
    }

    switch (choice) {
        case 1:
            printf("Enter 7 float values:\n");
            for (int i = 0; i < 7; i++) {
                printf("Enter float[%d]: ", i + 1);
                scanf("%f", &user_float[i]);
            }
            user_list = push(user_list, user_float);
            break;

        case 2:
            printf("\nDisplaying the list:\n");
            display(user_list);
            break;

        case 3:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != 3);

free_list(user_list); // Free the memory allocated for the list

return 0;
}