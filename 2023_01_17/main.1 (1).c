#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int A;//학번
	char B;//이름
	int C;//국어
	int D;//영어
	int E;//수학
	struct Node *next;
} ListNode;//솔직히 구조체 적기 귀찮잖어..


int insertNode(ListNode **ptrHead){
	int A;
	char B;
	int C;
	int D;
	int E;
	ListNode *tempNode = (ListNode *)malloc(sizeof(ListNode));
	if(!tempNode){
		return -1;
	}
	printf("이름 : ");
	scanf( " %c" ,&B);
	tempNode->B = B;
	printf("학번 : ");
	scanf("%d",&A);
	tempNode->A = A;
	printf("국어 : ");
	scanf("%d",&C);
	tempNode->C = C;
	printf("영어 : ");
	scanf("%d",&D);
	tempNode->D = D;
	printf("수학 : ");
	scanf("%d",&E);
	tempNode->E = E;
	
	printf("\n\n");
	
	tempNode->next = *ptrHead;
	*ptrHead = tempNode;
	return 1;
}

void printList (ListNode *head){
	printf("리스트 출력: \n");
	while(head){
		printf("학번 : %d ",head->A);
		printf("이름 : %c ",head->B);
		printf("국어 : %d ",head->C);
		printf("영어 : %d ",head->D);
		printf("수학 : %d\n",head->E);
		head = head->next;
	}
	printf("\n");
}

void sortedInsert_A(ListNode** head, ListNode* newNode)
{
    ListNode dummy;
    ListNode* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->A < newNode->A) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
void insertSort_A(ListNode** head)
{
    ListNode* result = NULL;    
    ListNode* current = *head;  
    ListNode* next;
 
    while (current != NULL)
    {
        
        next = current->next;
        sortedInsert_A(&result, current);
        current = next;
    }
 
    *head = result;
}
void sortedInsert_B(ListNode** head, ListNode* newNode)
{
    ListNode dummy;
    ListNode* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->B < newNode->B) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
void insertSort_B(ListNode** head)
{
    ListNode* result = NULL;    
    ListNode* current = *head;  
    ListNode* next;
 
    while (current != NULL)
    {
        
        next = current->next;
 
        sortedInsert_B(&result, current);
        current = next;
    }
 
    *head = result;
}
void sortedInsert_C(ListNode** head, ListNode* newNode)
{
    ListNode dummy;
    ListNode* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->C < newNode->C) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
void insertSort_C(ListNode** head)
{
    ListNode* result = NULL;    
    ListNode* current = *head;  
    ListNode* next;
 
    while (current != NULL)
    {
        
        next = current->next;
 
        sortedInsert_C(&result, current);
        current = next;
    }
 
    *head = result;
}
void sortedInsert_D(ListNode** head, ListNode* newNode)
{
    ListNode dummy;
    ListNode* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->D < newNode->D) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
void insertSort_D(ListNode** head)
{
    ListNode* result = NULL;    
    ListNode* current = *head;  
    ListNode* next;
 
    while (current != NULL)
    {
        
        next = current->next;
 
        sortedInsert_D(&result, current);
        current = next;
    }
 
    *head = result;
}
void sortedInsert_E(ListNode** head, ListNode* newNode)
{
    ListNode dummy;
    ListNode* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->E < newNode->E) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
void insertSort_E(ListNode** head)
{
    ListNode* result = NULL;    
    ListNode* current = *head;  
    ListNode* next;
 
    while (current != NULL)
    {
        
        next = current->next;
 
        sortedInsert_E(&result, current);
        current = next;
    }
 
    *head = result;
}

int main(void){
	
	ListNode *head = NULL;
	insertNode(&head);
	insertNode(&head);
	insertNode(&head);
	insertSort_C(&head);
	printList(head);
	printf("\n\n");
	insertSort_E(&head);
	printList(head);
	
	return 0;
}