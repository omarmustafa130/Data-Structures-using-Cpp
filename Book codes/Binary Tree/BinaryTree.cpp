/*---------------------------------Linked Binary Tree---------------------------------*/
#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef int Elem;

class BinarySearchTree
{
    protected:
        typedef struct Node
        {
            Node* par;
            Node* left;
            Node* right;
            Elem data;
            Node() : data(), par(NULL), left(NULL), right(NULL)
            {}
        }*nodeptr;
    public:
        class Position
        {
            private:
                nodeptr v;
            public:
                Position(Node* _v = NULL); /* constructor */
                Elem& operator*(); /* get element */
                Position left() const; /* get left child */
                Position right() const; /* get right child */
                Position parent() const; /* get parent */
                bool isRoot() const; /* root of the tree? */
                bool isExternal() const; /* an external node? */
                Position sibling() const; /* return Position to sibling */
                friend class BinarySearchTree; /* give tree access */
        };
        typedef std::list<Position> PositionList;
    private:
        nodeptr _root;
        int n;
    public:
        BinarySearchTree();
        int size();         //number of nodes
        bool empty();       //is the tree empty?
        Position root();    //get root
        PositionList positions() const; //list of nodes
        void addRoot();     //add root to empty tree
        void expandExternal(const Position& p);
        Position removeAboveExternal(const Position& p);
        /* added functions */
        void print_exp_recur(Position p) const; /* print expression recursively */
        float eval_recur(Position p) const ; /* evaluate expression recursively */
        bool isAncestor(Position p1, Position p2) const; /* return true iff p1 is an ancestor of p2 */
        bool isDescendant(Position p1, Position p2) const; /* return true iff p1 is a descendant of p2 */
        PositionList get_path(Position p1, Position p2) const; /* return PositionList containing a path between p1 and p2 */
        bool isSibling(Position p1, Position p2) const; /* return true iff p1 is sibling of p2 */
        int depth_recur(Position p) const; /* calculates depth of a node recursively */
        int depth(Position p) const; /* calculate depth of a node */
        int height_recur(Position p) const; /* calculate tree height recursively */
        int height(Position p) const; /* calculate tree height */
    protected:
        void preorder(Node* v, PositionList& pl) const; // preorder utility
};

typedef std::list<BinarySearchTree::Position> PositionList;
/*-------------------------Position functions---------------------------------*/
BinarySearchTree::Position::Position(Node* _v) : v(_v)
{}

Elem& BinarySearchTree::Position::operator*()
{
    return v->data;
}

BinarySearchTree::Position BinarySearchTree::Position::left() const
{
    return Position(v->left);
}

BinarySearchTree::Position BinarySearchTree::Position::right() const
{
    return Position(v->right);
}

BinarySearchTree::Position BinarySearchTree::Position::parent() const
{
    return Position(v->par);
}

bool BinarySearchTree::Position::isRoot() const
{
    return (v->par == NULL);
}

bool BinarySearchTree::Position::isExternal() const
{
    return (v->left == NULL && v->right == NULL);
}

BinarySearchTree::Position BinarySearchTree::Position::sibling() const
{
    if(v->par->left == v)
        return Position(v->par->right);
    else
        return Position(v->par->left);
}

/*------------------------------------------------------------------------------------*/
/*-------------------------BinarySearchTree functions---------------------------------*/

BinarySearchTree::BinarySearchTree() : _root(NULL), n(0)
{}

int BinarySearchTree::size()
{
    return n;
}
bool BinarySearchTree::empty()
{
    return n==0;
}     
BinarySearchTree::Position BinarySearchTree::root()
{
    return Position(_root);
}  

PositionList BinarySearchTree::positions() const
{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}
void BinarySearchTree::addRoot()
{
    _root = new Node;
    n=1;
}
void BinarySearchTree::expandExternal(const Position& p)
{
    nodeptr v = p.v;
    v->left = new Node;
    v->right = new Node;
    v->left->par = v;
    v->right->par = v;
    n+=2;
}
BinarySearchTree::Position BinarySearchTree::removeAboveExternal(const Position& p)
{
    Node* w = p.v;
    Node* v = w->par; // get p’s node and parent
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root)   // child of root?
    {
        _root = sib; // . . .make sibling root
        sib->par = NULL;
    }
    else
    {
        Node* gpar = v->par; // w’s grandparent
        if (v == gpar->left) gpar->left = sib; // replace parent by sib
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v; // delete removed nodes
    n -= 2; // two fewer nodes
    return Position(sib);
}

void BinarySearchTree::preorder(Node* v, PositionList& pl) const
{
    pl.push_back(Position(v));
    if(v->left != NULL)
    {
        preorder(v->left, pl);
    }
    if(v->right != NULL)
    {
        preorder(v->right, pl);
    }
}

void BinarySearchTree::print_exp_recur(Position p) const
{
    if(p.isExternal())
    {
        cout<<*p - 48;
    }
    else
    {
        cout<<"(";
        print_exp_recur(p.left());
        if(*p == '+')
            cout<<"+";
        else if(*p == '-')
            cout<<"-";
        else if(*p == '*')
            cout<<"*";
        else if(*p == '/')
            cout<<"/";
        else if(*p == '%')
            cout<<"%";
        else if(*p>=48 && *p<58)
            cout<<*p-48;
        print_exp_recur(p.right());
        cout<<")";
    }
}

float BinarySearchTree::eval_recur(Position p) const
{
    if(p.isExternal())
    {
        return *p-48;
    }
    else
    {
        if(*p == '+')
            return eval_recur(p.left()) + eval_recur(p.right());
        else if(*p == '-')
            return eval_recur(p.left()) - eval_recur(p.right());
        else if(*p == '*')
            return eval_recur(p.left()) * eval_recur(p.right());
        else if(*p == '/')
            return eval_recur(p.left()) / eval_recur(p.right());
    }
    return 0;
}

bool BinarySearchTree::isAncestor(Position p1, Position p2) const
{
    /*the root node in a binary tree is not considered an ancestor, 
    because it has no parent node. An ancestor is defined as any node 
    that is on the path from the root node to a given node. 
    Since the root node is at the top of the tree and has no parent node, 
    it cannot be an ancestor of any other node in the tree. However, 
    the root node is considered the "ultimate" ancestor of all the nodes 
    in the tree, since all other nodes are descendants of the root node.*/
    nodeptr pp1 = p1.v;
    nodeptr pp2 = p2.v;
    while(pp2!=_root)
    {
        if(pp1 == pp2)
            return true;
        pp2=pp2->par;
    }
    return false;
}
bool BinarySearchTree::isDescendant(Position p1, Position p2) const
{
    if(isAncestor(p2,p1))
        return true;
    else
        return false;
}

PositionList BinarySearchTree::get_path(Position p1, Position p2) const
{
    PositionList list;
    Position p = p1;
    list.push_back(p);
    while (*p != *p2)
    {
        if(!isAncestor(p.left(), p2) && !isAncestor(p.right(), p2))
        {
            cout<<"No path between p1 and p2\n";
            list.pop_back();
            return list;
        }
        p = (isAncestor(p.left(), p2))? p.left():p.right();
        list.push_back(p);
    }
    return list;
}

bool BinarySearchTree::isSibling(Position p1, Position p2) const
{
    Position sib = p1.sibling();
    if(p2.v == sib.v)
        return true;
    else
        return false;
}

int BinarySearchTree::depth_recur(Position p) const
{
    if(p.isRoot())
    {
        return 0;
    }
    else
    {
        return (1 + depth_recur(p.parent()));
    }
}
int BinarySearchTree::depth(Position p) const
{
    int dep = 0;
    Position pp = p;
    while(!pp.isRoot())
    {
        pp = pp.parent();
        dep++;
    }
    return dep;
}
int BinarySearchTree::height_recur(Position p) const
{
    if(p.isExternal())
        return 0;
    int h = 0;

    h = max(h, height_recur(p.left()));
    h = max(h, height_recur(p.right()));
    return 1+h;
}
int BinarySearchTree::height(Position p) const
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


int main()
{
    BinarySearchTree BT;
    BT.addRoot();
    
    BinarySearchTree::Position p[15];
    p[0] = BT.root(); //get root position
    for(int i = 0; i<=6; i++)
    {
        BT.expandExternal(p[i]);
        p[i*2+1] = p[i].left();
        p[i*2+2] = p[i].right();
        *p[i] = i+1;
        *p[i*2+1] = i*2+2;
        *p[i*2+2] = i*2+3;
    }

    for(int i =0; i<15; i++) //printing tree level by level
    {   
        static int j = 1;
        if(i == 0)
        {
            cout<<*p[i]<<endl;
        }
        else
        {   
            j*=2;
            for(int k = 0; k<j; k++)
            {
                cout<<*p[i]<<" ";
                i++;
    
            }
            i--;
            cout<<endl;
        }
    }
    cout<<"The root is: "<<*BT.root()<<endl;
    cout<<"The depth of the node 15 recursively is: "<<BT.depth_recur(p[14])<<endl;
    cout<<"The depth of the node 15 non-recursively is: "<<BT.depth(p[14])<<endl;
    cout<<"The height of the tree recursively is: "<<BT.height_recur(BT.root())<<endl;
    cout<<"The height of the tree non-recursively is: "<<BT.height(BT.root())<<endl;

    /*Output:
    1
    2 3 
    4 5 6 7 
    8 9 10 11 12 13 14 15 
    The root is: 1
    The depth of the node 15 recursively is: 3
    The depth of the node 15 non-recursively is: 3
    The height of the tree recursively is: 3
    The height of the tree non-recursively is: 3
    */
    return 0;
}