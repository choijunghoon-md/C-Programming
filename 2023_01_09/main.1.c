#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

int A(int *c,int A);
int a(int *c,int A);
int ddd(int *c);

int main(void){
	
	int i;
	int scores[SIZE+1];
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<SIZE; i++){
		scores[i] = (rand() % 100);
	}
	for(i=0; i<SIZE; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	A(&scores,0);
	
	for(i=0; i<SIZE; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	a(&scores,0);
	
	for(i=0; i<SIZE; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	ddd(&scores);
	
	printf("\n\n");
	
	A(&scores,1);
	
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	printf("\n\n");
	
	a(&scores,1);
	
	for(i=0; i<SIZE+1; i++){
		printf("scores[%d]=%d\n",i,scores[i]);
	}
	
	
	
	return 0;
}

int A(int *c,int A){
	
	int min;
	int a,b=0;
	int f;
	f=sizeof(int)*(strlen(c));
	f++;
	for(int i=0; i<f+A; i++){
		min=1000;
		for(int j=i; j<f+A; j++){
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



int a(int *c,int A){
	int max;
	int a,b=0;
	int f;
	f=sizeof(int)*(strlen(c));
	f++;
	for(int i=0; i<f+A; i++){
		
		max=0;
		
		for(int j=i; j<f+A; j++){
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