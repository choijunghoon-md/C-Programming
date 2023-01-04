#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N,M,i,a,end,cnt;
	printf("몇개의 막대기가 있는가? : ");
	scanf("%d",&N);
	if(N>=2 && N<=100000){
		int *M=(int *)malloc(sizeof(int)*N);
		for(i=0;i<N;i++){
			scanf("%d",&a);
			if(a>=1 && a<=100000){
				M[i]=a;
			}		
			else{			
				return 0;		
			}
		}
		cnt=1;
		end=M[N-1];
		for(i=N-2;i>=0;i--){
			if(M[i]>end){
				cnt++;
				end=M[i];
			}
		}
		printf("\n%d\n",cnt);
		free(M);
	}
	
	return 0;
}