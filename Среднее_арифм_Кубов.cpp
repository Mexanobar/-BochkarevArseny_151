﻿#include <iostream>

using namespace std;

int main()
{
	int n;

	float num, sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		sum += (num * num * num);
	}

	sum = sum / n;

	cout << sum;

	return 0;
}