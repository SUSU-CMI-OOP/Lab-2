#include <iostream>
using namespace std;

#pragma once
 
enum Sign
{
	negative = -1,
	zero = 0,
	positive = 1
};

class BigInt
{
private:
	Sign sign;
	int* numbers;
	unsigned long int numbersCount;  
public:
	BigInt(); //+
	BigInt(char *); //+
	BigInt(long int); //+
	BigInt(const BigInt&); //+
	~BigInt(); //+

	const BigInt operator+(const BigInt&);
	const BigInt operator-(const BigInt&);
	const BigInt operator*(const BigInt&);

	bool operator==(const BigInt&); //+
	bool operator!=(const BigInt&); //+
	bool operator<(const BigInt&); //+
	bool operator>(const BigInt&); //+
	bool operator<=(const BigInt&); //+
	bool operator>=(const BigInt&); //+


	BigInt& operator=(const BigInt &integer); //+
	BigInt& operator+=(const BigInt &integer);//+
	BigInt& operator-=(const BigInt &integer);//+
	BigInt& operator*=(const BigInt &integer); //+

	friend ostream& operator<<(ostream&, const BigInt&); //+
	
	BigInt& operator++ (); //Префиксная запись
	BigInt& operator++ (int); //Постфиксная запись
	BigInt& operator-- ();
	BigInt& operator-- (int);
};
