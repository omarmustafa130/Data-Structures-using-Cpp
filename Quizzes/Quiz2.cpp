// Function to find the elements in x but not in y
#include <iostream>
using namespace std;

int findElements(int* x, int* y, int* z, int m, int n)
{

    int i=0, j=0, k=0;
    while(i<m && j< n)
    {
        if(x[i] < y[j])
        {
            z[k]= x[i];
            k++; i++;
        }

        else if(x[i]>y[j])
        {
            j++;
        }
        else
            i++;
    }
    while(i<m)
    {
        z[k] = x[i];
        i++; k++;
    }
    return k;
}

int main()
{
    int m = 6;
    int n = 5;
    int x[m] = {1,2,3,4,5,6};
    int y[n] = {1,2,3,4,5};
    int z[m];
    int count = findElements(x,y,z,m, n);
    for (int i = 0; i < count; i++)
		cout << z[i] << " "; //Should be 1, 3, 5, 7, 9
    return 0;
}