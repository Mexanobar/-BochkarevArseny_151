template <typename T>
void swap(T& a, T& b)
{
  T c{a};
  a = b;
  b = c;
}



template <typename T>
void makeHeap(T*& arr, int n, int i)
{
    int max{i};    

    int l{2*i + 1}; 
    int r{2*i + 2}; 
 
    if (l < n && arr[l] > arr[max])
        max = l;
 
    if (r < n && arr[r] > arr[max])
        max = r;
 
    if (max != i)
    {
        swap(arr[i], arr[max]); 
        makeHeap(arr, n, max);
    }
}



template <typename T>
void heapSort(T*& arr, int n)
{ 
    for (int i{n / 2 - 1}; i >= 0; i--)
        makeHeap(arr, n, i);
 
    for (int i{n-1}; i>=0; i--)
    { 
        swap(arr[0], arr[i]); 
        makeHeap(arr, i, 0);
    }
} 