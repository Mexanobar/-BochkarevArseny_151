#include <iostream>

class AoA
{
    private:
        size_t m;
        int** A;
        int* data;
    public:
        AoA(int* Array_k, size_t m);
        ~AoA();
        AoA(const AoA& A);
        const AoA& operator=(const AoA& A);
        int get(size_t i, size_t j);
        void set(size_t i, size_t j, int val);
};

AoA::AoA(int* Array_k, size_t m): m(m), A(new int*[m])
{
    size_t size{0};
    for (int i{0}; i < m; i++) size += Array_k[i];
    data = new int[size];
    int temp{0};
    for (int i{0}; i < m; i++)
    {
        A[i] = data + temp;
        temp += Array_k[i];
    }
}

int AoA::get(size_t i, size_t j)
{
    if (i >= m) 
        throw "Out of m";
    if (j >= (size_t)(A[i] - A[i+1])) 
        throw "Out of k[i]";
    return A[i][j];
}

void AoA::set(size_t i, size_t j, int val)
{
    if (i >= m)
        throw "Out of m";
    if (j >= (size_t)(A[i] - A[i+1])) 
        throw "Out of k[i]";

    A[i][j] = val;
}

AoA::~AoA()
{
    delete[] A;
    delete[] data;
}

int main() 
{
    size_t size{10};
    int *A = new int[size];

    for (int i{0}; i < size; i++)
        A[i] = i;

    AoA B(A, size);

    try 
    {
        for (int i{0}; i < size; i++) 
            for (int j{0}; j < A[i]; j++)
                B.set(i, j, i + 3);
    }
    catch (const char* error_msg)
    {
        std::cout << error_msg << "\n";
    }

    try 
    {
        for (int i{0}; i < size; i++)
        {
            std::cout << "\n";
            for (int j{0}; j < A[i]; j++)
                std::cout << B.get(i, j) << " ";
        }
    }
    catch (const char* error_msg)
    {
        std::cout << error_msg << "\n";
    }

    return 0;
}