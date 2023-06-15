/*-----------------Priority Queue using sorted list-------------------*/
#include <iostream>
#include <list>
using namespace std;

//Comparators
template <typename T>
class BottomTop
{
    public:
        bool operator()(const T& p, const T& q)
        {
            return (p<q);
        }
};

//T: type of list elements
//C: type of comparator
template <typename T, typename C>
class ListPriorityQueue
{
    private:
        list<T> L;
        C isLess;           //less than comparator
    public:
        int LPQsize();
        bool empty();
        void insert(const T& e);
        T& min();
        void removeMin();
};

template <typename T, typename C>
int ListPriorityQueue<T,C>::LPQsize()
{
    return(L.size());
}

template <typename T, typename C>
bool ListPriorityQueue<T,C>::empty()
{
    return(L.empty());
}

template <typename T, typename C>
void ListPriorityQueue<T,C>::insert(const T& e)
{
    typename std::list<T>::iterator p;
    p = L.begin();
    while(p!=L.end() && (!isLess(e, *p)))
        ++p;
    L.insert(p,e);
}

template <typename T, typename C>
T& ListPriorityQueue<T,C>::min() 
{
    return L.front();
}

template <typename T, typename C>
void ListPriorityQueue<T,C>::removeMin()
{
    L.pop_front();
}

int main()
{
    BottomTop<int> BT;
    ListPriorityQueue<int, BottomTop<int>> LPQ;
    LPQ.insert(3);
    LPQ.insert(55);
    
    cout<<"expected value is: 3 -- output value is: "<<LPQ.min()<<endl;
    LPQ.insert(1);
    LPQ.insert(2);

    LPQ.removeMin();
    cout<<"expected value is: 2 -- output value is: "<<LPQ.min()<<endl;
   
    return 0;
}