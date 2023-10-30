#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "doublyLinkedList.h"


Node* NewNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->prev = t->next = NULL;
    return t;
}


LinkedList* createDLL(void) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = list->tail = NULL; // tail may be redundent, ignore.
    return list;
}


int isListEmpty(LinkedList* list) {
    return list->head == NULL;
}


Node* endOfList(Node* node) {
    while (node) 
        node = node->next; // returns last node of list
    return node;
}


void display(LinkedList* list) {    // displays every nodes data of list.
    if (isListEmpty(list))
        printf("List is empty\n");
    else {
        Node* t = list->head;
        while (t) {
            printf("%d\n", t->data);
            t = t->next;
        }
    }
    printf("\n");
}


int insertArray(LinkedList* list, int A[]) { // inserts whole array in list.
    int i = 0;
    while (A[i] != NULL) {
        Node* temp = NewNode(A[i]);
        if (isListEmpty(list))
            list->head = list->tail = temp;
        else {
            list->tail->next = temp;
            temp->prev = list->tail;
            list->tail = temp;
        }
    }
}


int insertNode(LinkedList* list, Node* node) {

    if (isListEmpty(list))
        list->head = list->tail = node;

    else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    return list->tail == node;
}


int sizeOfList(Node* node) { // counts and returns the size of list.
    int c = 0;
    while (node) {
        c++;
        node = node->next;
    }
    return c;
}


Node* middleNode(Node* first) {  // finds the most middle list.
    
    Node* fast = first;
    while (fast->next) {
        fast = fast->next;
        first = first->next;
        if (fast->next) {
            fast = fast->next;
        }
    }
    return first;
}


Node* splitList(Node* node) { // splits the list at the node that are inserted
    Node* temp = node;
    node->prev->next = NULL;
    node->prev = NULL;
    return node; // returns the 'head' of the "new" list
}


void displayCompare(Node* prob, Node* solu) {
    while (prob) {
        printf("P:%d\tS:%d\n", prob->data, solu->data); // prints two different lists next to each other.
        prob = prob->next;
        solu = solu->next;
    }
}


void rrdisplay(Node* p) // reversing recursive display
{
    if (p)
    {
        rrdisplay(p->next);     // by swapping order of these to lines
        printf("%d ", p->data); // we'll get a revers printout instead.
    }
}