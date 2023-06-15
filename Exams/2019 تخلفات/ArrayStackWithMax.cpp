//Q3
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack
{
    enum{DEF_CAPACITY = 100};
    public:
        ArrayStack(int cap = DEF_CAPACITY);
        const int size();
        bool empty();
        const T& top();
        void push(const T& d);
        void pop();
        T& getMax();
    private:
        T* S;
        T* S_with_max;
        int capacity;
        int t;

};


template <typename T> 
ArrayStack<T>::ArrayStack(int cap) : S(new T[cap]), S_with_max(new T[cap]),  t(-1), capacity(cap)
{}

template <typename T>
const int ArrayStack<T>::size()
{
    return t+1;
}

template <typename T>
bool ArrayStack<T>::empty()
{
    return (t==-1);
}

template <typename T>
const T& ArrayStack<T>::top()
{
    try
    {
        if(t==-1)
        {
            throw("Stack is empty!");
        }
        return S[t];
    }
    catch(const char* cerr)
    {
        cout<<cerr<<endl;
    }
    return 0;
}

template <typename T>
void ArrayStack<T>::push(const T& d)
{
    try
    {
        if(size() == capacity)
        {
            throw("Stack is full!");
        }
        t++;
        S[t] = d;
        if(t==0)
        {
            S_with_max[t] = d;
        }      
        else
        {
            if(d>S_with_max[t-1])
                S_with_max[t] = d;
            else
                S_with_max[t] = S_with_max[t-1];
        }
    }
    catch(const char* cerr)
    {
        cout<<cerr<<endl;
    }
    
}

template <typename T>
void ArrayStack<T>::pop()
{
    try
    {
        if(empty())
        {
            throw("Stack is empty!");
        }
        t--;
    }
    catch(const char* cerr)
    {
        cout<<cerr<<'\n';
    }
    
}
template <typename T>
T& ArrayStack<T>::getMax()
{
    return (S_with_max[t]);
}

int main()
{
    ArrayStack<int>my_stack;
    my_stack.push(12);
    my_stack.push(134);

    my_stack.push(7);
    my_stack.push(13);
    cout<<my_stack.getMax();
}

