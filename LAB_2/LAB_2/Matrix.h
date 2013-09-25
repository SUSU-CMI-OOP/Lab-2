#include <iostream>
using namespace std;
#pragma once
#define MaxMatrixSize 100 

class Matrix
{
private:
	double** Array;
	//int sizeArray;
	const int lengthArray;
	const int hightArray;
public:
	Matrix();
	Matrix(int,int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator+ (const Matrix&);
	Matrix operator+ (const double);
	Matrix operator- (const Matrix&);
	Matrix operator- (double);
	Matrix operator* (const Matrix&);
	Matrix operator* (double);
	double* operator[](int);
	const double* operator[](int) const;
	Matrix& operator= (const Matrix&);
	Matrix& operator= (double);
	Matrix& operator+= (const Matrix&);
	Matrix& operator+= (double);
	Matrix& operator-= (const Matrix&);
	Matrix& operator-= (double);
	Matrix& operator*= (const Matrix&);
	Matrix& operator*= (double);
	bool operator== (const Matrix&);
	bool operator!= (const Matrix&);
	ostream& operator<<(const Matrix&);
};

