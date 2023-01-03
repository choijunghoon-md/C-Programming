#include <stdio.h>
#define NO_MAX_WAYPOINTS 50
float   X[NO_MAX_WAYPOINTS] = { 0, };
float   Y[NO_MAX_WAYPOINTS] = { 0, };
float Yaw[NO_MAX_WAYPOINTS] = { 0, };
float result;

int read_waypoints_data(void);

int main(void){

	read_waypoints_data();

	return 1;
}

int read_waypoints_data(void){
	FILE *fp;
	int no_line = 0;
	float x, y, yaw;
	fp = fopen("waypoints.dat", "rt");
	do{
		result = fscanf(fp, "%f %f %f", &x, &y, &yaw);
		X[no_line] = x;
		Y[no_line] = y;
		Yaw[no_line] = yaw;
		no_line++;
	} while (result > 0);
	for (int i = 0; i < no_line; i++){
		printf("\n %f %f %f \n", X[i], Y[i], Yaw[i]);
	}
	printf("no of line %d\n", no_line);

	return 0;
}
