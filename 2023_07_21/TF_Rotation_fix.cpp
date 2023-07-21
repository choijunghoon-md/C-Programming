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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TF_base_link_base_link_map(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix(base_link_origin.theta);
	/*printf("\n\n");
	printf("base_link_point      %6.3lf  %6.3lf\n", base_link_point2d->x, base_link_point2d->y);
	printf("base_link_map_point  %6.3lf  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);
	printf("base_link_origin     %6.3lf  %6.3lf  %6.3lf\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);*/
	base_link_map_point2d->x = (Rotation_matrix[0][0] * base_link_point2d.x) + (Rotation_matrix[0][1] * base_link_point2d.y);
	base_link_map_point2d->y = (Rotation_matrix[1][0] * base_link_point2d.x) + (Rotation_matrix[1][1] * base_link_point2d.y);
}

void TF_base_link_map_map(Point2D base_link_2D, Point2D* base_link_map_2D, Pose2D base_link_origin) {
	base_link_map_2D->x += base_link_origin.x;
	base_link_map_2D->y += base_link_origin.y;
}

void TF_map_base_link(Point2D base_link_2D, Point2D* base_link_map_2D, Pose2D base_link_origin) {
	TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	TF_base_link_map_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
}




void TF_base_link_map_base_link(Point2D* base_link_point2d, Point2D base_link_map_point2d, Pose2D base_link_origin)
{
	set_rotation_matrix_inverse(base_link_origin.theta);
	/*printf("\n\n");
	printf("base_link_point      %6.3lf  %6.3lf\n", base_link_point2d->x, base_link_point2d->y);
	printf("base_link_map_point  %6.3lf  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);
	printf("base_link_origin     %6.3lf  %6.3lf  %6.3lf\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);*/
	base_link_point2d->x = (Rotation_matrix_inverse[0][0] * base_link_map_point2d.x) + Rotation_matrix_inverse[0][1] * (base_link_map_point2d.y);
	base_link_point2d->y = (Rotation_matrix_inverse[1][0] * base_link_map_point2d.x) + Rotation_matrix_inverse[1][1] * (base_link_map_point2d.y);
}

void TF_map_base_link_map(Point2D* base_link_2D, Point2D base_link_map_2D, Pose2D base_link_origin) {
	base_link_2D->x -= base_link_origin.x;
	base_link_2D->y -= base_link_origin.y;
}

void TF_base_link_map(Point2D* base_link_2D, Point2D base_link_map_2D, Pose2D base_link_origin) {
	TF_map_base_link_map(&base_link_Point2D, base_link_map_Point2D, base_link_origin);
	TF_base_link_map_base_link(&base_link_Point2D, base_link_map_Point2D, base_link_origin);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	//angle_degree = 90;
	//angle_radian = DEG2RAD(angle_degree);

	base_link_origin.x = 0.0;
	base_link_origin.y = 0.0;
	base_link_origin.theta = 90;

	base_link_Point2D.x = 4;
	base_link_Point2D.y = 2;

	base_link_map_Point2D.x = -2;
	base_link_map_Point2D.y = 4;

	/*printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);*/
	TF_map_base_link(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	printf("base_link -> map  x:%6.3lf    y:%6.3lf\n\n", base_link_map_Point2D.x, base_link_map_Point2D.y);

	TF_base_link_map(&base_link_Point2D, base_link_map_Point2D, base_link_origin);
	printf("map -> base_link  x:%6.3lf   y:%6.3lf\n\n", base_link_Point2D.x, base_link_Point2D.y);

	return 0;
}