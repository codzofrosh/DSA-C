#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *prev = NULL;

// Function prototypes
void create_linkedList();
void print_linkedList();
void addElement();
void insertBeginning();
void insertEnd();
void insertMiddle();
void deleteElement();
void deleteBeginning();
void deleteEnd();
void deleteMiddle();
void deletebyElement();
int listSize();

// Create a linked list
void create_linkedList() {
    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    char choice;
    do{
    printf("Enter data to continue: ");
    scanf("%d", &nodeInstance->data);
    nodeInstance->next = NULL;

    if (head != NULL) {
        prev->next = nodeInstance;
    } else {
        head = nodeInstance;
    }
    prev = nodeInstance;

    printf("Add another element (Y/N): ");
    scanf(" %c", &choice);
    }while(choice=="y"||choice == 'Y');
}
// Print the linked list
void print_linkedList() {
    struct node *nodeInstance = head;

    if (head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (nodeInstance != NULL) {
        printf("%d -> ", nodeInstance->data);
        nodeInstance = nodeInstance->next;
    }
    printf("NULL\n");
}

// Add element menu
void addElement() {
    int choice;
    printf("\nEnter where you want to add an element:\n");
    printf("1. Beginning\n2. In Middle by Position\n3. At End\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertBeginning();
            break;
        case 2:
            insertMiddle();
            break;
        case 3:
            insertEnd();
            break;
        default:
            printf("Invalid choice.\n");
    }
    print_linkedList();
}

// Insert at beginning
void insertBeginning() {
    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d", &nodeInstance->data);

    nodeInstance->next = head;
    head = nodeInstance;
}

// Insert at end
void insertEnd() {
    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d", &nodeInstance->data);
    nodeInstance->next = NULL;

    if (head == NULL) {
        head = nodeInstance;
        return;
    }

    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = nodeInstance;
}

// Insert in the middle by position
void insertMiddle() {
    int position;
    printf("Enter position to insert: ");
    scanf("%d", &position);

    if (position < 1 || position > listSize() + 1) {
        printf("Invalid position!\n");
        return;
    }

    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d", &nodeInstance->data);

    if (position == 1) {
        nodeInstance->next = head;
        head = nodeInstance;
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    nodeInstance->next = current->next;
    current->next = nodeInstance;
}

// Delete element menu
void deleteElement() {
    int choice;
    printf("\nEnter where you want to delete an element:\n");
    printf("1. Beginning\n2. In Middle by Position\n3. At End\n4. Search and Delete Element\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteBeginning();
            break;
        case 2:
            deleteMiddle();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            deletebyElement();
            break;
        default:
            printf("Invalid choice.\n");
    }
    print_linkedList();
}

// Delete at beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }

    struct node *current = head;
    head = head->next;
    free(current);
}

// Delete at end
void deleteEnd() {
    if (head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Delete in the middle by position
void deleteMiddle() {
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > listSize()) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    struct node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Delete by searching for an element
void deletebyElement() {
    int key;
    printf("Enter element to delete: ");
    scanf("%d", &key);

    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (current == head) {
        deleteBeginning();
    } else if (current->next == NULL) {
        deleteEnd();
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Get the size of the linked list
int listSize() {
    struct node *current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n2. Print Linked List\n3. Add Element\n4. Delete Element\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_linkedList();
                break;
            case 2:
                print_linkedList();
                break;
            case 3:
                addElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
