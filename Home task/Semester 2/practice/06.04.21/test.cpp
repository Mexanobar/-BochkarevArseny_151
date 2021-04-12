#include <iostream>
#include "pair.h"

int main()
{
	pair<int, char> pa1(123, 'b');
	pair<int, char> pa2(pa1);
	std::cout << pa2.first() << "\n";

	pair<char, char> pa3('g', 'g');
	std::cout << pa3.first() << pa3.second() << "\n";

	pa2=make_pair(222, 'F');
	std::cout << pa2.first() << pa2.second() << "\n";

	pa2.set_first(1232);
	std::cout << pa2.first() << "\n";

	return 0;
}