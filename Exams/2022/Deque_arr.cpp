/*Write a deque class without inheritance 
or objects from any other class or structure*/
// = Deque with array
#include <iostream>
using namespace std;

typedef unsigned int Elem;

class DequeArr
{
    private:
        Elem* arr;
        int capacity;
        int t;
    public:
        DequeArr(int cap);
        int size();
        bool empty();
        Elem front();
        Elem back();
        void insertFront(const Elem& d);
        void insertBack(const Elem& d);
        void removeFront();
        void removeBack();
        void PrintQueue();
};

DequeArr::DequeArr(int cap = 10) : capacity(cap), arr(new Elem[capacity]), t(-1)
{}
int DequeArr::size()
{
    return (t+1);
}
bool DequeArr::empty()
{
    return (t==-1);
}
Elem DequeArr::front()
{
  return arr[0];  
}
Elem DequeArr::back()
{
    return arr[t];
}
void DequeArr::insertFront(const Elem& d)
{
    if(t+1 < capacity)
    {
        for(int i=t+1; i>0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = d;
        t++;
    }
}
void DequeArr::insertBack(const Elem& d)
{
    if(t+1 < capacity)
    {
        t++;
        arr[t] = d;
    }
}
void DequeArr::removeFront()
{
    for(int i = 0; i<t; i++)
    {
        arr[i] = arr[i+1];
    }
    t--;
}
void DequeArr::removeBack()
{
    t--;
}

//for testing
void DequeArr::PrintQueue()
{
    for(int i =0; i<=t; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    DequeArr D(10);
    D.insertFront(1);
    D.insertBack(2);
    D.insertBack(3);
    D.insertBack(4);
    D.insertBack(5);
    cout<<"the size is : "<<D.size()<<endl;
    D.PrintQueue();
    cout<<endl;
    D.removeBack();
    D.PrintQueue();
    cout<<endl;
    D.removeFront();
    D.PrintQueue();
    cout<<endl;
    return 0;
    /*Output:
    the size is : 5
    1 2 3 4 5 
    1 2 3 4 
    2 3 4 
    */
}