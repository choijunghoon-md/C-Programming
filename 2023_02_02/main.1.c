#include <stdio.h>

float old_average=0;
float new_average=0;

 void nomal_average (float a,float K){
    new_average=(old_average*K)+(a*(1-K));
    old_average=new_average;
  } //  이때 K는 가급적 0.4이상 1미만으로 한다.

int main(void){
	float b=0;
	float K=0.7;
	
	while(1){
		printf("값을 넣으세요 : ");
		scanf("%f",&b);
		nomal_average(b,K);
		printf("%f \n",new_average);
	}
}