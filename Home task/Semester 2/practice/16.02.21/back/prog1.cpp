#include <iostream>
#include <cmath>

using namespace std;

long long fact(long long n)
{
	return (n > 1 ? n*fact(n-1) : 1);
}

double generateSin(double x)
{ 
	long double res{0};

	for (long long i{0}; i < 15; i++) // в силу переполнения типа long long рассчёт пойдёт до n = 14
	{
		res += ((pow(-1, i)) * pow(x, 2*i + 1)) / double(fact(2*i + 1));
	}

	return res;
}


int main()
{
	double x, new_sin;

	cin >> x;

	//cout.setf(ios::scientific);
	cout.precision(10);

	cout << sin(x) << "\n\n";

	new_sin = generateSin(x);


	cout << new_sin;

	return 0;
}