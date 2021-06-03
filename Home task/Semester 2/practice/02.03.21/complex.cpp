#include <iostream>
#include <math.h>
using namespace std;

struct Complex
{
    float a, b;

    Complex (float x, float y)
    {
        a = x;
        b = y;
    }

    Complex (Complex &x)
    {
        a = x.a;
        b = x.b;
    }

    Complex& operator += (Complex &x)
    {
        a += x.a;
        b += x.b;
        return *this;
    }

    Complex& operator -= (Complex &x)
    {
        a -= x.a;
        b -= x.b;
        return *this;
    }

    Complex& operator *= (Complex &x)
    {
        float new_a = a*x.a - b*x.b;
        float new_b = a*x.b + x.a*b;
        a = new_a;
        b = new_b;
        return *this;
    }

    Complex& operator /= (Complex &x)
    {
        float new_a = a*x.a + b*x.b;
        float new_b = b*x.a - x.b*a;
        try
        {
            if (x.a*x.a + x.b*x.b != 0) 
            {
                a = new_a / (x.a*x.a + x.b*x.b);
                b = new_b / (x.a*x.a + x.b*x.b);
            }
            else 
                throw "can't divide by zero!\n";
        }
        catch(const char* errMsg)
        {
            std::cout << errMsg;
        }

        return *this;
    }

	Complex& operator = (Complex &x)
	{
	    a = x.a;
	    b = x.b;
	    return *this;
	}


	Complex& conjugate()
	{
		b = -b;	
		return *this;
	}
};

Complex &operator - (Complex x, Complex &y)
{
    return x -= y;
}

Complex &operator + (Complex x, Complex &y)
{
    return x += y;
}

Complex &operator * (Complex x, Complex &y)
{
    return x *= y;
}

Complex &operator / (Complex x, Complex &y)
{
    return x /= y;
}

ostream &operator << (ostream &out, Complex &x)
{
    if (x.b < 0) out << "(" << x.a << " - " << -x.b << "i" << ")";  
    else out << "(" << x.a << " + " << x.b << "i" << ")";
    return out;
}


float abs(Complex &x)
{
	return sqrt(x.a*x.a + x.b*x.b);
}



int main() 
{

    Complex a(10.0, 18.6), b(0, 0); 

    cout << a << " - " << b << " = " << a-b << "\n";
    cout << a << " + " << b << " = " << a+b << "\n";
    cout << a << " * " << b << " = " << a*b << "\n";
    cout << a << " / " << b << " = " << a/b << "\n";
    cout << "|a| = " << abs(a) << "\n";
    
    cout << "a == " << a << "\n";

    cout << "conjugate a == " << a.conjugate();
}
