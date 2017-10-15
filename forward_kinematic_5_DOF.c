#include <stdio.h>
#include <math.h>

#define N 4
#ifndef M_PI
#define M_PI 3.1415927
#endif

int fwd_kin(theta, x)
double *theta;
double x[3];
{	
	printf("This is to test \n");
	printf("%f\t%f\t%f\t%f\t%f\t\n",theta[0],theta[1],theta[2],theta[3],theta[4]);

	double** multiply(double **, double **, double **);
	double** calculate_rot_matrix(char , double , double **);
	double** calculate_disp_matrix(char , double , double **);
	double matDisp[N][N] = {
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 }
	};
	double matRotate[N][N] = {
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 }
	};


	double Tb0[N][N];
	double T01[N][N];
	double T12[N][N];
	double T23part1[N][N];
	double T23part2[N][N];
	double T3Tool1[N][N];	
	double T3Tool2[N][N];
	double T3Tool3[N][N];
	
	double Tb1[N][N];
	double Tb2[N][N];
	double Tb3[N][N];
	double FinalMatrix[N][N];

	//double thetaValue = 30;
	char axis[3]; // = ['x', 'y', 'z'];
	//printf("%c\n", axis[0]);
	


	double l0 = 0.25, l1 = 0.25, l2 = 0.25, l3 = 0.15;
	double d1 = 0.05, d2 = 0.05;
	double theta0 = theta[0], theta1 = theta[1], theta2 = theta[2], theta3 = theta[3], theta4 = theta[4];
	
	axis[0] = 'a';
	axis[1] = 'b';
	axis[2] = 'c';

	// Initial multiplication
	multiply(calculate_disp_matrix(axis[2], l0, matDisp), calculate_rot_matrix(axis[2], theta0, matRotate), Tb0);
	
	calculate_rot_matrix(axis[1], theta1, T01);

	multiply(calculate_disp_matrix(axis[0], l1, matDisp), calculate_rot_matrix(axis[1], theta2, matRotate), T12);

	multiply(calculate_disp_matrix(axis[1], d1, matDisp), calculate_disp_matrix(axis[0], l2, matDisp), T23part1);
	multiply(T23part1, calculate_rot_matrix(axis[1], theta3, matRotate), T23part2);
	
	multiply(calculate_disp_matrix(axis[1], d1, matDisp), calculate_disp_matrix(axis[0], l2, matDisp), T3Tool1);
	multiply(T3Tool1, calculate_disp_matrix(axis[0], l3, matDisp), T3Tool2);
	multiply(T3Tool2, calculate_rot_matrix(axis[0], theta4, matRotate), T3Tool3);

	// Final multiplication
	multiply(Tb0,T01 , Tb1);
	multiply(Tb1, T12, Tb2); 
	multiply(Tb2, T23part2, Tb3);
	multiply(Tb3, T3Tool3, FinalMatrix);

	x[0] = FinalMatrix[0][N];
	x[1] = FinalMatrix[1][N];
	x[2] = FinalMatrix[2][N];
	printf("%f\t%f\t%f\t%f\t%f\t",theta[0],theta[1],theta[2],theta[3],theta[4]);

}

double** multiply(double **mat1, double **mat2, double **res)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
			res[i][j] = 0;
            for (k = 0; k < N; k++)
				res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
	return &res;
}

double** calculate_disp_matrix(char axis, double displacement, double **matDisp) {
	
	switch (axis) {

	case 'x':
		printf("this is the x case\n");
		matDisp[0][N] = displacement;
		break;

	case 'y':
		printf("this is the y case\n");
		matDisp[1][N] = displacement;
		break;

	case 'z':
		printf("this is the z case\n");
		matDisp[2][N] = displacement;
		break;
			  
	default: 
		printf("this is the default case\n");
	}
	return &matDisp;
}

double** calculate_rot_matrix(char axis, double thetaValue, double **matRotate) {

	double s;
	double c;
	double minusS;
	
	double val = M_PI / 180.0;
	c = cos(thetaValue);
	s = sin(thetaValue);
	minusS = (-1) * s;
	
	switch (axis) {
	case 'x':
		printf("this is the x case\n");
		matRotate[1][1] = c;
		matRotate[1][2] = minusS;
		matRotate[2][1] = s;
		matRotate[2][2] = c;
		break;

	case 'y':
		printf("this is the y case\n");
		matRotate[0][0] = c;
		matRotate[0][2] = minusS;
		matRotate[2][0] = s;
		matRotate[2][2] = c;
		break;

	case 'z':
		printf("this is the z case\n");
		matRotate[0][0] = c;
		matRotate[0][1] = minusS;
		matRotate[1][0] = s;
		matRotate[1][1] = c;
		break;

	default:
		printf("this is the default case\n");
	}

	return &matRotate;
}


inv_kin(x, theta)
double *x;
double theta[6];
{
}