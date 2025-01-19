#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front,*rear;
};

void initializeQueue(struct queue *QueueInstance){
    QueueInstance->front = QueueInstance->rear = NULL;
}
void enqueue(struct queue *QueueInstance){
    char choice;
    do{
        struct node *NodeInstance = (struct node *)malloc(sizeof(struct node));
        if(NodeInstance){
            printf("Enter element to insert in Queue\n");
            scanf("%d",&NodeInstance->data);
            NodeInstance->next = NULL;
            if(QueueInstance->rear == NULL)
            {
                QueueInstance->front = QueueInstance->rear = NodeInstance;
            }
            else
            {
                QueueInstance->rear->next = NodeInstance;
                QueueInstance->rear = NodeInstance;
            }
        }
        else{
            printf("Memory Not allocated for Enqueuing\n");
            return;
        }
        printf("Do u want to enqueue another element\n");
        while(getchar()!='\n');
        scanf("%c",&choice);
    }while(choice=='y'||choice=='Y');
}
void dequeue(struct queue *QueueInstance){
    char choice;
    do{
        if(QueueInstance->rear == NULL){
            printf("Queue Empty\n");
            return;
        }
        struct node *current = QueueInstance->front;
        int dequeuedElement = current->data;
        printf("Dequeued Element %d\n",dequeuedElement);
        QueueInstance->front = QueueInstance->front->next;
        free(current);
        printf("do u want to dequeue another element\n");
        while(getchar()!='\n');
        scanf("%c",&choice);
    }
}
void printQueue(struct queue *QueueInstance){
    struct node *current = QueueInstance->front;
    if(current){
        while(current!=NULL){
            printf("%d->",current->data);
            current = current->next;
        }
    }
    else{
        printf("Queue Empty\n");
    }
    return;
}
int main(){
    struct queue *QueueInstance = (struct queue *)malloc(sizeof(struct queue));
    if(!QueueInstance){
        printf("Memory for Queue not initalized\n");
        return -1;
    }
    initializeQueue(QueueInstance);
    enqueue(QueueInstance);
    printf("Queue after enqueueing\n");
    printQueue(QueueInstance);
    dequeue(QueueInstance);
    printf("\nQueue After Dequeing\n");
    printQueue(QueueInstance);
    return 0;
}