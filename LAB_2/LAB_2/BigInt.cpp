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

				for (int i = 0; i < numbersCount; i++)
					numbers[i] = str[i+1] - '0';
			}
			else
				if (str[0] >= '1' && str[0] <= '9')
				{
					sign = positive;
					numbersCount = strlen(str);
					numbers = new int [numbersCount];

					for (int i = 0; i < numbersCount; i++)
						numbers[i] = str[i] - '0';
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
