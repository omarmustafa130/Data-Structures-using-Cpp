#include <iostream>
using namespace std;

typedef unsigned int Elem;


class LinkedDeque
{
    private:
    typedef struct Node
    {
        Elem data;
        Node* next;
        Node* prev;
    }*nodeptr;
    nodeptr header;
    nodeptr trailer;
    int n;
    protected:
        void add(nodeptr n, const Elem& d);
        void remove(nodeptr n);
    public:
        LinkedDeque();
        int size();
        bool empty();
        Elem front();
        Elem back();
        void insertFront(const Elem& d);
        void insertBack(const Elem& d);
        void removeFront();
        void removeBack();
};



LinkedDeque::LinkedDeque() :  n(0)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

void LinkedDeque::add(nodeptr n, const Elem& d)
{
    nodeptr u = new Node; u->data = d; // create a new node for e
    u->next = n; // link u in between v
    u->prev = n->prev; // . . .and v->prev
    n->prev->next = u;
    n->prev = u;
}


void LinkedDeque::remove(nodeptr n)
{
    nodeptr u = n->prev; // predecessor
    nodeptr w = n->next; // successor
    u->next = w; // unlink v from list
    w->prev = u;
    delete n;

}
int LinkedDeque::size()
{
    return n;
}
bool LinkedDeque::empty()
{
    return (n==0);
}
Elem LinkedDeque::front()
{
    return (header->next->data);
}
Elem LinkedDeque::back()
{
    return(trailer->prev->data);
}
void LinkedDeque::insertFront(const Elem& d)
{
    add(header->next, d);
    n++;
}
void LinkedDeque::insertBack(const Elem& d)
{
    add(trailer, d);
    n++;
}
void LinkedDeque::removeFront()
{
    remove(header->next);
    n--;
}
void LinkedDeque::removeBack()
{
    remove(trailer->prev);
    n--;
}


int main()
{
    LinkedDeque D2;
    D2.insertFront(3);
    D2.insertFront(5);
    cout<<D2.front()<<'\n';
    D2.removeFront();
    D2.insertBack(7);
    cout<<D2.back()<<'\n';
    return 0;
}