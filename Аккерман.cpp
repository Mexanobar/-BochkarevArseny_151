﻿#include <iostream>

using namespace std; 

long akk(int n, int m)
{
	if (n == 0)
		return m + 1;
	else if ((n != 0) && (m == 0))
		return akk(n - 1, 1);
	else if ((n > 0) && (m > 0))
		return akk(n - 1, akk(n, m - 1));
}

int main()
{
	cout << akk(3, 2);

	return 0;
}