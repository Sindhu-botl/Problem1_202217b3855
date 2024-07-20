#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
 
// Function declarations
void create();
void insert();
void delete();
void search();
void display();
void exitProgram();
 
// Global variables
int list[MAX];
int count = 0;
 
int main() {
    int choice;
    char cont = 'y';
 
    while (cont == 'y' || cont == 'Y') {
        printf("Main Menu\n");
        printf("1. Create\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Insert\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exitProgram();
                break;
            default:
                printf("Invalid Choice!\n");
        }
 
        printf("Do u want to continue? (y/n): ");
        scanf(" %c", &cont); // note the space before %c to consume any leftover newline character
    }
 
    return 0;
}
 
void create() {
    int n, i;
    if (count > 0) {
        printf("List already created!\n");
        return;
    }
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Number of nodes exceeds maximum limit!\n");
        return;
    }
    count = n;
    for (i = 0; i < n; i++) {
        printf("Enter the Element: ");
        scanf("%d", &list[i]);
    }
}
 
void insert() {
    int pos, elem, i;
    if (count == MAX) {
        printf("List is full!\n");
        return;
    }
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > count) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter the Element: ");
    scanf("%d", &elem);
    for (i = count; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = elem;
    count++;
}
 
void delete() {
    int pos, i;
    if (count == 0) {
        printf("List is empty!\n");
        return;
    }
    printf("Enter the position u want to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= count) {
        printf("Invalid position!\n");
        return;
    }
    for (i = pos; i < count - 1; i++) {
        list[i] = list[i + 1];
    }
    count--;
}
 
void search() {
    int elem, i;
    printf("Enter the element to search: ");
    scanf("%d", &elem);
    for (i = 0; i < count; i++) {
        if (list[i] == elem) {
            printf("Element %d found at position %d\n", elem, i);
            return;
        }
    }
    printf("Element %d not found in the list\n", elem);
}
 
void display() {
    int i;
    if (count == 0) {
        printf("The list is empty\n");
        return;
    }
    printf("The Elements of The list ADT are:\n");
    for (i = 0; i < count; i++) {
        printf("%d\n", list[i]);
    }
}
 
void exitProgram() {
    printf("Exiting the program...\n");
    exit(0);
}