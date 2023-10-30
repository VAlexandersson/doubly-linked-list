#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


typedef struct NodeDLL {
	int data;
	struct NodeDLL* next, * prev;
} Node;


typedef struct doublyLinkedList {
	Node* head, * tail;
} LinkedList;


Node* NewNode(int x);
LinkedList* createDLL(void);
int isListEmpty(LinkedList* list);
int insertArray(LinkedList* list, int A[]);
int insertNode(LinkedList* list, Node* node);
int sizeOfList(Node* node);
Node* middleNode(Node* first);
Node* endOfList(Node* node);
Node* splitList(Node* node);
void display(LinkedList* l);
void displayCompare(Node* prob, Node* solu);
#endif