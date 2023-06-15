/*-----------------Heap priority queue-------------------*/
#include <iostream>
#include <vector>
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

template <typename T>
class VectorCompleteTree
{
    private:
        vector<T> V;
    public:
        typedef typename vector<T>::iterator Position;
    protected:
        Position pos(int i)
        {
            return V.begin() + i;
        }

        int idx(const Position& p) const
        {
            return p - V.begin();
        }

    public:
        VectorCompleteTree() : V(1)
        {}

        int size() const
        {
            return(V.size()-1);
        }

        Position left(const Position& p)
        {
            return pos(idx(p)*2);
        }

        Position right(const Position& p)
        {
            return pos(idx(p)*2 + 1);
        }

        Position parent(const Position& p)
        {
            return pos(idx(p)/2);
        }

        bool hasLeft(const Position& p)
        {
            return (2*idx(p)<=size());
        }

        bool hasRight(const Position& p)
        {
            return ((2*idx(p) + 1)<=size());
        }

        bool isRoot(const Position& p)
        {
            return (idx(p)==1);
        }

        Position root()
        {
            return pos(1);
        }

        Position last()
        {
            return pos(size());
        }

        void addLast(const T& e)
        {
            V.push_back(e);
        }
        
        void removeLast()
        {
            V.pop_back();
        }

        void swap(const Position& p, const Position& q)
        {
            T e = *p;
            *p = *q;
            *q = e;
        }
};

template <typename T, typename C>
class HeapPriorityQueue
{
    private:
        VectorCompleteTree<T> CT;
        C isLess;
        typedef typename VectorCompleteTree<T>::Position Position;
    public:
        int size();
        bool empty();
        void insert(const T& e);
        const T& min();
        void removeMin();

};




template <typename T, typename C>
int HeapPriorityQueue<T,C>::size()
{
    return CT.size();
}

template <typename T, typename C>
bool HeapPriorityQueue<T,C>::empty()
{
    return (size() == 0);
}

template <typename T, typename C>
void HeapPriorityQueue<T,C>::insert(const T& e)
{
    CT.addLast(e);
    Position v = CT.last();
    while(!CT.isRoot(v))
    {
        Position par = CT.parent(v);
        if(isLess(*v,*par))
        {
            CT.swap(v,par);
            v = par;
        }
        else
            break;
    }
}

template <typename T, typename C>
const T& HeapPriorityQueue<T,C>::min()
{
    return *(CT.root());
}

template <typename T, typename C>
void HeapPriorityQueue<T,C>::removeMin()
{
    if(size() == 1)
    {
        CT.removeLast();
    }
    else
    {
        Position u = CT.root();
        CT.swap(u,CT.last());
        CT.removeLast();
        while(CT.hasLeft(u))
        {
            Position v = CT.left(u);
            if(CT.hasRight(u) && isLess(*(CT.right(u)), *v))
            {
                v = CT.right(u);
            }
            if(isLess(*v, *u))
            {
                CT.swap(u,v);
                u=v;
            }
            else
                break;
        }
    }
    
}




int main()
{

    HeapPriorityQueue<int, BottomTop<int> > HPQ;
    HPQ.insert(1);
    HPQ.insert(2);
    HPQ.insert(3);
    HPQ.insert(4);

    cout<<"Expected size is: 1 --- Output size is: "<<HPQ.min()<<endl;
    HPQ.removeMin();
    cout<<"Expected size is: 2 --- Output size is: "<<HPQ.min()<<endl;

    return 0;
}