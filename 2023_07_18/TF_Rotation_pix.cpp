// TF_Rotation.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define RAD2DEG(x)   x*180/M_PI  //���̾ȿ��� ��۷�
#define DEG2RAD(x)   x*M_PI/180  //��ۿ��� ��������

typedef struct 
{
	double x;
	double y;
	double theta;
} Pose2D;

typedef struct
{
	double x;
	double y;	
} Point2D;


Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;


double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix_inverse[0][0] = cos(angle_radian);    Rotation_matrix_inverse[0][1] = sin(angle_radian);
	Rotation_matrix_inverse[1][0] = -sin(angle_radian);   Rotation_matrix_inverse[1][1] = cos(angle_radian);
}

void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix[0][0] = cos(angle_radian);   Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian);   Rotation_matrix[1][1] = cos(angle_radian);
}

void TF_Change_base_link1(Point2D* base_link_map_point2d, Pose2D base_link_origin) {
	set_rotation_matrix_inverse(base_link_origin.theta);
	double transform_X = (Rotation_matrix_inverse[0][0] * base_link_map_point2d->x) + Rotation_matrix_inverse[0][1] * (base_link_map_point2d->y);
	double transform_Y = (Rotation_matrix_inverse[1][0] * base_link_map_point2d->x) + Rotation_matrix_inverse[1][1] * (base_link_map_point2d->y);
	base_link_map_point2d->x = transform_X;
	base_link_map_point2d->y = transform_Y;
}

void TF_Change_base_link_map1(Point2D* base_link_point2d, Pose2D base_link_origin) {
	set_rotation_matrix(base_link_origin.theta);
	double transform_X = (Rotation_matrix[0][0] * base_link_point2d->x) + (Rotation_matrix[0][1] * base_link_point2d->y);
	double transform_Y = (Rotation_matrix[1][0] * base_link_point2d->x) + (Rotation_matrix[1][1] * base_link_point2d->y);
	base_link_point2d->x = transform_X;
	base_link_point2d->y = transform_Y;
}

void TF_Change_base_link_map2(Point2D* base_link_point2d, Pose2D base_link_origin) {
	double transform_X = base_link_point2d->x + base_link_origin.x;
	double transform_Y = base_link_point2d->y + base_link_origin.y;
	base_link_point2d->x = transform_X;
	base_link_point2d->y = transform_Y;
}
void TF_Change_base_link2(Point2D* base_link_map_point2d, Pose2D base_link_origin) {
	double transform_X = base_link_map_point2d->x - base_link_origin.x;
	double transform_Y = base_link_map_point2d->y - base_link_origin.y;
	base_link_map_point2d->x = transform_X;
	base_link_map_point2d->y = transform_Y;
}


void TF_base_link_base_link_map(Point2D* base_link_point2d, Point2D *base_link_map_point2d, Pose2D base_link_origin)
{
	printf("\n\n");
	printf("base_link_point      %6.3lf  %6.3lf\n", base_link_point2d->x, base_link_point2d->y);
	printf("base_link_map_point  %6.3lf  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);
	printf("base_link_origin     %6.3lf  %6.3lf  %6.3lf\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);
	printf("//////////////////////////////////////////////////////////////////////////////////////////////\n");

	TF_Change_base_link2(base_link_map_point2d, base_link_origin);
	TF_Change_base_link1(base_link_map_point2d, base_link_origin);

	TF_Change_base_link_map1(&base_link_Point2D, base_link_origin);
	TF_Change_base_link_map2(&base_link_Point2D, base_link_origin);

	printf("change base_link_point -> base_link_map_point     %6.3lf  %6.3lf\n", base_link_point2d->x, base_link_point2d->y);
	printf("change base_link_map_point -> base_link_point     %6.3lf  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);
	printf("//////////////////////////////////////////////////////////////////////////////////////////////\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	//angle_degree = 90;
	//angle_radian = DEG2RAD(angle_degree);

	base_link_origin.x = 2.0;
	base_link_origin.y = 1.0;
	base_link_origin.theta = 90;	

	base_link_Point2D.x = 1;
	base_link_Point2D.y = 1;

	base_link_map_Point2D.x = 1;
	base_link_map_Point2D.y = 1;

	set_rotation_matrix(base_link_origin.theta);
	
	/*printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);*/

	TF_base_link_base_link_map(&base_link_Point2D, &base_link_map_Point2D, base_link_origin);

	return 0;
}

