#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *prev = NULL;

void create_linkedList() {
    char choice;
        do{
            struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
            if(nodeInstance){
                printf("Enter data\n");
                scanf("%d",&nodeInstance->data);
                nodeInstance->next = NULL;
                //*To check
                 if(head!=NULL){
                   prev->next = nodeInstance;
                 }
                 else{
                     head = nodeInstance;
                 }
                 prev = nodeInstance;
               // */;
            }
            else{
                printf("Memory Not alloted\n");
                return;
            }
            printf("Do you want to insert another element y or n\n");
            while(getchar()!='\n');
            scanf("%c",&choice);
        } while (choice == 'y' || choice == 'Y');
    }

void print_linkedList() {
    struct node *nodeInstance = head;
    if (head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }
    printf("Linked List:\n");
    while (nodeInstance != NULL) {
        printf("%d ->%p\n", nodeInstance->data,nodeInstance->next);
        nodeInstance = nodeInstance->next;
    }
}

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

void insertBeginning() {
    struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d", &nodeInstance->data);
    nodeInstance->next = head;
    head = nodeInstance;
}

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


void deleteBeginning() {
    if (head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }

    struct node *current = head;
    head = head->next;
    free(current);
}


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
int listSize() {
    struct node *current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void convertSingletoCircularLinkedList(){
    struct node *current = head;
    while(current->next){
        current = current->next;
    }
    current->next = head;
    return;
}
void printCircularLinkedList(){
    struct node *current = head;
    printf("CircularLinkedList Elements are :\nHead %p\n",head);
    do{
        printf("%d->%p\n",current->data,current->next);
        current = current->next;
    }while(current!=head);
    return;
}
/* Algorithm for reversing linnkedlist - Iterative Approach
Initialize three pointers:
    prev_rev to keep track of the previous node, initially NULL,
    current to traverse the list, initially pointing to the head,
    next_rev to temporarily store the next node.
Traverse the list:
    While current is not NULL:
        Save the next node: next = current->next.
        Reverse the link: current->next = prev.
        Move prev and current one step forward:
        prev = current
        current = next
Update the head:
After the loop, prev will be pointing to the new head. Assign it to the head of the list.
Here I am providing this function as option. So assigning the new head revHead.
Else assign the prev_rev to head.
*/
void reverseLinkedList_iterative() {
    struct node *prev_rev = NULL;
    struct node *current = head;
    struct node *next_rev = NULL;

    while (current != NULL) {
        next_rev = current->next;   
        current->next = prev_rev;  
        prev_rev = current;        
        current = next_rev;       
    }
    struct node *revHead = prev_rev;
    printf("Reversed Elements:\n");
    while (revHead != NULL) {
        printf("%d -> %p\n", revHead->data, (void *)revHead->next);
        revHead = revHead->next;
    }
}
struct node* reverseLinkedList_recursive(struct node *current){
    if(current == NULL){
        printf("LinkedList not Initialized\n");
        return;
    }
    if(current->next==NULL){
        return current;
    }
    struct node *head_rr = reverseLinkedList_recursive(current->next);
    current->next->next = current;
    current->next = NULL;
    return head_rr;
}
void print_linkedList_recursion(struct node *head_rr){
    printf("LinkedList reversed in recursive fashion\n");
    struct node *current = head_rr;
    while(current){
        printf("%d->%p",current->data,current->next);
        current = current->next;
    }
}
int main() {
    create_linkedList();
    print_linkedList();
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Element\n2. Delete Element\n3.Convert Single to CircularLinkedList\n4.Reverse a LinkedList - Iterative\n5.Reverse LinkedList - Recursive\n");
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
                convertSingletoCircularLinkedList();
                printCircularLinkedList();
            case 4:
                reverseLinkedList_iterative();
            case 5:
                struct node *head_r = reverseLinkedList_recursive(&head);
                print_linkedList_recursion(head_r);
            case 6:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}