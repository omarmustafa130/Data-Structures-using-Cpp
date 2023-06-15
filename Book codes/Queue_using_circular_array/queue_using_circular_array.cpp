/*---------------------------Queue using circular array--------------------------*/
#include <iostream>
using namespace std;

template<typename T>
class Queue
{
    enum{DEF_CAPACITY = 100};
    private:
        T* Q;
        int f,r,n;
    public:
        Queue(int cap = DEF_CAPACITY);
        int size();
        bool empty();
        const T& front();
        void enqueue(const T& d);
        void dequeue();
        void printQueue();
};


template<typename T>
Queue<T>::Queue(int cap) : Q(new T[cap]), f(0), r(0), n(0)
{}

template<typename T>
int Queue<T>::size()
{
    return n;
}

template<typename T>
bool Queue<T>::empty()
{
    return (n==0);
}


template<typename T>
const T& Queue<T>::front()
{
    if(!empty())
    {
        return Q[f];
    }
    else
    {
        cout<<"Queue is empty!\n";
        return NULL;
    }
}


template <typename T>
void Queue<T>::dequeue()
{
    if(!empty())
    {
        f = (f+1)%DEF_CAPACITY;
        n--;
    }
    else
    {
        cout<<"Queue is empty!\n";
    }   
}



template <typename T>
void Queue<T>::enqueue(const T& d)
{
    if(size()<DEF_CAPACITY)
    {
        Q[r] = d;
        r=(r+1) % DEF_CAPACITY;
        n++;
    }
    else
    {
        cout<<"Queue is full!\n";
    }   
}


template <typename T>
void Queue<T>::printQueue()
{
    if(!empty())
    {
        for(int i = 0; i<size(); i++)
        {
            cout<<Q[f+i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"Queue is full!\n";
    }   
}


int main()
{
    Queue<int> Q1;
    Q1.enqueue(5);
    Q1.enqueue(3);
    cout<<Q1.front()<<endl;
    Q1.printQueue();
    cout<<"The size is "<<Q1.size()<<endl;
    Q1.dequeue();
    cout<<Q1.front()<<endl;
    Q1.printQueue();
    cout<<Q1.empty()<<'\n';
    return 0;
    /*Output:
    5
    5 3 
    The size is 2
    3
    3 
    0
    */
}

/*---------------------------End of Queue using circular array--------------------------*/
