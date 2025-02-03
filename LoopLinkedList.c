#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *prev = NULL;
int numNodes = 0;

void createLinkedList() {
	char choice;
	do {
		struct node *nodeInstance = (struct node *)malloc(sizeof(struct node));
		if (nodeInstance) {
			numNodes += 1;
			printf("Enter element: ");
			scanf("%d", &nodeInstance->data);
			nodeInstance->next = NULL;
			if (head) {
				prev->next = nodeInstance;
			} else {
				head = nodeInstance;
			}
			prev = nodeInstance;
			printf("Do you want to insert another element (y/n)? ");
			while (getchar() != '\n'); // Clear the input buffer
			scanf("%c", &choice);
		} else {
			printf("Memory not allocated for LinkedList\n");
			return;
		}
	} while (choice == 'y' || choice == 'Y');
}

void printLinkedList() {
	struct node *current = head;
	if (current) {
		int count = 0;
		while (current && count < 99) {
			printf("%d -> %p\n", current->data, current->next);
			current = current->next;
			count += 1;
		}
		// if (count == numNodes) {
		//     printf("...\n");
		// }
	} else {
		printf("LinkedList not created\n");
	}
}

void createLoop() {
	struct node *current = head;
	struct node *loopNode = head;
	int position;
	printf("Enter position to create a loop (1 to %d): ", numNodes);
	scanf("%d", &position);
	if (position < 1 || position > numNodes) {
		printf("Invalid position\n");
		return;
	}
	while (position - 1 && loopNode) {
		loopNode = loopNode->next;
		position--;
	}
	while (current->next) {
		current = current->next;
	}
	current->next = loopNode;
	printf("Loop created\n");
}
void findLoop() {
	/*Here i am implementing Floyd’s Cycle-Finding Algorithm.
	This approch called as Tortoise - Hare Approach makes use of two pointers
	slow = head->next and fast head->next->next
	As we move the pointers, if there is any loop present in createLinkedList
	pointers will meet at same element.
	*/
	struct node *slow = head;
	struct node *fast = head;
	int detected = 0;
	while(slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			printf("Loop Detected\n");
			detected = 1;
			break;
		}
	}
	if(detected) {
		printf("Loop Detected\nPrinting Loop elements\n");
		struct node *loopStart = head;
		while(loopStart!=slow) {
			printf("%d->",loopStart->data);
			loopStart = loopStart->next;
			slow = slow->next;
		}
		printf("%d -> ", loopStart->data);
		struct node *current = loopStart->next;
		while (current != loopStart) {
			printf("%d -> ", current->data);
			current = current->next;
		}
		printf("%d -> ...\n", loopStart->data);
	}
	else {
		printf("No loop detected. Printing linked list elements:\n");
		struct node *current = head;
		while (current) {
			printf("%d -> ", current->data);
			current = current->next;
		}
	}
}
int main() {
	createLinkedList();
	printLinkedList();
	char choice;
	printf("Do u want to create a loop y or n\n");
	while(getchar()!='\n');
	scanf("%c",&choice);
	if(choice=='y') {
		createLoop();
		printf("Verifying Loop Creation\n");
		printLinkedList();
	}
	findLoop();
	return 0;
}