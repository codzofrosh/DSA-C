#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

// Function to create a doubly linked list
void create_linkedList() {
    char choice;
    struct node *prevNode = NULL;

    do {
        struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
        if (!nodeInstance) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter element to be inserted: ");
        scanf("%d", &nodeInstance->data);
        nodeInstance->prev = NULL;
        nodeInstance->next = NULL;

        if (head) {
            prevNode->next = nodeInstance;
            nodeInstance->prev = prevNode;
        } else {
            head = nodeInstance;
        }

        prevNode = nodeInstance;

        printf("Do you want to insert another element? (y/n): ");
        while (getchar() != '\n');
        scanf("%c", &choice);

    } while (choice == 'Y' || choice == 'y');
}

// Function to print the linked list
void print_linkedList() {
    struct node *current = head;
    if (!current) {
        printf("No LinkedList found.\n");
        return;
    }

    printf("Linked List Elements:\n");
    while (current) {
        printf("%p <- [%d] -> %p\n", current->prev, current->data, current->next);
        current = current->next;
    }
}

// Function to insert a node at the beginning
void insertBeginning() {
    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    if (!nodeInstance) {
        printf("Memory not allocated\n");
        return;
    }

    printf("Enter data to be inserted at the beginning: ");
    scanf("%d", &nodeInstance->data);

    nodeInstance->prev = NULL;
    nodeInstance->next = head;

    if (head)
        head->prev = nodeInstance;

    head = nodeInstance;
}

// Function to insert a node at the end
void insertEnd() {
    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    if (!nodeInstance) {
        printf("Memory not allocated\n");
        return;
    }

    printf("Enter element to be inserted at the end: ");
    scanf("%d", &nodeInstance->data);

    nodeInstance->next = NULL;

    if (!head) {
        nodeInstance->prev = NULL;
        head = nodeInstance;
        return;
    }

    struct node *current = head;
    while (current->next)
        current = current->next;

    current->next = nodeInstance;
    nodeInstance->prev = current;
}

// Function to insert a node at a specific position
void insertPosition() {
    int position;
    printf("Enter position to insert the element: ");
    scanf("%d", &position);

    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    if (!nodeInstance) {
        printf("Memory not allocated\n");
        return;
    }

    printf("Enter element to be inserted: ");
    scanf("%d", &nodeInstance->data);

    if (position == 1) {
        insertBeginning();
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position - 1; ++i) {
        if (!current) {
            printf("Position out of range\n");
            free(nodeInstance);
            return;
        }
        current = current->next;
    }

    if (!current) {
        printf("Position out of range\n");
        free(nodeInstance);
        return;
    }

    nodeInstance->next = current->next;
    nodeInstance->prev = current;

    if (current->next)
        current->next->prev = nodeInstance;

    current->next = nodeInstance;
}

// Function to delete a node at the beginning
void deleteBeginning() {
    if (!head) {
        printf("No LinkedList to delete.\n");
        return;
    }

    struct node *current = head;
    head = head->next;

    if (head)
        head->prev = NULL;

    free(current);
}

// Function to delete a node at the end
void deleteEnd() {
    if (!head) {
        printf("No LinkedList to delete.\n");
        return;
    }

    struct node *current = head;

    while (current->next)
        current = current->next;

    if (current->prev)
        current->prev->next = NULL;
    else
        head = NULL;

    free(current);
}

// Function to delete a node at a specific position
void deletePosition() {
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        deleteBeginning();
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position; ++i) {
        if (!current) {
            printf("Position out of range\n");
            return;
        }
        current = current->next;
    }

    if (!current) {
        printf("Position out of range\n");
        return;
    }

    if (current->next)
        current->next->prev = current->prev;

    if (current->prev)
        current->prev->next = current->next;

    free(current);
}

// Function to delete a node by value
void deleteByValue() {
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct node *current = head;
    while (current) {
        if (current->data == value) {
            if (current == head) {
                deleteBeginning();
                return;
            }

            if (current->next)
                current->next->prev = current->prev;

            if (current->prev)
                current->prev->next = current->next;

            free(current);
            return;
        }
        current = current->next;
    }

    printf("Element not found.\n");
}

// Function to add an element
void addElement() {
    int choice;
    printf("Enter your choice\n1. Insert at Beginning\n2. Insert by Position\n3. Insert at End\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertBeginning();
            break;
        case 2:
            insertPosition();
            break;
        case 3:
            insertEnd();
            break;
        default:
            printf("Enter correct choice.\n");
    }
}

// Function to delete an element
void deleteElement() {
    int choice;
    printf("Enter your choice\n1. Delete at Beginning\n2. Delete by Position\n3. Delete by Value\n4. Delete at End\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteBeginning();
            break;
        case 2:
            deletePosition();
            break;
        case 3:
            deleteByValue();
            break;
        case 4:
            deleteEnd();
            break;
        default:
            printf("Enter correct choice.\n");
    }
}

int main() {
    create_linkedList();
    print_linkedList();

    int choice;
    do {
        printf("\n1. Add Element\n2. Delete Element\n3. Print Linked List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                print_linkedList();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
