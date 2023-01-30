#include <stdio.h>

float old_average=0;
float new_average=0;

 void nomal_average_5data (float a,int K){
    new_average=(old_average*(K-1)/K)+(a/K);
    old_average=new_average ;
  }

int main(void){
	float b=0;
	int K=1;
	
	while(1){
		printf("값을 넣으세요 : ");
		scanf("%f",&b);
		nomal_average_5data (b,K);
		K = K+1;
		printf("%f \n",new_average);
	}
}