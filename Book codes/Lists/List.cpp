/*--------------------------NodeList-------------------------*/
#include <iostream>
using namespace std;

typedef int T;
class NodeList
{
    private:
        typedef struct Node
        {
            Node* prev;
            Node* next;
            T Elem;
        } *nodeptr;
        
    public:
        class Iterator
        {
            private:
                nodeptr v;
                Iterator(nodeptr u);

            public:
                T& operator*();
                bool operator==(const Iterator& p);
                bool operator!=(const Iterator& p);
                Iterator& operator++();
                Iterator& operator--();
                friend class NodeList;
        };

    public:
        NodeList();
        int size();
        bool empty();
        Iterator begin();
        Iterator end();
        void insertFront(const T& e);
        void insertBack(const T& e);
        void insert(const Iterator& p, const T& e);
        void eraseFront();
        void eraseBack();
        void erase(const Iterator& p);
    private:
        int n;
        nodeptr header;
        nodeptr trailer;
};

NodeList::Iterator::Iterator(nodeptr u)
{
    v=u;
}

T& NodeList::Iterator::operator*()
{
    return (v->Elem);
}
bool NodeList::Iterator::operator==(const Iterator& p)
{
    return(v == p.v);
}
bool NodeList::Iterator::operator!=(const Iterator& p)
{
    return(v!=p.v);
}
NodeList::Iterator& NodeList::Iterator::operator++()
{
    v=v->next;
    return *this;
}
NodeList::Iterator& NodeList::Iterator::operator--()
{
    v=v->prev;
    return *this;
}

NodeList::NodeList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}
int NodeList::size()
{
    return n;
}
bool NodeList::empty()
{
    return (n==0);
}
NodeList::Iterator NodeList::begin()
{
    
    return Iterator(header->next);
}
NodeList::Iterator NodeList::end()  // end position is just beyond last
{
    return Iterator(trailer);
}
void NodeList::insertFront(const T& e)
{
    insert(begin(), e);
}
void NodeList::insertBack(const T& e)
{
    insert(end(), e);
}
void NodeList::insert(const Iterator& p, const T& e) //insert before p
{
    n+=1;
    nodeptr v = new Node;
    v->Elem = e;
    nodeptr beforeP = (p.v)->prev;
    v->prev = beforeP;
    beforeP->next = v;
    v->next = p.v;
    p.v->prev = v;
}
void NodeList::eraseFront()
{
    erase(begin());
}
void NodeList::eraseBack()
{
    erase(--end());
}
void NodeList::erase(const Iterator& p)
{
    nodeptr beforeP = p.v->prev;
    nodeptr afterP = p.v->next;
    beforeP->next = afterP;
    afterP->prev = beforeP;
    delete p.v;
    n--;
}

int main()
{
    typedef NodeList::Iterator iterator;
    NodeList N1;
    N1.insertFront(8);
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;
    iterator p = N1.begin();
    cout<<"p: "<<*p<<endl;
    N1.insertBack(5);
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;
    iterator q = p;
    ++q;
    cout<<"q: "<<*q<<endl;
    cout<<(p==N1.begin())<<endl;
    N1.insert(q,3);
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;
    *q = 7;
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;
    N1.insertFront(9);
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;

    N1.eraseBack();
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;

    N1.erase(p);
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    cout<<endl;

    N1.eraseFront();
    for(iterator I = N1.begin(); I!=N1.end(); ++I)
    {
        cout<<*I<<" ";
    }  
    return 0;
    /*Output:
    8 
    p: 8
    8 5 
    q: 5
    1
    8 3 5 
    8 3 7 
    9 8 3 7 
    9 8 3 
    9 3 
    3 
    */
}