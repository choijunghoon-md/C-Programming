#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


struct {
    double X;    //x값
    double Y;    //y값
    double deg;  //각도
}Input_baselink_map;


double chang_map(double x, double y) {
    double x1 = (Input_baselink_map.X * cos(Input_baselink_map.deg * M_PI / 180) - Input_baselink_map.Y * sin(Input_baselink_map.deg * M_PI / 180)); //+ Input_baselink_map.X;
    double y1 = (Input_baselink_map.Y * cos(Input_baselink_map.deg * M_PI / 180)) + (Input_baselink_map.X * sin(Input_baselink_map.deg*M_PI/180)); //+ Input_baselink_map.Y;
    x1 += x;
    y1 += y;
    printf("x : %f\n", x1);
    printf("y : %f", y1);

    return 0;
}

int main()
{
    Input_baselink_map = {
        1,1,45
    };
    chang_map(4, 4);
}