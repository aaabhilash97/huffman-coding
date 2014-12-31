#include "library.h"
// Uses special case code for the head end
void SortedInsertt(struct node** headRef, struct node* newNode) {
// Special case for the head end
if (*headRef == NULL ||strcmp((*headRef)->name,newNode->name)<=0) {
newNode->next = *headRef;
*headRef = newNode;
}
else {
// Locate the node before the point of insertion
struct node* current = *headRef;
while (current->next!=NULL && strcmp((*headRef)->name,newNode->name)<0) {
current = current->next;
}
newNode->next = current->next;
current->next = newNode;
}
}/*
// Dummy node strategy for the head end
void SortedInsert2(struct node** headRef, struct node* newNode) {
struct node dummy;
struct node* current = &dummy;
dummy.next = *headRef;
while (current->next!=NULL && current->next->data<newNode->data) {
current = current->next;
}
newNode->next = current->next;
current->next = newNode;
*headRef = dummy.next;
}
// Local references strategy for the head end
void SortedInsert3(struct node** headRef, struct node* newNode) {
struct node** currentRef = headRef;
while (*currentRef!=NULL && (*currentRef)->data<newNode->data) {
currentRef = &((*currentRef)->next);
}
newNode->next = *currentRef;
// Bug: this line used to have
// an incorrect (*currRef)->next
*currentRef = newNode;
}*/
void InsertSortt(struct node** headRef) {
struct node* result = NULL;
// build the answer here
struct node* current = *headRef; // iterate over the original list
struct node* next;
while (current!=NULL) {
next = current->next;
// tricky - note the next pointer before we change it
SortedInsertt(&result, current);
current = next;
}
*headRef = result;
}
