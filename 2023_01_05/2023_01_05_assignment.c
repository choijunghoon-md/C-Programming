#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int insertlist(int *a,int b){
	for(int i=8;i>=0;i--){
		if(a[i]!= 0){
			a[i+1]=a[i];
		}
	}
	a[0]=b;
	if(b==0){
		a[0]=-100;
	}
	return 1;
}

int insertlistAtEnd(int *a,int b){
	int i=0;
	while(a[i]!=0){
		if(i>9){return -1;}
		i++;
	}
	a[i]=b;
	return 1;
}

void printlist(int *a){
	printf("리스트 출력: ");
	for(int i=0; i<10; i++){
		if(a[i]==-100){printf(" %d ",0);}
		else if(a[i]==0){}
		else{printf(" %d ",a[i]);}
	}
	printf("\n");
}

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
	
	int list[10]={0};
	
	insertlist(list,2);
	insertlist(list,0);
	insertlist(list,2);
	insertlistAtEnd(list,1);
	insertlist(list,6);
	insertlist(list,5);
	insertlistAtEnd(list,2);
	printlist(list);
	
	ListNode *head = NULL;
	insertNode(&head, 4);
	insertNode(&head, 2);
	insertNode(&head, 1);
	sortedInsert(&head,3);
	insertAtEnd(&head,5);
	printList(head);

	
	return 0;
}