#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 5

int A(int *c);
int a(int *c);
int ddd(int *c);

int main(void){
	
	int i;
	int scores[SIZE+1]={0};
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<SIZE; i++){
		scores[i] = (rand() % 100);
	}
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	A(&scores);
	
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	a(&scores);
	
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	ddd(&scores);
	
	printf("\n\n");
	
	A(&scores);
	
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	a(&scores);
	
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	
	
	return 0;
}

int A(int *c){
	
	int min;
	int a,b=0;
	int f;
	f=(sizeof(int)*(strlen(c))+1);
	for(int i=0; i<f; i++){
		min=1000;
		for(int j=i; j<f; j++){
			if(min>=c[j]){
				min=c[j];
				b=j;
			}
			
		}
		a=c[i];
		c[i]=min;
		c[b]=a;
	}
}

int a(int *c){
	int max;
	int a,b=0;
	int f;
	f=(sizeof(int)*(strlen(c))+1);
	for(int i=0; i<f; i++){
		
		max=0;
		
		for(int j=i; j<f; j++){
			if(max<=c[j]){
				max=c[j];
				b=j;
			}
			a=c[i];
			c[i]=max;
			c[b]=a;
		}
		
	}
}

int ddd(int *c){
	int d;
	printf("추가값을 입력하세요. : ");
	scanf("%d",&d);
	c[5]=d;
}