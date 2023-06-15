//a) what is the complexity of each function:
//the function on the left: O(N^2), lef: O(N)

#include <iostream>
using namespace std;
float fun1(int a[], int n, float x)
{
    float s=a[n];
    for(int i = n-1; i>=0; i--)
    {
        s=s*x+a[i];
    }
    return s;
}

float fun1_recursive(int a[], int n, float x)
{
    static int i = 0;
    if(i == n-1)
        return a[i];
    
    else
    {
        i++;
        float s = fun1_recursive(a, n,x);
        i--;
        return (x*s + a[i]);
    }
    
    
}