#include "Header.h"


Matrix::Matrix(void)
{
	lengthArray=5;
	hightArray=5;
	Array=new double* [lengthArray];
	for(int i=0; i<lengthArray;i++)
		Array[i]=new double [hightArray];	
}
Matrix::Matrix(int length,int hight)
{
	if(length!=hight)
	{
		cout<<"Error! length and hight must have the same value";
		exit(1);
	}
	lengthArray=length;
	hightArray=hight;
	Array=new double* [lengthArray];
	for(int i=0; i<lengthArray;i++)
		Array[i]=new double [hightArray];
}


Matrix Matrix::operator+(Matrix& ob1)
{
	if(this->lengthArray!=ob1.lengthArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	Matrix temp;
	for(int i;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]+ob1.Array[i][j];
	return temp;
}
Matrix Matrix::operator+(double var)
{
	Matrix temp;
	for(int i;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]+var;
	return temp;
}
Matrix Matrix::operator-(Matrix& ob1)
{
	if(this->lengthArray!=ob1.lengthArray)
	{
		// Error: defferent size of matrix;
		exit(1);
	}
	Matrix temp;
	for(int i;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]-ob1.Array[i][j];
	return temp;
}
Matrix Matrix::operator-(double var)
{
	Matrix temp;
	for(int i;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]=Array[i][j]-var;
	return temp;
}

Matrix Matrix::operator*(Matrix& ob1)
{
	Matrix temp;
	for(int i;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			for(int r=0;r<lengthArray;r++)
				temp.Array[i][j]+=Array[i][r]*ob1.Array[r][j];
	return temp;
}
Matrix Matrix::operator*(double var)
{
	Matrix temp;
	for(int i;i<lengthArray;i++)
		for(int j=0;j<hightArray;j++)
			temp.Array[i][j]*=var;
	return temp;
}
Matrix& Matrix::operator=(Matrix& ob)
{
	this->sizeArray=ob.sizeArray;
	for(int i=0;i<this->sizeArray;i++)
		for(int j=0;j<this->sizeArray;j++)
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
double& Matrix::operator[](int index)
{
	return *Array[index];
}







int main() 
{
    Matrix a;
    Matrix *b();
    Matrix c(3,3);

   // for (int i = 0; i < 2; i++)
   //     for (int j = 0; j < 2; j++) 
			//b[i][j] = i+j;



    //b *= 2;
    //b = a = b + b; 

    //if (a != b) cout << "Something wrong\n";
    //else cout << "As expected\n";

    //b += c;   // эта строчка работать не должна, потому что матрицы
        // разной размерности складывать нельзя.         

    /*cout << a << endl
        << c << endl
        << b << endl;
*/
    return 0;
}