#include <iostream>
#include <stdlib.h>

using std::size_t;

void fix(int &n, int limit)
{
	while (n < 0) n+=limit;
	n %= limit;
}

struct Array 
{
	int * data;
	size_t size;


	Array(size_t N)
	{
		size = N;
		data = new int[size];
	}


	~Array()
	{
		delete[] data;
	}


	Array(const Array& A)	
	{
		size = A.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = A.data[i];
	}


	const Array& operator=(const Array& A)
	{
		if (data)
			delete[] data;
		size = A.size;

		data = new int[size];

		for (int i = 0; i < size; i++)
			data[i] = A.data[i];

		return *this;
	}


	int& operator[](int i)
	{  
		fix(i, size);
		return data[i]; 
	}
};
   
std::ostream& operator<<(std::ostream& out, Array &A)
{
	int a;
	for (int i = 0; i < A.size; i++){
		if (i == 0) out << "[";
		out << A[i];
		if (i != A.size-1) out << ", ";
		else out << "]";
	}
	return out;
}


int main() 
{
	int n = 4;
	Array arr1(n);

	for (int i = 0; i < n; i++)
		std::cin >> arr1[i];

	Array arr2(arr1);
	Array arr3 = arr1;
	arr3[1020] = 23;

	std::cout << arr1 << std::endl;
	std::cout << arr2 << std::endl;
	std::cout << arr3 << std::endl;
	

	return 0;
}