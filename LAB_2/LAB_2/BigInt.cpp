#include "BigInt.h"


BigInt::BigInt(void)
{
	sign=zero;
	numbers=NULL;
}
BigInt::BigInt(char* str)
{
	if(str != NULL)
	{
		if (str[0] == '0' && strlen(str) == 1)
		{
			sign = zero;
			numbersCount = 1;
			numbers = new int [numbersCount];
			numbers[0] = 0;
		}
		else
			if (str[0] == '-' && strlen(str) > 1)
			{
				sign = negative;
				numbersCount = strlen(str) - 1;
				numbers = new int [numbersCount];

				for (int i = 1; i < numbersCount; i++)
					numbers[i] = str[i];
			}
			else
				if (str[0] >= '1' && str[0] <= '9')
				{
					sign = positive;
					numbersCount = strlen(str);
					numbers = new int [numbersCount];

					for (int i = 0; i < numbersCount; i++)
						numbers[i] = str[i];
				}
	}
}
BigInt::BigInt(long int integer)
{
	if (integer == 0)
	{
		sign = zero;
		numbersCount = 1;
		numbers = new int [numbersCount];
		numbers[0] = 0;
	}
	else
	{
		if (integer < 0)
		{
			sign = negative;
			integer = -integer;
		}
		else
		{
			sign = positive;
		}

		numbersCount = 0;
		long int temp = integer;

		while (integer / 10 != 0)
		{
			numbersCount++;
			integer /= 10;
		}

		numbersCount++;
		numbers = new int [numbersCount];
		integer = temp;

		for (int i = 0; i < numbersCount; i++)
		{
			numbers[numbersCount - i - 1] = integer % 10;
			integer /= 10;
		}
	}
}
BigInt::BigInt(const BigInt &object) 
{
	sign=object.sign; 
	numbersCount=object.numbersCount;
	numbers = new int [numbersCount];

	for (int i = 0; i < numbersCount; i++)
		numbers[i] = object.numbers[i];
}

BigInt::~BigInt(void)
{
	delete [] numbers;
}
ostream& operator<<(ostream& outputStream, const BigInt &integer)
{
	if (integer.sign == negative)
		outputStream << '-';

	for (int i = 0; i < integer.numbersCount; i++)
		outputStream << integer.numbers[i];

	return outputStream;
}
void BigInt::Reverce() 
{
	
}
bool BigInt::operator<(const BigInt& b)
{
	if (this->sign == negative && (b.sign == positive || b.sign == zero))
		return true;
	else
		if((this->sign==zero||this->sign==positive)&&(b.sign == positive || b.sign == zero))
		{
			if (this->numbersCount < b.numbersCount)
				return true;
			else
			{
				if (this->numbersCount == b.numbersCount)			
				{
					for (int i = 0; i < this->numbersCount; i++)				
						if (this->numbers[i] < b.numbers[i])			
							return true;
						else
							return false;
				}	
				return false;
			}
		}
		else
			{return false;}		
}
bool BigInt::operator>(const BigInt& b)
{ 
	return !(*this<b);
}
bool BigInt::operator==(const BigInt& b)
{ 
	return !(*this < b || *this > b);
}
bool BigInt::operator>=(const BigInt& b)
{ 
	return (*this > b||*this==b);
}
bool BigInt::operator<=(const BigInt& b)
{ 
	return (*this<b ||*this==b);
}
BigInt& BigInt::operator=(const BigInt &integer)
{
	if(this==&integer)
	{
		exit(0x1);
	}
	this->sign = integer.sign;
	this->numbersCount = integer.numbersCount;

	for (int i = 0; i < integer.numbersCount; i++)
		this->numbers[i] = integer.numbers[i];
	return *this;
}
BigInt& BigInt::operator+=(const BigInt &ob)
{
	*this=*this+ob;
	return *this;
}
BigInt& BigInt::operator-=(const BigInt &ob)
{
	*this=*this-ob;
	return *this;
}
BigInt& BigInt::operator*=(const BigInt &ob)
{
	*this=*this * ob;
	return *this;
}

BigInt& BigInt::operator++ ()
{
	*this+=1;
	return *this;
}
BigInt& BigInt::operator++ (int)
{
	*this+=1;
	return *this;
}
BigInt& BigInt::operator-- ()
{
	*this-=1;
	return *this;
}
BigInt& BigInt::operator-- (int)
{
	*this-=1;
	return *this;
}
const BigInt BigInt::operator+(const BigInt &ob)
{
	
	BigInt temp1;	
	BigInt temp2;
	BigInt result;
	temp1.numbersCount=this->numbersCount;
	temp1.sign=this->sign;
	for (int i=0;i<numbersCount;i++) 
		temp1.numbers[i]=this->numbers[i];

	temp2.numbersCount=ob.numbersCount;
	temp2.sign=ob.sign;
	for (int i=0;i<numbersCount;i++) 
		temp2.numbers[i]=ob.numbers[i];      //����������� ������ �����
	temp1.Reverce();
	temp2.Reverce();
	if (temp1.sign==temp2.sign) //���� ���� ����
	{
		result.sign=temp1.sign;
		int newsize;
		if (temp1.numbersCount>temp2.numbersCount) 
			newsize=temp1.numbersCount;
		else 
			newsize=temp2.numbersCount;
		for (int i=0;i<this->numbersCount;i++)  
			result.numbers[i]=temp1.numbers[i]+temp2.numbers[i];  //���������� ����������
		if (result.numbers[newsize-1]>9) 
			newsize++;                                //�������� ����� ������
		result.numbersCount=newsize;
		for (int i=0;i<newsize;i++)
		{
			if (result.numbers[i]>9)
			{
				result.numbers[i]=result.numbers[i]%10;
				result.numbers[i+1]=result.numbers[i+1]+1;
			} //����������� ������������, � ������ �������� � ������� �������
		}
		result.Reverce();
		*this=result;
		return *this;
	}
	else //���� ������ �� ������
	{
	 BigInt mytemp;
	 if (temp1.sign=='-')
	 {
	  mytemp=temp2;
	  temp2=temp1;
	  temp1=mytemp;
	 }
	 
 if (temp1.numbersCount>temp2.numbersCount){
  int newnumbersCount;
  newnumbersCount=temp1.numbersCount; //��������������� ������
  result.sign=temp1.sign;
  for (int i=0;i<newnumbersCount;i++) result.numbers[i]=temp1.numbers[i]-temp2.numbers[i];
  for (int i=0;i<newnumbersCount;i++){
	  if (result.numbers[i]<0){result.numbers[i]=result.numbers[i]+10;result.numbers[i+1]=result.numbers[i+1]-1; //����������� ������������, � ������ �������� � ������� �������
   }
  }
  while (result.numbers[newnumbersCount-1]==0) --newnumbersCount;
  result.numbersCount=newnumbersCount;
  result.Reverce();
  *this=result;
  return *this;
 }
 if (temp1.numbersCount<temp2.numbersCount){
  int newnumbersCount;
  result.sign=temp2.sign;
  newnumbersCount=temp2.numbersCount;
  for (int i=0;i<newnumbersCount;i++) result.numbers[i]=temp2.numbers[i]-temp1.numbers[i];
  for (int i=0;i<newnumbersCount;i++){
   if (result.numbers[i]<0) {result.numbers[i]=result.numbers[i]+10;result.numbers[i+1]=result.numbers[i+1]-1;
   }
  }
  while (result.numbers[newnumbersCount-1]==0) --newnumbersCount;
  result.numbersCount=newnumbersCount;
  result.Reverce();
  *this=result;
  return *this;
 }
 else
 {
  temp1.Reverce();
  temp2.Reverce();
  int p=0;// <- ��� ����� ����� ���������� ������ temp1 ��� temp2. 1- temp1>temp2; 2-temp1<temp2; 3-��� �����
  for (int i=0;i<temp1.numbersCount;i++){
   if (temp1.numbers[i]>temp2.numbers[i]){ p=1; break;}
   if (temp1.numbers[i]<temp2.numbers[i]){ p=2; break;}
   if (temp1.numbers[i]==temp2.numbers[i]){p=3;}
  };
  //������ ����� ��� ������ � ����� ����������� ����� �����
  temp1.Reverce();
  temp2.Reverce();
  if (p==1)
  {
   result.sign=temp1.sign;
   int newnumbersCount=0;
   newnumbersCount=temp1.numbersCount;
   for (int i=0;i<newnumbersCount;i++){result.numbers[i]=temp1.numbers[i]-temp2.numbers[i];}
   for(int i=0;i<newnumbersCount;i++){
    if (result.numbers[i]<0){result.numbers[i]=result.numbers[i]+10;result.numbers[i+1]=result.numbers[i+1]-1;
    }
   }
   while (result.numbers[newnumbersCount-1]==0) --newnumbersCount;//==
   result.numbersCount=newnumbersCount;
   result.Reverce();
   *this=result;
   return *this;
  };
  if (p==2){
   int newnumbersCount;
   result.sign=temp2.sign;
   newnumbersCount=temp2.numbersCount;
   for (int i=0;i<newnumbersCount;i++){ result.numbers[i]=temp2.numbers[i]-temp1.numbers[i];//cout<<result.coef[i];}
   }
   for (int i=0;i<newnumbersCount;i++){
    if (result.numbers[i]<0) {result.numbers[i]=result.numbers[i]+10;result.numbers[i+1]=result.numbers[i+1]-1;
    }
   }
   while (result.numbers[newnumbersCount-1]==0) --newnumbersCount;//==
   result.numbersCount=newnumbersCount;
   result.Reverce();
   *this=result;
   return *this;
  };
  if (p==3){
 
   this->numbers[0]=0;
   this->numbersCount=1;
   this->sign=positive;
   return *this;
  }
 }
}}	
const BigInt BigInt::operator*(const BigInt &A)
{
 BigInt temp1;
 BigInt temp2;
 BigInt result;
 
 temp1.numbersCount=this->numbersCount;
 temp1.sign=this->sign;
 for (int i=0;i<numbersCount;i++) 
	 temp1.numbers[i]=this->numbers[i];  //����������� ������ �����
 
 temp2.numbersCount=A.numbersCount;
 temp2.sign=A.sign;
 for (int i=0;i<numbersCount;i++) temp2.numbers[i]=A.numbers[i];    //����������� ������ �����
 
 //�������������� ��� �����
 temp2.Reverce();
 temp1.Reverce();
 
 //���� ���� ���� � ��� ��
 if (temp1.sign==temp2.sign) result.sign=positive; else result.sign=negative;
  int newnumbersCount, carry, k, j,i;
  //���������� ������
  newnumbersCount=temp1.numbersCount+temp2.numbersCount;
 
  for (i=0;i<temp1.numbersCount;i++)
  {
   carry = 0;
   for (j=0;j<temp2.numbersCount;j++)
   {//�������� ����������
	   k = temp1.numbers[i]*temp2.numbers[j]+result.numbers[i+j] + carry;
    carry = k / 10;//carry - ��� ������� � ������� ������
    result.numbers[i+j]=k-carry*10;
   }
   result.numbers[i+j]=carry;
  }
  while (result.numbers[newnumbersCount-1]==0) --newnumbersCount;
  result.numbersCount=newnumbersCount;
  result.Reverce();
  *this=result;
  return *this;
};
const BigInt BigInt::operator-(const BigInt &ob)
{
	return (*this+ob);
}

