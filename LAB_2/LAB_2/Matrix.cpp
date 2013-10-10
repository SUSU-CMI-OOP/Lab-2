#include "Matrix.h"




Matrix::Matrix(void):lengthArray(5), hightArray(5)
{
	Array=new double* [lengthArray];
	for(int i=0; i<lengthArray;i++)
		Array[i]=new double [hightArray];	
	//cout<<"Работа конструктора\n";
}
Matrix::Matrix(int length,int hight):lengthArray(length), hightArray(hight)
{
	if(length!=hight)
	{
		cout<<"Error! length and hight must have the same value";
		exit(1);
	}
	Array=new double* [lengthArray];
	for(int i=0; i<lengthArray;i++)
		Array[i]=new double [hightArray];
	//cout<<"Работа конутрутора с параметрами\n";
}
Matrix::~Matrix(void)
{
	for(int i=0; i<lengthArray;i++)
		delete [] Array[i];
	delete [] Array;
	//cout<<"Работа деструтора\n";
}
Matrix::Matrix(const Matrix &ob):lengthArray(ob.lengthArray), hightArray(ob.hightArray)
{
	Array=new double* [this->lengthArray];
	for(int i=0; i<this->lengthArray;i++)
		Array[i]=new double [hightArray];
	for(int i=0;i<this->lengthArray;i++)
		for(int j=0;j<this->hightArray;j++)
			this->Array[i][j]=ob.Array[i][j];
	//cout<<"Работа конструктора копий\n";
}

Matrix Matrix::operator+(const Matrix& ob1)
{
	if(this->lengthArray!=ob1.lengthArray||this->hightArray!=ob1.hightArray)
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
	if(this->lengthArray!=ob1.lengthArray||this->hightArray!=ob1.hightArray)
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

	if(this->lengthArray!=ob.lengthArray||this->hightArray!=ob.hightArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
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
	if(this->lengthArray!=obj.lengthArray||this->hightArray!=obj.hightArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			this->Array[i][j]+=obj.Array[i][j];
	return *this;
}
Matrix& Matrix::operator+=(double var)
{
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			this->Array[i][j]+=var;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& obj)
{
	if(this->lengthArray!=obj.lengthArray||this->hightArray!=obj.hightArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			this->Array[i][j]-=obj.Array[i][j];
	return *this;
}

Matrix& Matrix::operator-=(double var)
{
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			this->Array[i][j]-=var;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& obj)
{
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
		{
			double temp=0;
			for(int k=0;k<lengthArray;k++)
				temp+=Array[i][k]*obj.Array[k][j];
			this->Array[i][j]=temp;
		}

	return *this;
}
Matrix& Matrix::operator*=(double var)
{
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			this->Array[i][j]*=var;
	return *this;
}

bool Matrix::operator==(const Matrix& obj)
{
	if(hightArray!=obj.hightArray||lengthArray!=obj.lengthArray)
		return false;
	for(int i=0;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			if(Array[i][j]!=obj.Array[i][j])
				return false;
	return true;
}
bool Matrix::operator!=(const Matrix& obj)
{
	return !(*this==obj);
}

ostream& operator<<(ostream& stream, const Matrix& obj)
{
	for(int i=0;i<obj.lengthArray;i++)
	{
		for(int j=0; j<obj.hightArray;j++)
			stream<<obj.Array[i][j];
		cout<<"\n";
	}
	return stream;
}

void Matrix::show(void)
{
	cout<<"\n";
	for(int i=0;i<hightArray;i++)
	{
		for(int j=0; j<lengthArray;j++)
			cout<<Array[i][j]<<" ";
		cout<<"\n";
	}
}