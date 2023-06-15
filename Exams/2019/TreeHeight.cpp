#include <iostream>
#include <list>
#include <queue>
using namespace std;
typedef int Elem;



class BinaryTree
{
    private:
        typedef struct Node
        {
            Elem elem;
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
                typedef list<BinaryTree::Position> PositionList;
                Position(nodeptr v_= NULL);
                nodeptr operator*();
                Position left();
                Position right();
                Position parent();
                PositionList children();
                Elem& value();
                bool isRoot();
                bool isExternal();
        };
    
    public:
        typedef list<BinaryTree::Position> PositionList;
        BinaryTree();
        int size();
        bool empty();
        Position root();
        PositionList positions();
        void addRoot();
        void expandExternal( Position& p);
        Position removeAboveExternal( Position& p);
    protected:
        void preorder(Node* v, PositionList& pl);

    private:
        nodeptr _root;
        int n;
};

typedef list<BinaryTree::Position> PositionList;
typedef list<BinaryTree::Position>::iterator Iterator;

BinaryTree::Position::Position(nodeptr _v) : v(_v)
{}


BinaryTree::nodeptr BinaryTree::Position::operator*()
{
    return v;
}

BinaryTree::Position BinaryTree::Position::parent()
{
    return(BinaryTree::Position(v->par));
}

BinaryTree::PositionList BinaryTree::Position::children()
{
    PositionList pl;
    pl.push_back(BinaryTree::Position(v->left));
    pl.push_back(BinaryTree::Position(v->right));
    return(pl);
}


bool BinaryTree::Position::isRoot()
{
    return (v->par == NULL);
}

Elem& BinaryTree::Position::value()
{
    return v->elem;
}

bool BinaryTree::Position::isExternal()
{
    return(v->left == NULL && v->right == NULL);
}

BinaryTree::Position BinaryTree::Position::left()
{
    return(BinaryTree::Position(v->left));
}


BinaryTree::Position BinaryTree::Position::right()
{
    return(BinaryTree::Position(v->right));
}

BinaryTree::BinaryTree() : _root(NULL), n(0)
{}


int BinaryTree::size()
{
    return n;
}

bool BinaryTree::empty()
{
    return (n==0);
}

BinaryTree::Position BinaryTree::root()
{
    return BinaryTree::Position(_root);
}

PositionList BinaryTree::positions()
{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

void BinaryTree::addRoot()
{
    _root = new Node;
    n=1;
}

void BinaryTree::expandExternal(Position& p)
{
    nodeptr v = p.operator*();
    v->left = new Node;
    v->right = new Node;
    v->left->par = v;
    v->right->par = v;
    n+=2;
}

BinaryTree::Position BinaryTree::removeAboveExternal(Position& p)
{
    nodeptr w = p.operator*();
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

void BinaryTree::preorder(nodeptr v, PositionList& pl)
{
    pl.push_back(BinaryTree::Position(v));
    if(v->left != NULL)
        preorder(v->left, pl);
    if(v->right !=NULL)
        preorder(v->right, pl);
}

//Q4
int BinarySearchTree::height2(Position p) const
{
    int d = 0;
    queue<Position> posQueue;
    posQueue.push(p);
    while(!posQueue.empty())
    {
        int n = posQueue.size();
        for(int i = 0; i<n;i++)
        {
            Position node = posQueue.front();
            if(!node.isExternal())
            {
                posQueue.push(node.left());
                posQueue.push(node.right());
            }
            posQueue.pop();
        }
        if(posQueue.size())
            d++;
    }
    return d;
}

/*
int height2(const Tree& T, const Position& p) {
    if (p.isExternal()) 
        return 0;                       // leaf has height 0
    int h = 0;
    PositionList ch = p.children();     // list of children
    for (Iterator q = ch.begin(); q != ch.end(); ++q)
        h = max(h, height2(T, *q));
    return 1 + h;                       // 1 + max height of children
}

*/
int main(){
    BinaryTree BT;
    BT.addRoot();
    BinaryTree::Position p = BT.root();
    p.value() = 1;
    BT.expandExternal(p);
    cout<<BT.root().value();
    p.left().value() = 2;
    p.right().value() = 3;
    cout<<endl;
    cout<<p.left().value()<<"  ";
    cout<<p.right().value()<<"  ";
    cout<<endl;
    cout<<height2(BT, BT.root());
    return 0;
}