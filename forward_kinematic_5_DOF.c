#include <stdio.h>
#include <math.h>

#define N 4
#ifndef M_PI
#define M_PI 3.1415927
#endif

fwd_kin(theta, x){

	double *theta;
	double x[3];
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
	double thetaValue = 30;
	char axis = 'z';
	double displacement = 10;

	calculate_disp_matrix(axis, displacement, matDisp);
	calculate_rot_matrix(axis, thetaValue, matRotate);

}

double** multiply(int **mat1, int **mat2, int **res)
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

void calculate_disp_matrix(char axis, double displacement, double matDisp[N][N]) {
	
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
}

void calculate_rot_matrix(char axis, double thetaValue, double **matRotate) {

	double s;
	double c;
	double minusS;
	
	double val = M_PI / 180.0;
	c = cos(thetaValue*val);
	s = sin(thetaValue*val);
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


}


inv_kin(x, theta)
double *x;
double theta[6];
{
}