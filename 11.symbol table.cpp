#include <stdio.h>
#include <string.h>

#define MAX 50

struct Symbol {
    char name[20];
    char type[20];
    int address;
};

struct Symbol table[MAX];
int count = 0;

/* Insert a symbol */
void insert() {
    if (count >= MAX) {
        printf("Symbol Table is Full!\n");
        return;
    }

    struct Symbol s;
    printf("Enter Symbol Name: ");
    scanf("%s", s.name);

    // Check duplicate
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, s.name) == 0) {
            printf("Symbol already exists!\n");
            return;
        }
    }

    printf("Enter Symbol Type: ");
    scanf("%s", s.type);

    printf("Enter Address: ");
    scanf("%d", &s.address);

    table[count++] = s;
    printf("Symbol inserted successfully.\n");
}

/* Search a symbol */
void search() {
    char name[20];
    printf("Enter Symbol Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol Found!\n");
            printf("Name: %s\nType: %s\nAddress: %d\n",
                   table[i].name, table[i].type, table[i].address);
            return;
        }
    }
    printf("Symbol not found.\n");
}

/* Modify a symbol */
void modify() {
    char name[20];
    printf("Enter Symbol Name to modify: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Enter New Type: ");
            scanf("%s", table[i].type);
            printf("Enter New Address: ");
            scanf("%d", &table[i].address);
            printf("Symbol modified successfully.\n");
            return;
        }
    }
    printf("Symbol not found.\n");
}

/* Display Symbol Table */
void display() {
    if (count == 0) {
        printf("Symbol Table is empty.\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("-------------------------------------------------\n");
    printf("Name\t\tType\t\tAddress\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%d\n",
               table[i].name, table[i].type, table[i].address);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Symbol Table Operations ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: modify(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
