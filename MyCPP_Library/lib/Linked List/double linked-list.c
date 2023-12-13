#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct _node of double linked-list
typedef struct ListNode{
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
} listNode;

// head node of starting point of list.
typedef struct {
	listNode* head;
} linkedList_h;

// void double linked-list creation.
linkedList_h* createLinkedList_h(void){
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// double linked-list print orderlly.
void printList(linkedList_h* DL){
	listNode* p;
	printf(" DL = (");
	p = DL->head;
	while(p != NULL){
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// insert data behind pre
void insertNode(linkedList_h* DL, listNode *pre, char*x){
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if(DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else{
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if(newNode->rlink != NULL)  // if. there's another node behind pre
			newNode->rlink->llink = newNode;
	}
}

// delete old node in double linked-list
void deleteNode(linkedList_h* DL, listNode* old){
	if(DL->head == NULL) return;
	else if (old== NULL) return;
	else{
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);
	}
}

// search node x in list
listNode* searchNode(linkedList_h* DL, char* x){
	listNode *temp;
	temp = DL->head;
	while(temp != NULL) {
		if(strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}


