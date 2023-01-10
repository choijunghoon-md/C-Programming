#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aaa(int (*c)[3]);
//void sum1 (int (*c)[3]);
//void sum2 (int (*c)[3]);
//void sum3 (int (*c)[3]);
void sum(int (*c)[3],int num);

int main(void){
	
	int test[5][3];
	
	//0=수학,1=국어,2=영어
	aaa(&test);
    printf("\n");
	sum(&test,1);
	printf("\n\n\n");
	sum(&test,2);
	printf("\n\n\n");
	sum(&test,3);
	printf("\n\n\n");
	
	return 0;
}


void sum1 (int (*c)[3]){
	float sum=0;
	int max=0;
	int b[5]={0};
	int d=0;
	int a[5];
	
	for(int i=0;i<5;i++){
		a[i]=c[i][0];
	}
	
	for(int i=0;i<5;i++){
		sum += a[i];
	}
	
	
	
	for(int i=0; i<5; i++){
		max=0;
		for(int j=0; j<5; j++){
			if(max<=a[j]){
				max=a[j];
				b[i]=j;
			}
		}
		printf("수학 %d등 %d번 점수:%2d\n",i+1,b[i]+1,c[b[i]][0]);
		a[b[i]]=0;
	}
	
	printf("\n평균 : %f",sum/5);
	
}

void sum2(int (*c)[3]){
	float sum=0;
	int max=0;
	int b[5]={0};
	int d=0;
	int a[5];
	
	for(int i=0;i<5;i++){
		a[i]=c[i][1];
	}
	
	for(int i=0;i<5;i++){
		sum += a[i];
	}

	
	for(int i=0; i<5; i++){
		max=0;
		for(int j=0; j<5; j++){
			if(max<=a[j]){
				max=a[j];
				b[i]=j;
			}
		}
		printf("국어 %d등 %d번 점수:%2d\n",i+1,b[i]+1,c[b[i]][1]);
		a[b[i]]=0;
	}
	
	printf("\n평균 : %f",sum/5);
	
}

void sum3(int (*c)[3]){
	float sum=0;
	int max=0;
	int b[5]={0};
	int d=0;
	int a[5];
	
	for(int i=0;i<5;i++){
		a[i]=c[i][2];
	}
	
	for(int i=0;i<5;i++){
		sum += a[i];
	}
	
	
	
	for(int i=0; i<5; i++){
		max=0;
		for(int j=0; j<5; j++){
			if(max<=a[j]){
				max=a[j];
				b[i]=j;
			}
		}
		printf("영어 %d등 %d번 점수:%2d\n",i+1,b[i]+1,c[b[i]][2]);
		a[b[i]]=0;
	}
	
	printf("\n평균 : %f",sum/5);
	
}

void aaa(int (*c)[3]){
	
	srand((unsigned)time(NULL));
	
	for(int i=0;i<5;i++){
		printf("학번 %d 의 점수입력\n",i+1);
		c[i][0] = (rand() % 100);
		printf("수학 : %2d  ",c[i][0]);
		c[i][1] = (rand() % 100);
		printf("국어 : %2d  ",c[i][1]);
		c[i][2] = (rand() % 100);
		printf("영어 : %2d\n",c[i][2]);
	}
}

void sum(int (*c)[3],int num){
	float sum=0;
	int max=0;
	int b[5]={0};
	int d=0;
	int a[5];
	
	for(int i=0;i<5;i++){
		a[i]=c[i][num-1];
	}
	
	for(int i=0;i<5;i++){
		sum += a[i];
	}
	
	
	
	for(int i=0; i<5; i++){
		max=0;
		for(int j=0; j<5; j++){
			if(max<=a[j]){
				max=a[j];
				b[i]=j;
			}
		}
		if(num==1){printf("수학");}
		else if(num==2){printf("국어");}
		else if(num==3){printf("영어");}
		printf(" %d등 %d번 점수:%2d\n",i+1,b[i]+1,c[b[i]][num-1]);
		a[b[i]]=0;
	}
	
	printf("\n평균 : %f",sum/5);
	
}