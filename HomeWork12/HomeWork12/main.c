#define R3 3
#define R4 4
#define C3 3
#define N3 3
#define N4 4

#include <stdio.h>
#include <stdlib.h>

//Exercise 1
double *avgRow(int Mat[][C3]);
//Exercise 2
int *diffRowCol(int Mat[][N3]);
//Exercise 3
int scalarMultiplicationMatrix(int Mat[][N4]);
//Exercise 4
int isSymmetric(int Mat[][N3]);
//Exercise 5
int isDiagonalsSorted(int Mat[][N4]);
//Exercise 6
void binSearchDiagonalSorted(int Mat[][N4], int key, int *rowPtr, int *colPtr);
//Exercise 7
int isFullySorted(int Mat[][C3]);
//Exercise 8
void binSearchFullySorted(int Mat[][C3], int key, int *rowPtr, int *colPtr);
//Exercise 9
int allAppear(int Mat[][N3]);
//Exercise 10
void swap(int *num1, int *num2);
void rotateDown(int Mat[][C3]);
//Exercise 11
void rotate90(int Mat[][N3]);
void rotate90NoTempMat(int Mat[][N3]);



void main() { }

//Exercise 1
double *avgRow(int Mat[][C3])
{
	double *avgArr = (double*)malloc(R3 * sizeof(double));
	int i, j;
	for (i = 0; i < R3; i++) {
		avgArr[i] = 0;
		for (j = 0; j < C3; j++) {
			avgArr[i] += Mat[i][j];
		}
		avgArr[i] /= C3;
	}
	return avgArr;
}
//Exercise 2
int *diffRowCol(int Mat[][N3])
{
	int *diff = (int*)malloc(N3 * sizeof(int));
	int i, j;
	for (i = 0; i < N3; i++) {
		diff[i] = 0;
		for (j = 0; j < N3; j++)
			diff[i] += (Mat[i][j] - Mat[j][i]);
	}
	return diff;
}
//Exercise 3
int scalarMultiplicationMatrix(int Mat[][N4])
{
	int scalar = 0, i;
	for (i = 0; i < N4; i++)
		scalar += (Mat[i][i] * Mat[i][N4 - 1 - i]);
	return scalar;
}
//Exercise 4
int isSymmetric(int Mat[][N3])
{
	int i, j;
	for (i = 1; i < N3; i++)
		for (j = 0; j < i; j++)
			if (Mat[i][j] != Mat[j][i])
				return 0;
	return 1;
}
//Exercise 5
int isDiagonalsSorted(int Mat[][N4])
{
	int i;
	for (i = 1; i < N4; i++)
		if (Mat[i][i] < Mat[i - 1][i - 1])
			return 0;
	if (Mat[0][N4 - 1] < Mat[N4 - 1][N4 - 1])
		return 0;
	for (i = 1; i < N4; i++)
		if (Mat[i][N4 - 1 - i] < Mat[i - 1][N4 - i])
			return 0;
	return 1;
}
//Exercise 6
void binSearchDiagonalSorted(int Mat[][N4], int key, int *rowPtr, int *colPtr)
{
	int low, mid, high;
	low = 0;
	high = 2 * N4 - 1;
	*rowPtr = -1;
	*colPtr = -1;
	while (low <= high) {
		mid = (high - low) / 2 + low;
		if (mid < N4) {
			if (Mat[mid][mid] == key) {
				*rowPtr = mid;
				*colPtr = mid;
				break;
			}
			if (Mat[mid][mid] < key)	low = mid + 1;
			else 	high = mid - 1;
		}
		else {
			if (Mat[mid - N4][2 * N4 - 1 - mid] == key) {
				*rowPtr = mid - N4;
				*colPtr = 2 * N4 - 1 - mid;
				break;
			}
			if (Mat[mid - N4][2 * N4 - 1 - mid] < key)	low = mid + 1;
			else	high = mid - 1;
		}
	}
}
//Exercise 7
int isFullySorted(int Mat[][C3])
{
	int i;
	int *oneDimPtr = (int*)Mat;
	for (i = 1; i < R4 * C3; i++)
		if (oneDimPtr[i] < oneDimPtr[i - 1])
			return 0;
	return 1;
}
//Exercise 8
void binSearchFullySorted(int Mat[][C3], int key, int *rowPtr, int *colPtr)
{
	int low, mid, high;
	int *oneDimPtr = (int*)Mat;
	low = 0;
	high = R4 * C3 - 1;
	*rowPtr = -1;
	*colPtr = -1;
	while (low <= high) {
		mid = (high - low) / 2 + low;
		if (oneDimPtr[mid] == key) {
			*rowPtr = (mid / C3);
			*colPtr = (mid % C3);
			break;
		}
		if (oneDimPtr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
}
//Exercise 9
int allAppear(int Mat[][N3])
{
	int count[N3 * N3] = { 0 };
	int i, j;
	for (i = 0; i < N3; i++)
		for (j = 0; j < N3; j++) {
			if (Mat[i][j] < 1 || Mat[i][j] > N3 * N3)
				return 0;
			count[Mat[i][j] - 1]++;
			if (count[Mat[i][j] - 1] > 1)
				return 0;
		}
	return 1;
}
//Exercise 10
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void rotateDown(int Mat[][C3])
{
	int i, j, temp;
	for (j = 0; j < C3; j++) {
		temp = Mat[R4 - 1][j];
		for (i = R4 - 1; i >= 1; i--)
			swap(&Mat[i][j], &Mat[i - 1][j]);
		Mat[0][j] = temp;
	}
}
//Exercise 11
void rotate90(int Mat[][N3])
{
	int temp[N3][N3];
	int i, j;
	for (i = 0; i < N3; i++)
		for (j = 0; j < N3; j++)
			temp[j][N3 - 1 - i] = Mat[i][j];
	for (i = 0; i < N3; i++)
		for (j = 0; j < N3; j++)
			Mat[i][j] = temp[i][j];
}
void rotate90NoTempMat(int Mat[][N3])
{
	int i, j;
	//Transpose Matrix
	for (i = 1; i < N3; i++)
		for (j = 0; j < i; j++)
			swap(&Mat[i][j], &Mat[j][i]);
	//Flip Matrix
	for (i = 0; i < N3; i++)
		for (j = 0; j < N3 / 2; j++)
			swap(&Mat[i][j], &Mat[i][N3 - 1 - j]);
}