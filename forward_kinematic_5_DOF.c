#include <stdio.h>
#include <math.h>

#define N 4
#ifndef M_PI
#define M_PI 3.1415927
#endif



void multiply(int mat1[][N], int mat2[][N], int res[][N])
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


void calculate_rot_matrix(char axis, double thetaValue, double matRotate[N][N]) {

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


