#include "BigInt.h"
#include "Matrix.h"


int main(void) 
{
	setlocale(LC_ALL,"Russian");
	Matrix ob1;
	Matrix ob_A(5,5),ob_B(5,5),ob_C(6,6);

	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			ob_A[i][j]=i+j;
			ob_B[i][j]=i*j;
		}
	ob_A.show();
	ob_B.show();
	ob_A*=ob_B;
	ob_A.show();
	ob1=ob_A+ob_B;
	ob1.show();
	//ob_C=ob_A; //Generate exception: code 0x1; 

	BigInt a;
    BigInt b("-1206");   
    BigInt c(1207);       

    a = c;
    if (a != c) cout << "Something wrong\n";
    else cout << "As expected\n";

    if (b < c) cout << "As expected\n";
    else cout << "Something wrong\n";

    cout << b++ << endl
         << c-1 << endl
         << b+=7 << endl;


	system("pause");
    return 0;
}