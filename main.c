#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Node Template
struct node {
	int data;
	struct node *next;
};

//LL Struct
struct linkedList {
	struct node *head;
	struct node *tail;
	int size;
};

//List Initializer
void initList(struct linkedList *L) {
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
}

//Empty List Indicator
void emptyList() {
	printf("NULL\n\n ^HEAD\n ^TAIL\n\nList is empty.\n");
	return;
}

//Node Counter
void nodeCount(struct linkedList *L) {
	if (L->head == NULL && L->tail == NULL) {
		return;
	} else if (L->size <= 1) {
		printf("\nList Size: %d Node\n", L->size);
	} else {
		printf("\nList Size: %d Nodes\n", L->size);
	}
}

//Shows the Nodes in the List
void showNodes(struct linkedList *L) {
	printf("Your List:\n\n");
	if (L->size == 1) {
		printf("[%d] -> NULL", L->head->data);
		printf("\n\n ^HEAD\n ^TAIL\n\n");
	} else if (L->size > 1) {
		struct node *temp = L->head;
		int charCount = 0;
		int finalCharCount;

		while (temp != NULL) {
			charCount += printf("[%d] -> ", temp->data);
			if (temp->next == L->tail) {
				finalCharCount = charCount;
			}
			temp = temp->next;
		}
		printf("NULL\n");
        
        printf(" ︎↑");
        for (int i = finalCharCount - 1; i > 0; i--) {
			printf(" ");
		}
		printf("︎︎︎↑\n");
        
		printf(" HEAD");

		for (int i = finalCharCount - 5; i > 0; i--) {
			printf(" ");
		}

		printf(" TAIL\n\n");
	}
}

//Shows the List
void showList(struct linkedList *L) {
	printf("\n");
	if (L->size == 0) {
		emptyList();
		return;
	} else {
		showNodes(L);
	}
	//Head & Tail Checkers for Debugging
	/*printf("Head: %d\n", L->head->data);
	printf("Tail: %d\n", L->tail->data);*/
}

//Insertion @ Head
void insertAtHead (struct linkedList *L, int data) {
	struct node *newNode = malloc(sizeof(*newNode));

	if (L->head == NULL && L->tail == NULL) { //Empty List
		L->tail = newNode;
	}

	newNode->data = data;
	newNode->next = L->head;
	L->head = newNode;
	L->size++;
}

//Insertion @ Tail
void insertAtTail (struct linkedList *L, int data) {
	if (L->head == NULL) {
		insertAtHead(L, data);
	} else {
		struct node *newNode = malloc(sizeof(*newNode));
		newNode->data = data;
		newNode->next = NULL;

		L->tail->next = newNode;
		L->tail = newNode;
		L->size++;
	}
}

//Deletion @ Head
void deleteAtHead(struct linkedList *L) {
	if (L->head == NULL && L->tail == NULL) { //Empty List
		return;
	} else if (L->head == L->tail) { //Only 1 Node
		struct node *temp = L->head;
		L->head = NULL;
		L->tail = NULL;
		free(temp);
	} else {//More than 1 node present
		struct node *temp = L->head;
		L->head = temp->next;
		free(temp);
	}
	L->size--;
}

//Deletion @ Tail
void deleteAtTail(struct linkedList *L) {
	if (L->head == NULL && L->tail == NULL) { //Empty list
		return;
	} else if (L->head->next == NULL && L->tail->next == NULL) { //Only 1 node
		deleteAtHead(L);
		return;
	} else { //More than 1 node present
		struct node *appoint = L->head;
		struct node *delete = L->tail;

		while(appoint->next->next != NULL) {
			appoint = appoint->next;
		}

		L->tail = appoint;
		appoint->next = NULL;
		free(delete);
	}
	L->size--;
}

//Deletion by Value
bool deleteByValue(struct linkedList *L, int key) {
	struct node *temp = L->head;
	struct node *prev = NULL;

	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) { //Empty list/value not found
		return false;
	} else if (prev == NULL) { //Only 1 Node
		deleteAtHead(L);
		return true;
	} else if (temp->next == NULL) { //Deleting tail
		deleteAtTail(L);
		return true;
	} else { //Deleting middle
		prev->next = temp->next;
		free(temp);
		L->size--;
		return true;
	}
}

//Prints the menu
void printMenu() {
	printf("\n");
	printf("Menu\n");
	printf("----\n");
	printf("1. Insert Node at Head\n");
	printf("2. Insert Node at Tail\n");
	printf("3. Delete Node at Head\n");
	printf("4. Delete Node at Tail\n");
	printf("5. Delete by Value\n");
	printf("6. End Session\n");
	printf("\nChoose Action (1-6): ");
}

//Invalid Input Indicator
void invalidInput() {
	printf("\nINVALID INPUT\n");
}

//Node Insertion Indicator
void nodeInserted() {
	printf("\nNode inserted.\n");
}

//Node Deletion Indicator
void nodeDeleted() {
	printf("\nNode deleted.\n");
}

int main() {
	struct linkedList *L = malloc(sizeof(*L));
	initList(L);
	int choice;

	printf("============================\n");
	printf(" Singly Linked List Manager\n");
	printf("============================\n");

	showList(L);
	nodeCount(L);

	do {
		int input;
		printMenu();
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\n[Head Insertion]\nInput Value for New Node: ");
			scanf("%d", &input);
			insertAtHead(L, input);
			nodeInserted();
			break;
		case 2:
			printf("\n[Tail Insertion]\nInput Value for New Node: ");
			scanf("%d", &input);
			insertAtTail(L, input);
			nodeInserted();
			break;
		case 3:
			printf("\n[Head Deletion]\n");
			deleteAtHead(L);
			nodeDeleted();
			break;
		case 4:
			printf("\n[Tail Deletion]\n");
			deleteAtTail(L);
			nodeDeleted();
			break;
		case 5:
			printf("\n[Value-Based Deletion]\nInput Target Value: ");
			scanf("%d", &input);
			if (deleteByValue(L, input) == false) {
				printf("\nValue not found.\n");
			} else {
				nodeDeleted();
			}
			break;
		case 6:
			break;
		default:
			invalidInput();
			break;
		}

		if (choice >= 1 && choice <6) {
			showList(L);
			nodeCount(L);
		}

	} while (choice != 6);
	
	printf("\nSession Ended\n");
	showList(L);
	nodeCount(L);

	return 0;
}
