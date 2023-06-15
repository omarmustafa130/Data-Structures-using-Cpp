//Q5
//(1)_isHeap()
#include <iostream>
using namespace std;

bool isHeap(int* arr, int sz)
{
    for(int i = 0; i<sz/2; i++)
    {
        if(arr[i]>arr[i*2+1] || arr[i]>arr[i*2+2])
            return false;
    }
    return true;
}

//(2)_BottomUpHeap()
void BottomUpHeap(int* arr, int sz)
{
    int temp;
    for(int i = (sz-2)/2; i>=0; i--)
    {
        
        int left = arr[i*2 + 1];
        int right = arr[i*2 + 2];
        if(arr[i]<left && arr[i]<right)
        {

            continue;
        }
        else
        {
            if( left < right)
            {
                temp = left;
                arr[i*2 + 1] = arr[i];
                arr[i] = temp;
            }
            else if(right<left)
            {
                temp = right;
                arr[i*2 + 2] = arr[i];
                arr[i] = temp;

            }   
            else 
                continue;      
        }
    }
}
int main()
{

    int arr[] ={1,5,7,13,28,32,24,11,17,38,21,3,27,33,22};
    cout<<isHeap(arr, 15);
    cout<<endl;
    int arr2[]= {3,7,2,1,4};
    BottomUpHeap(arr, 15);
    for(int i =0; i<15; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<isHeap(arr, 15);
    cout<<endl;
    return 0;
    /*Output:
    1
    1 3 2 7 4 
    */
}

