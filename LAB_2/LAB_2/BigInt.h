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
	int* number;
	unsigned long int numberCount;  
public:
	BigInt();
	BigInt(char *);
	BigInt(long int);
	BigInt(const BigInt&);
	~BigInt();

	const BigInt operator+(const BigInt&);
	const BigInt operator-(const BigInt&);
	const BigInt operator*(const BigInt&);

	friend const BigInt operator+(const BigInt&, const BigInt&);
	friend const BigInt operator-(BigInt&, const BigInt&);
	friend const BigInt operator*(BigInt&, const BigInt&);

	bool operator==(const BigInt&);
	bool operator!=(const BigInt&);
	bool operator<(const BigInt&);
	bool operator>(const BigInt&);
	bool operator<=(const BigInt&);
	bool operator>=(const BigInt&);

	friend bool operator==(const BigInt&, const BigInt &);	
	friend bool operator!=(const BigInt &, const BigInt &);	
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);





};
