
#include <iostream>
#include <list>
using namespace std;

class Position
{};
typedef list<Position> PositionList;
template <typename T>
class BinaryTree
{
    private:
        typedef struct Node
        {
            T elem;
            Node* par;
            Node* left;
            Node* right;
            Node() : elem(), par(NULL), left(NULL), right(NULL)
            {}
        }*nodeptr;
    public:
        class Position
        {
            private:
                nodeptr v;
            public:
                Position(nodeptr = NULL);
                T& operator*();
                Position left();
                Position right();
                Position parent();
                bool isRoot();
                bool isExternal();
        };
    
    public:
        BinaryTree();
        int size();
        bool empty();
        Position root();
        PositionList positions();
        void addRoot();
        void expandExternal(const Position& p);
        Position removeAboveExternal(const Position& p);
    protected:
        void preorder(Node* v, PositionList& pl);

    private:
        nodeptr _root;
        int n;
};


template<typename T>
BinaryTree<T>::Position::Position(nodeptr _v = NULL) : v(_v)
{}


template<typename T>
T& BinaryTree<T>::Position::operator*()
{
    return v->elem;
}

template<typename T>
BinaryTree<T>::Position BinaryTree<T>::Position::parent()
{
    return(BinaryTree::Position(v->par));
}


template<typename T>
bool BinaryTree<T>::Position::isRoot()
{
    return (v->par == NULL);
}

template<typename T>
bool BinaryTree<T>::Position::isExternal()
{
    return(v->left == NULL && v->right == NULL);
}

template<typename T>
BinaryTree<T>::Position BinaryTree<T>::Position::left()
{
    return(BinaryTree::Position(v->left));
}


template<typename T>
BinaryTree<T>::Position BinaryTree<T>::Position::right()
{
    return(BinaryTree::Position(v->right));
}

template<typename T>
BinaryTree<T>::BinaryTree() : _root(NULL), n(0)
{}


template<typename T>
int BinaryTree<T>::size()
{
    return n;
}

template<typename T>
bool BinaryTree<T>::empty()
{
    return (n==0);
}

template<typename T>
BinaryTree<T>::Position BinaryTree<T>::root()
{
    return BinaryTree::Position(_root);
}

template<typename T>
PositionList BinaryTree<T>::positions()
{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

template<typename T>
void BinaryTree<T>::addRoot()
{
    _root = new Node;
    n=1;
}

template<typename T>
void BinaryTree<T>::expandExternal(const Position& p)
{
    nodeptr v = p.v;
    v->left = new Node;
    v->right = new Node;
    v->left->par = v;
    v->right->par = v;
    n+=2;
}

template<typename T>
BinaryTree<T>::Position BinaryTree<T>::removeAboveExternal(const Position& p)
{
    nodeptr w = p.v;
    nodeptr v = w->par;
    nodeptr sib = (w==v->left? v->right : v->left);
    if(v==_root)
    {
        _root = sib;
        sib->par = NULL;
    }
    else
    {
        nodeptr gpar = v->par;
        if(v == gpar->left)
        {
            gpar->left = sib;
        }
        else
        {
            gpar->right = sib;
        }
        sib->par = gpar;
    }
    delete w; 
    delete v;
    n-=2;
    return Position(sib);
    

        
}

template<typename T>
void BinaryTree<T>::preorder(Node* v, PositionList& pl)
{
    pl.push_back(Position(v));
    if(v->left !== NULL)
        preorder(v->left, pl);
    if(v->right !=NULL)
        preorder(v->right, pl);
}



template <typename T, typename R> // element and result types
class EulerTour { // a template for Euler tour
    protected:
        struct Result { // stores tour results
            R leftResult; // result from left subtree
            R rightResult; // result from right subtree
            R finalResult; // combined result
        };
        typedef BinaryTree<T> BinaryTree; // the tree
        typedef typename BinaryTree::Position Position; // a position in the tree
    protected: // data member
        const BinaryTree* tree; // pointer to the tree
    public:
        void initialize(const BinaryTree& T) // initialize
        { tree = &T; }
    protected: // local utilities
        int eulerTour(const Position& p) const; // perform the Euler tour
        // functions given by subclasses
        virtual void visitExternal(const Position& p, Result& r) const {}
        virtual void visitLeft(const Position& p, Result& r) const {}
        virtual void visitBelow(const Position& p, Result& r) const {}
        virtual void visitRight(const Position& p, Result& r) const {}
        Result initResult() const { return Result(); }
        int result(const Result& r) const { return r.finalResult; }
};
template <typename T, typename R>
int EulerTour<T,R>::eulerTour(const Position& p) const
{
    Result r = initResult();
    if(p.isExternal())
    {
        visitExternal(p,r);
    }
    else
    {
        visitLeft(p,r);
        r.leftResult = eulerTour(p.left());
        visitBelow();
        r.rightResult = eulerTour(p.right());
        visitRight();
    }
    return result(r);
}

//Q5 - extend euler tour class to test if the heap order property is satisfied
template <typename E, typename R>
class HeapOrderPropertyTest : public EulerTour<E, R> 
{
    protected: // shortcut type names
        typedef typename EulerTour<E, R>::BinaryTree BinaryTree;
        typedef typename EulerTour<E, R>::Position Position;
        typedef typename EulerTour<E, R>::Result Result;
    public:
        void execute(const BinaryTree& T) 
        { // execute the tour
            initialize(T);
            eulerTour(T.root()) << "\n";
        }
    protected: // leaf: return value
        virtual void visitExternal(const Position& p, Result& r) const
        { r.finalResult = (*p).value(); }
        // internal: do operation
        virtual void visitRight(const Position& p, Result& r) const
        { 
            if((*p).value() < r.leftResult && (*p).value()< r.rightResult)
                r.finalResult = (*p).value();
            else
                cout<<"The heap order property is not satisfied!\n";
        }
};
