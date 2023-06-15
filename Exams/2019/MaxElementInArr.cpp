//Q2: get the index of max element in arr
#include <iostream>
using namespace std;

template<typename T>
int getMaxElement(T* arr, int n)
{
    T max = arr[0];
    int indMax = 0;
    for(int i =1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            indMax = i;
        }
    }
    return indMax;
}


int main()
{
    int arr[] = {9,2,3,4};
    cout<<getMaxElement<int>(arr, 4);
    return 0;
    //output: 0
}