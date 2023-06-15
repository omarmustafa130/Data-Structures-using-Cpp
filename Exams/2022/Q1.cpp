#include <iostream>
using namespace std;


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
    private:
        T* S;
        int capacity;
        int t;

};


template <typename T> 
ArrayStack<T>::ArrayStack(int cap) : S(new T[cap]), t(-1), capacity(cap)
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
    return S[t];
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
//int a[] = {1,36,7,18,28,23,24,16,17,38,21,3};
void find(int a[], int size, ArrayStack<int> &s)
{
    for(int i =0; i<size; i++)
    {
        while(! s.empty() && s.top()<a[i])
        {
            s.pop();
        }
        s.push(a[i]);
    }
}

int main()
{
    int a[] = {1,36,7,18,28,23,24,16,17,38,21,3};
    ArrayStack<int> my_stack;
    find(a, 12, my_stack);
    while(!my_stack.empty())
    {
        cout<<my_stack.top()<<'\n';
        my_stack.pop();
    }
    return 0;
}




/*-----------------------------2022 Exam------------------------------*/
//a) What is the stack contents at the end?
//      s = {38,21,3}
//b) What does this function do?
//      مش عارفها
//c) What is the complexity of this function?
//      O(N^2)
//d) What is the output of xxx();
//      4 6 7 9 10
//e) How many times the function will be called?
//      10 times