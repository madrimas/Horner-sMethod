#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

double firstMethod(double*, int, double);
double secondMethod(double*, int, double);
double thirdMethod(double*, int, double);

int main()
{
	setlocale(LC_ALL, "");
	mt19937_64 rnd(time(NULL));

	cout << "Podaj stopieñ wielomianu: ";
	int degree;
	cin >> degree;

	double* coefficients = new double[degree + 1];

	for (int i = 0; i < degree + 1; i++)
	{
		uniform_real_distribution <double> dist(-5, 5);
		coefficients[i] = dist(rnd);
	}
	
	cout << "Wielomian wygl¹da nastêpuj¹co: ";
	for (int i = 0; i < degree + 1; i++)
	{
		cout << coefficients[i];
		if ( (i != degree) && (degree - i != 1) )
		{
			cout << "*x^" << degree - i;
		}
		else if (degree - i == 1)
		{
			cout << "*x";
		}
		if ( (coefficients[i+1] >= 0) && (i!=degree) )
		{
			cout << "+";
		}
	}
	cout << endl;

	cout << "Podaj argument dla którego liczona bêdzie wartoœæ wielomianu: ";
	double argument;
	cin >> argument;

	cout << setw(18) << left << "Pierwsza metoda: " << firstMethod(coefficients, degree, argument) << endl;
	cout << setw(18) << left << "Druga metoda: " << secondMethod(coefficients, degree, argument) << endl;
	cout << setw(18) << left << "Trzecia metoda: " << thirdMethod(coefficients, degree, argument) << endl;

	delete[] coefficients;

	system("pause");
	return 0;
}

double firstMethod(double * arrOfCoefficients, int degree, double argument)
{
	double temp = 0;
	for (int i = 0; i < degree; i++)
	{
		temp += pow(argument, (degree - i))*arrOfCoefficients[i];
	}
	temp += arrOfCoefficients[degree];
	return temp;
}

double secondMethod(double * arrOfCoefficients, int degree, double argument)
{
	double temp = 0;
	double tempX = 1;
	for (int i = degree; i >= 0; i--)
	{
		temp += tempX*arrOfCoefficients[i];
		tempX *= argument;
	}
	return temp;
}

double thirdMethod(double * arrOfCoefficients, int degree, double argument)
{
	double temp = arrOfCoefficients[0];
	for (int i = 1; i < degree + 1; i++)
	{
		temp = argument*temp + arrOfCoefficients[i];
	}
	return temp;
}