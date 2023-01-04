#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
} ListNode;


int insertNode(ListNode **ptrHead, int value){
	ListNode *tempNode = (ListNode *)malloc(sizeof(ListNode));
	if(!tempNode){
		return -1;
	}
	tempNode->value = value;
	tempNode->next = *ptrHead;
	*ptrHead = tempNode;
	return 1;
}

void printList(ListNode *head){
	printf("리스트 출력: ");
	while(head){
		printf(" %d ",head->value);
		head = head->next;
	}
	printf("\n");
}

int sortedInsert(ListNode **ptrHead, int value){
	ListNode *head = *ptrHead;
	ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
	printf("입력 원소 %d \n",value);
	
	if(!tempNode){
		return -1;
	}
	
	tempNode->value=value;
	tempNode->next=NULL;
	if(head==NULL || head->value > value){
		tempNode->next = *ptrHead;
		*ptrHead = tempNode;
		return 1;
	}
	
	while (head->next != NULL && head->next->value < value){
		head = head->next;
	}
	
	tempNode->next=head->next;
	head->next=tempNode;
	return 1;
}

int insertAtEnd(ListNode **ptrHead, int value){
	ListNode *head = *ptrHead;
	ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
	if(!tempNode){
		return -1;
	}
	tempNode->value = value;
	tempNode->next = NULL;
	
	if(head == NULL){
		tempNode->next = *ptrHead;
		*ptrHead = tempNode;
		return 1;
	}
	
	while(head->next != NULL){
		head = head->next;
	}
	
	tempNode->next = head->next;
	head->next = tempNode;
	
	return 1;
}




int main(void){
	
	ListNode *head = NULL;
	insertNode(&head, 4);
	insertNode(&head, 2);
	insertNode(&head, 1);
	sortedInsert(&head,3);
	insertAtEnd(&head,5);
	printList(head);

	
	return 0;
}