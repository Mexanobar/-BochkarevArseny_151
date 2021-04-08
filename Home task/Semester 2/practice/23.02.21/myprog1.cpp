#include <iostream>

using std::cout;
using std::cin;


class A
{
	int a;
	double b;
	char c;
	long long d;
	public:
		A(int x, double y, char t, long long z): a(x),b(y),c(t), d(z) {}

};


class help
{
	public:
		int a1;
		double b1;
		char c1;
		long long d1;
		help(int x, double y, char t, long long z) : a1(x), b1(y), c1(t), d1(z) {}
};

int & get_a(A &tst)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	return pb->a1;
}


void put_a(A &tst, int x)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	pb->a1 = x;
}
 
 

double& get_b(A &tst)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	return pb->b1;
}


void put_b(A &tst, double x)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	pb->b1 = x;
}
 
 

char& get_c(A &tst)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	return pb->c1;
}


void put_c(A &tst, char x)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	pb->c1 = x;
}
 
 

long long& get_d(A &tst)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	return pb->d1;
}


void put_d(A &tst, long long x)
{
	void* p = &tst;

	help* pb = static_cast<help* > (p);

	pb->d1 = x;
}
 
 

int main()
{
	A t(1, 0.1, 'a', 123333);

	put_a(t, 123);

	int& temp = get_a(t);
	cout << temp;


	return 0;
}