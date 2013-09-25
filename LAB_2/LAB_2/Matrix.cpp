#include "Matrix.h"


Matrix::Matrix(void): lengthArray(5),hightArray(5)
{
	Array=new double* [lengthArray];
	for(int i=0; i<lengthArray;i++)
		Array[i]=new double [hightArray];	
	cout<<"������ ������������\n";
}

Matrix::Matrix(int length,int hight): lengthArray(length), hightArray(hight)
{
	if(length!=hight)
	{
		cout<<"Error! length and hight must have the same value";
		exit(1);
	}
	Array=new double* [lengthArray];
	for(int i=0; i<lengthArray;i++)
		Array[i]=new double [hightArray];
	cout<<"������ ����������� � �����������\n";
}
Matrix::~Matrix(void)
{
	for(int i=0; i<lengthArray;i++)
		delete [] Array[i];
	delete [] Array;
	cout<<"������ ����������\n";
}
Matrix::Matrix(const Matrix &ob): lengthArray(ob.lengthArray),hightArray(ob.hightArray)
{
	Array=new double* [this->lengthArray];
	for(int i=0; i<this->lengthArray;i++)
		Array[i]=new double [hightArray];
	for(int i=0;i<this->lengthArray;i++)
		for(int j=0;j<this->hightArray;j++)
			this->Array[i][j]=ob.Array[i][j];
	cout<<"������ ������������ �����\n";
}

Matrix Matrix::operator+(const Matrix& ob1)
{
	if(this->lengthArray!=ob1.lengthArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	Matrix temp;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]+ob1.Array[i][j];
	return temp;
}
Matrix Matrix::operator+(double var)
{
	Matrix temp;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]+var;
	return temp;
}
Matrix Matrix::operator-(const Matrix& ob1)
{
	if(this->lengthArray!=ob1.lengthArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	Matrix temp;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]-ob1.Array[i][j];
	return temp;
}
Matrix Matrix::operator-(double var)
{
	Matrix temp;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]-var;
	return temp;
}
Matrix Matrix::operator*(const Matrix& ob1)
{
	Matrix temp;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			for(int r=0;r<lengthArray;r++)
				temp.Array[i][j]+=Array[i][r]*ob1.Array[r][j];
	return temp;
}
Matrix Matrix::operator*(double var)
{
	Matrix temp;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]*=var;
	return temp;
}
Matrix& Matrix::operator=(const Matrix& ob)
{
	if(this==&ob)
		exit(1);

	if(this->lengthArray!=ob.lengthArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	this->lengthArray=ob.lengthArray;
	this->hightArray=ob.hightArray;
	for(int i=0;i<this->lengthArray;i++)
		for(int j=0;j<this->hightArray;j++)
			this->Array[i][j]=ob.Array[i][j];
	return *this;
}
Matrix& Matrix::operator=(double var)
{
	for(int i=0;i<this->lengthArray;i++)
		for(int j=0;j<this->hightArray;j++)
			this->Array[i][j]=var;
	return *this;
}
double* Matrix::operator[](int index)
{
	return Array[index];
}
const double* Matrix::operator[](int index) const
{
	return Array[index];
}

Matrix& Matrix::operator+=(const Matrix& obj)
{
	if(this->lengthArray!=obj.lengthArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			this->Array[i][j]=this->Array[i][j]+obj.Array[i][j];
	return *this;
}
