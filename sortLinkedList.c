#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;

void createList1(){
    char choice;
    struct node *prev = NULL;
    do{
        struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
        if(nodeInstance){
            printf("Enter data\n");
            scanf("%d",&nodeInstance->data);
            nodeInstance->next = NULL;
            if(head1){
                prev->next = nodeInstance;
            }
            else{
                head1 = nodeInstance;
            }
            prev = nodeInstance;
            printf("Do u want to insert another element y or n\n");
            while(getchar()!='\n');
            scanf("%c",&choice);
        }
        else{
            printf("Memory not allcoated\n");
            return;
        }
    }while(choice=='y'||choice=='Y');
}
void createList2(){
    char choice;
    struct node *prev = NULL;
    do{
        struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
        if(nodeInstance){
            printf("Enter data\n");
            scanf("%d",&nodeInstance->data);
            nodeInstance->next = NULL;
            if(head2){
                prev->next = nodeInstance;
            }
            else{
                head2 = nodeInstance;
            }
            prev = nodeInstance;
            printf("Do u want to insert another element y or n\n");
            while(getchar()!='\n');
            scanf("%c",&choice);
        }
        else{
            printf("Memory not allcoated\n");
            return;
        }
    }while(choice=='y'||choice=='Y');
}
void printList(struct node *current){
  while(current){
      printf("%d->%p\n",current->data,current->next);
      current = current->next;
  }  
}
struct node * merge(){
    if(!head1)
        return head2;
    else if (!head2)
        return head1;
    else{
        int choice;
        printf("Where u want to append\t1. end of first list 2. end of second list\n");
        scanf("%d",&choice);
        if(choice==1){
            struct node *current = head1;
            while(current->next)
                current = current->next;
            current->next = head2;
            return head1;
        }
        else{
            struct node *current = head2;
            while(current->next)
                current = current->next;
            current->next = head1;
            return head2;
        }
    }
}
struct node *sortMerge() {
    if (head1 == NULL) return head2; 
    if (head2 == NULL) return head1;
    struct node *mergehead = NULL;
    struct node *tail = NULL;
    if (head1->data <= head2->data) {
        mergehead = head1;
        head1 = head1->next;
    } else {
        mergehead = head2;
        head2 = head2->next;
    }
    tail = mergehead;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return mergehead;
}
int main(){
    int choice;
    struct node *mergelist;
    printf("LinkedList 1\n");
    createList1();
    printf("\nLinkedList 2\n");
    createList2();
    printf("Elements of LinkedList 1\n");
    printList(head1);
    printf("\nElements of LinkedList 2\n");
    printList(head2);
    printf("Enter your choice to merge\n1.Merge without sort\n2.Sort and Merge\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            mergelist = merge();
            printf("LinkedList after Merge\n");
            printList(mergelist);
        break;
        case 2:
            mergelist = sortMerge();
            printf("LinkedList after sort and merge \n");
            printList(mergelist);
        break;
    }
}