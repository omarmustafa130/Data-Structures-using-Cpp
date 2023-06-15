/*------------------Array Stack----------------------*/
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

int getMax_recursive(ArrayStack<int> S)
{
    int top = S.top();
    S.pop();
    if(S.empty())
    {
        S.push(top);
        return top;
    }
    else
    {
        int max = getMax_recursive(S);
        if(top>max)
        {
            int temp = max;
            max = top;
            S.push(temp);
            S.push(max);
        }
        else
        {
            S.pop();
            S.push(top);
            S.push(max);
        }
        return max;
    }
}
int main()
{
    ArrayStack<int>my_stack;
    my_stack.pop();
    cout<<"the stack size: "<<my_stack.size()<<endl;
    cout<<"is the stack empty? "<<my_stack.empty()<<endl;
    my_stack.push(12);
    my_stack.push(134);
    cout<<"the stack size: "<<my_stack.size()<<endl;
    cout<<"is the stack empty? "<<my_stack.empty()<<endl;
    cout<<my_stack.top()<<endl;
    my_stack.pop();
    cout<<my_stack.top()<<endl;
    cout<<"\n";
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout << A.top() << endl; A.pop();
    A.push(9);
    cout << A.top() << endl;
    cout << A.top() << endl; A.pop();
    ArrayStack<string> B(10);
    B.push("Bob");
    B.push("Alice");
    cout << B.top() << endl;
    B.pop();
    B.push("Eve");
    cout << B.top() << endl;
    /*Output:
    -------------------
    Stack is empty!
    the stack size: 0
    is the stack empty? 1
    the stack size: 2
    is the stack empty? 0
    134
    12

    13
    9
    9
    Alice
    Eve
    */
}
