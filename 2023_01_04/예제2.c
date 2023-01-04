#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N,M;
	int i=0;
	while(1){
		printf("임의의 정수 두개를 입력하시오(예: 1 10) : ");
		scanf("%d %d",&N,&M);
		if((N>=0 && N<100000)&&(M>=0 && M<100000)){	break; }
		printf("입력된 수가 0<=N,M<100000의 조건을 벗어났습니다.\n다시입력하시오......\n");
	}
	
	if(N>M){
		for(i=M; i<=N; i++){
			printf(" %d ",i);
		}
	}
	
	else{
		for(i=N; i<=M; i++){
			printf(" %d ",i);
		}
	}
	
	return 0;
}