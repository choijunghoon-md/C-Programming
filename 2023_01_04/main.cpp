#include <stdio.h>
#include <math.h>

#define NO_MAX 50
float Sonar[NO_MAX] = {-1,};

float read_sonarpoint_data1(void);
float read_sonarpoint_data2(void);

int no_line = 0;

int main(void){
	float sum, V;
	sum = read_sonarpoint_data1();
	V = read_sonarpoint_data2();
	printf("sum = %f  V = %f \n", sum, V);

	for (int i = 0; i < no_line ; i++){
		printf("%f \n", Sonar[i]);
	}
}

float read_sonarpoint_data1(void){
	FILE *fp;
	no_line = 0;
	float result = 0;
	float sonar,sum=0;
	fp = fopen("sonar.data.txt", "rt");
	do{
		result = fscanf(fp, "%f", &Sonar[no_line]);
		if (Sonar[no_line] != 0){
			sum += Sonar[no_line];
		}
		no_line++;
	} while (result == 1);
	no_line--;
	result = sum / no_line;
	fclose(fp);
	printf("line : %d \n", no_line);

	return result;
}

float read_sonarpoint_data2(void){
	FILE *fp;
	float result = 0;
	float sonar, a, sum=0;
	float sum1 = read_sonarpoint_data1();
	no_line = 0;
	fp = fopen("sonar.data.txt", "rt");
	sum = 0.0;
	do{
		result = fscanf(fp, "%f", &Sonar[no_line]);
		if (Sonar[no_line] != 0){
			sum += (Sonar[no_line] - sum1) * (Sonar[no_line] - sum1);
		}
		no_line++;
	} while (result == 1);
	no_line--;
	a = (sum / no_line);
	result = sqrt(a);
	fclose(fp);
	printf("line : %d \n", no_line);

	return result;
}