/*--------------Vector complete tree------------*/
#include <iostream>
#include <vector>
using namespace std;

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


int main()
{
    VectorCompleteTree<int> VCT;
    VCT.addLast(1);
    cout<<"Expected size is: 1 --- Output size is: "<<VCT.size()<<endl;
    cout<<"Expected output is: 1 --- Output  is: "<<*(VCT.root())<<endl;
    VCT.addLast(2);
    VCT.swap(VCT.root(), VCT.left(VCT.root()));
    cout<<"Expected size is: 2 --- Output size is: "<<VCT.size()<<endl;
    cout<<"Expected output is: 2 --- Output  is: "<<*(VCT.root())<<endl;

    return 0;
}