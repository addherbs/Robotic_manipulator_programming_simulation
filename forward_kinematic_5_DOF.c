##include <stdio.h>
#include <math.h>

#define N 4
#ifndef M_PI
#define M_PI 3.1415927
#endif


double **multiplyMatrix(double mat1[][N], double mat2[][N], double result[][N]) {

	int i, j, k,x;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			result[i][j] = 0.0;
			for (x = 0; x < N; x++) {
				(*(*(result + i) + j)) += (*(*(mat1 + i) + x)) * (*(*(mat2 + x) + j));
			}
		}
	}
}


int translation(double x, double y, double z, double D[][N]) {
	double D1[N][N] = { { 1,0,0,x },{ 0,1,0,y },{ 0,0,1,z },{ 0,0,0,1 } };
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			D[i][j] = D1[i][j];
		}
	}
	return 0;
}

int rotationAlongXaxis(double thetaValue, double R[][N]) {

	double s;
	double c;
	int i, j;
	double minusS;

	double val = M_PI / 180.0;
	c = cos(thetaValue);
	s = sin(thetaValue);
	minusS = (-1) * s;


	double Rx[N][N] = { { 1,0,0,0 },
	{ 0,c,minusS,0 },
	{ 0,s,c,0 },
	{ 0,0,0,1 }
	};

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			R[i][j] = Rx[i][j];
		}
	}
	return 0;
}

int rotationAlongYaxis(double thetaValue, double R[][N]) {

	double s;
	double c;
	int i, j;
	double minusS;

	double val = M_PI / 180.0;
	c = cos(thetaValue);
	s = sin(thetaValue);
	minusS = (-1) * s;


	double Ry[N][N] = { { c,0,s,0 },
	{ 0,1,0,0 },
	{ minusS,0,c,0 },
	{ 0,0,0,1 }
	};
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			R[i][j] = Ry[i][j];
		}
	}
	return 0;
}

int rotationAlongZaxis(double thetaValue, double R[][N]) {

	double s;
	double c;
	int i, j;
	double minusS;

	double val = M_PI / 180.0;
	c = cos(thetaValue);
	s = sin(thetaValue);
	minusS = (-1) * s;


	double Rz[N][N] = { { c,minusS,0,0 },
	{ s,c,0,0 },
	{ 0,0,1,0 },
	{ 0,0,0,1 }
	};
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			R[i][j] = Rz[i][j];
		}
	}
	return 0;
}


fwd_kin(theta, x)
double *theta;
double x[3];
{
	double l0 = 0.25, l1 = 0.25, l2 = 0.25, l3 = 0.15;
	double d1 = 0.05, d2 = 0.05;
	char axis[N];
	
	double Rzt0[N][N], Ryt1[N][N], Ryt2[N][N], Ryt3[N][N], Rxt4[N][N];

	double finalR1[N][N], finalR2[N][N], finalR3[N][N], FinalMatrix[N][N], 
				Transformation1to2[N][N], TransformationBaseto0[N][N], Transformation2to1part1[N][N], 
				Transformation2to3[N][N], Transformation3to4part1[N][N], Transformation3to4part2[N][N], Transformation3to4Final[N][N];
	
	double DisplaceZL0[N][N],DisplaceXL1[N][N],DisplaceXL2[N][N],DisplaceYD1[N][N],DisplaceZL2[N][N],DisplaceXL3[N][N];

	axis[0] = 'x';
	axis[1] = 'y';
	axis[2] = 'z';
	
	
	translation(0, 0, l0, DisplaceZL0);

	translation(0, d1, 0, DisplaceYD1);
	translation(0, 0, d2, DisplaceZL2);

	translation(l1, 0, 0, DisplaceXL1);
	translation(l2, 0, 0, DisplaceXL2);
	translation(l3, 0, 0, DisplaceXL3);

	rotationAlongZaxis(theta[0], Rzt0);
	rotationAlongYaxis(theta[1], Ryt1);
	rotationAlongYaxis(theta[2], Ryt2);
	rotationAlongYaxis(theta[3], Ryt3);
	rotationAlongYaxis(theta[N], Rxt4);


	multiplyMatrix(DisplaceXL3, Rxt4, Transformation3to4part1);
	multiplyMatrix(DisplaceZL2, Transformation3to4part1, Transformation3to4part2);
	multiplyMatrix(DisplaceYD1, Transformation3to4part2, Transformation3to4Final);

	multiplyMatrix(DisplaceXL2, Ryt3, Transformation2to1part1);
	multiplyMatrix(DisplaceYD1, Transformation2to1part1, Transformation2to3);


	multiplyMatrix(DisplaceXL1, Ryt2, Transformation1to2);

	multiplyMatrix(DisplaceZL0, Rzt0, TransformationBaseto0);


	multiplyMatrix(Transformation2to3, Transformation3to4Final, finalR1);
	multiplyMatrix(Transformation1to2, finalR1, finalR2);
	multiplyMatrix(Ryt1, finalR2, finalR3);
	multiplyMatrix(TransformationBaseto0, finalR3, FinalMatrix);

	x[0] = FinalMatrix[0][3];	x[1] = FinalMatrix[1][3];	x[2] = FinalMatrix[2][3];

}



inv_kin(x, theta)
double *x;
double theta[6];
{
}