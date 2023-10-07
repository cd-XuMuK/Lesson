#include <iostream>

using namespace std;

class BigNum
{
public:
	BigNum();
	BigNum(const char *num);
	BigNum(const BigNum& other);
	BigNum& operator = (const BigNum& other);
	BigNum& operator + (const BigNum& other);
	void print();
	~BigNum();

private:
	char intToChar(int a);
	char *num;
};

BigNum::BigNum()
{
	num = nullptr;
}

BigNum::BigNum(const char *num)
{
	int lenght = strlen(num);
	this->num = new char[lenght + 1];

	for (int i = 0; i < lenght; i++) {

		switch (num[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			this->num[i] = num[i];
			break;
		default:
			
			break;
		}
		
	}

	this->num[lenght] = '/0';

}

BigNum::BigNum(const BigNum& other)
{

	int lenght = strlen(other.num);
	this->num = new char[lenght + 1];

	for (int i = 0; i < lenght; i++) {

		switch (num[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			this->num[i] = num[i];
			break;
		default:
			return;
			break;
		}

	}

	this->num[lenght] = '/0';
}

BigNum& BigNum::operator=(const BigNum& other)
{
	if (this->num != nullptr) {
		delete[] num;
	}



	int lenght = strlen(other.num);
	this->num = new char[lenght + 1];

	for (int i = 0; i < lenght; i++) {

		switch (num[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			this->num[i] = num[i];
			break;
		default:
			
			break;
		}

	}

	this->num[lenght] = '/0';

	return *this;
}

BigNum& BigNum::operator+(const BigNum& other)
{
	BigNum newNum;

	int numLenghtOne = strlen(num);
	int numLenghtTwo = strlen(other.num);

	int col;

	int i_1 = num[0];
	int i_2 = other.num[0];

	if (numLenghtOne < numLenghtTwo) 
	{
		newNum.num = new char[numLenghtTwo + 1];
		col = numLenghtTwo;
	}
	else if (numLenghtOne > numLenghtTwo)
	{
		newNum.num = new char[numLenghtOne + 1];
		col = numLenghtOne;
	}
	else 
	{

		int s = (int)num[0] + (int)other.num[0] + 0;

		if (s >= 10) 
		{
			newNum.num = new char[numLenghtOne + 2];
			col = numLenghtOne + 1;
		}
		else 
		{
			newNum.num = new char[numLenghtOne + 1];
			col = numLenghtOne;
		}

	}

	bool ost = false;
	
	for (int i = 0; i < col; i++) {
		if (numLenghtOne >= 0 && numLenghtTwo >= 0) {
			if (!ost) {
				int sum = (int)num[numLenghtOne] + (int)other.num[numLenghtTwo];
				if (sum < 10) {
					newNum.num[col - i] = intToChar(sum);
				}
				else {
					sum = sum % 10;
					ost = true;
					newNum.num[col - i] = intToChar(sum);
				}
			}
			else {
				int sum = (int)num[numLenghtOne - i] + (int)other.num[numLenghtTwo - i] + 1;
				if (sum < 10) {
					newNum.num[col - i] = intToChar(sum);
					ost = false;
				}
				else {
					sum = sum % 10;
					ost = true;
					newNum.num[col - i] = intToChar(sum);
				}
			}
			numLenghtOne--;
			numLenghtTwo--;
		}
		else if (numLenghtOne >= 0) {
			if (ost) {
				int sum = (int)num[numLenghtOne] + 1;
				if (sum < 10) {
					newNum.num[col - i] = intToChar(sum);
					ost = false;
				}
				else {
					sum = sum % 10;
					ost = true;
					newNum.num[col - i] = intToChar(sum);
				}
			}
			else {
				newNum.num[col - i] = num[numLenghtOne];
			}
			numLenghtOne--;
		}
		else if (numLenghtTwo >= 0) {
			if (ost) {
				int sum = (int)other.num[numLenghtTwo] + 1;
				if (sum < 10) {
					newNum.num[col - i] = intToChar(sum);
					ost = false;
				}
				else {
					sum = sum % 10;
					ost = true;
					newNum.num[col - i] = intToChar(sum);
				}
			}
			else {
				newNum.num[col - i] = other.num[numLenghtTwo];
			}
			numLenghtTwo--;
		}

	}
	
	newNum.num[col] = '\0';

	return newNum;
	// TODO: вставьте здесь оператор return
}

void BigNum::print()
{
	cout << num << endl;
}

BigNum::~BigNum()
{
	delete[] this->num;
}

char BigNum::intToChar(int a)
{
	switch (a)
	{
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 0:
		return '0';
		break;
	default:
		break;
	}
	
}

int main()
{
	BigNum a = "555555555555555555555555";
	BigNum b = "5555555555555555555";



	BigNum result;
	result = a + b;
	result.print();
}

