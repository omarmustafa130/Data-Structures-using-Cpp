//sort an array of 0,1,2

#include <iostream>
using namespace std;

void sortArray(int* A, int n)
{
    int counter_0 = 0;
    int counter_2 = n-1;
    int temp;
    for(int i = 1; i<=counter_2; i++)
    {
        if(A[i] == 2)
        {
            temp = A[i];
            A[i] = A[counter_2];
            A[counter_2] = temp;
            counter_2--;
            i--;
        }
        else if(A[i] == 0)
        {
            temp = A[i];
            A[i] = A[counter_0];
            A[counter_0] = temp;
            counter_0++;
        }

    }
}

int main()
{
    int m = 20;
    int A[m] = {2,1,2,1,2,1,0,1,0,1,1,0,1,2,0,1,0,2,1,2};
    sortArray(A, m);
    for(int i =0; i<m; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}