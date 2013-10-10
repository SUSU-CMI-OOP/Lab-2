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


//const BigInt BigInt::operator+(const BigInt&obj)
//{
//	//BigInt temp;
//	if(this->sign==obj.sign)
//	{
//		if(numbersCount>obj.numbersCount)
//			{
//				BigInt temp=*this;
//			}
//		else
//			{
//			
//			}
//	
//	
//	}
//	
//	
//	/*
//	if (size_a > size_b)
//    length = size_a + 1;
//else
//    length = size_b + 1;
// 
//for (int ix = 0; ix < length; ix++)
//{
//    b[ix] += a[ix]; // суммируем последние разряды чисел
//    b[ix + 1] += (b[ix] / 10); // если есть разряд для переноса, переносим его в следующий разряд
//    b[ix] %= 10; // если есть разряд для переноса он отсекается
//}
// 
//if (b[length - 1] == 0)
//    length--;
//	*/
//}



ostream& operator<<(ostream& outputStream, const BigInt &integer)
{
	if (integer.sign == negative)
		outputStream << '-';

	for (int i = 0; i < integer.numbersCount; i++)
		outputStream << integer.numbers[i];

	return outputStream;
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
	return b < *this;
}
bool BigInt::operator==(const BigInt& b)
{ 
	return !(*this < b || b > *this);
}
bool BigInt::operator>=(const BigInt& b)
{ 
	return (*this > b||*this==b);
}
bool BigInt::operator<=(const BigInt& b)
{ 
	return (b < *this||*this==b);
}