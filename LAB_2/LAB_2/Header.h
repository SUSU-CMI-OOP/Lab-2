#include <iostream>
using namespace std;
#pragma once
#define MaxMatrixSize 100 

class Matrix
{
private:
	double** Array;
	//int sizeArray;
	int lengthArray;
	int hightArray;
public:
	Matrix();
	Matrix(int,int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator+ (Matrix&);
	Matrix operator+ (double);
	Matrix operator- (Matrix&);
	Matrix operator- (double);
	Matrix operator* (Matrix&);
	Matrix operator* (double);
	double& operator[](int);
	Matrix& operator= (Matrix&);
	Matrix& operator= (double);

};