#include <iostream>

class parent
{
	protected:
		int m_value;
	 
	public:
		parent(int value) : m_value(value){}
		
		virtual ~parent() {}
};
 
class child : public parent
{
	protected:
		std::string m_name;
	 
	public:
		child(int value, std::string name) : parent(value), m_name(name){}
	 
		const std::string& getName() 
		{ 
			return m_name; 
		}
};


parent* getObject(bool b)
{
	if (b)
		return new child(1, "123");
	else
		return new parent(2);
}


int foo(int* ptr)
{
    return (*ptr + 10);
}

int main()
{
	int i{90};
	i = i / 3.6;
	std::cout << "static_cast:\n" << i << "\n";

	i = 90;
	i = static_cast<int>(i / 3.6);
	std::cout << i << "\n\n\n";


	const int val{10};
    const int *ptr{&val};
    int *ptr1{const_cast <int*>(ptr)};
    std::cout << "const_cast:\n" << foo(ptr1) << "\n\n\n";


    int* p = new int(65);
    char* ch {reinterpret_cast<char*>(p)};
    std::cout << "reinterpret_cast:\n" << *p << "\n";
    std::cout << *ch << "\n\n\n";



	parent *par = getObject(true);

    child *c = dynamic_cast<child*>(par); // используем dynamic_cast для конвертации указателя класса Parent в указатель класса Child

    std::cout << "dynamic_cast:\nname of the child is: \n" << c->getName() << '\n';
 
	delete par;

	return 0;
}

