/*----------------------Deque-------------------------*/
#include <iostream>
using namespace std;

typedef int Elem;
class DLinkedList
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
    protected:
        void add(nodeptr n, const Elem& d);
        void remove(nodeptr n);  
    public:
        DLinkedList(); // constructor
        ~DLinkedList(); // destructor
        bool empty() ; // is list empty?
        const Elem& Lfront() ; // get front element
        const Elem& Lback() ; // get back element
        void LaddFront(const Elem& e); // add to front of list
        void LaddBack(const Elem& e); // add to back of list
        void LremoveFront(); // remove from front
        void LremoveBack(); // remove from back
};

DLinkedList::DLinkedList() 
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() 
{
    while(!empty())
    {
        LremoveFront();
    }
    delete header;
    delete trailer;
}

void DLinkedList::add(nodeptr n, const Elem& d)
{
    nodeptr u = new Node; u->data = d; // create a new node for e
    u->next = n; // link u in between n
    u->prev = n->prev; // . . .and n->prev
    n->prev->next = u;
    n->prev = u;
}
void DLinkedList::remove(nodeptr n)
{
    nodeptr u = n->prev; // predecessor
    nodeptr w = n->next; // successor
    u->next = w; // unlink n from list
    w->prev = u;
    delete n;

}

void DLinkedList::LaddFront(const Elem& e) // add to front of list
{
    add(header->next, e);
}
void DLinkedList::LaddBack(const Elem& e) // add to back of list
{
    add(trailer, e);
}
void DLinkedList::LremoveFront() // remove from front
{
    remove(header->next);
}
void DLinkedList::LremoveBack() // remove from back
{
    remove(trailer->prev);
}

bool DLinkedList::empty()
{
    return(header->next == NULL);
}

const Elem& DLinkedList::Lfront()
{   
    return (header->next->data);
}

const Elem& DLinkedList::Lback()
{
    return(trailer->prev->data);
}

class LinkedDeque
{
    private:
        int n;
        DLinkedList DL;

    public:
        LinkedDeque();
        int size();
        bool empty();
        void front();
        void back();
        void insertFront(const Elem& d);
        void insertBack(const Elem& d);
        void removeFront();
        void removeBack();
};

LinkedDeque::LinkedDeque() : DL(), n(0)
{}
int LinkedDeque::size()
{
    return n;
}
bool LinkedDeque::empty()
{
    return (n==0);
}
void LinkedDeque::front() //you can use return
{
    cout<<DL.Lfront()<<endl;
}
void LinkedDeque::back() //you can use return
{
    cout<<DL.Lback()<<endl;
}
void LinkedDeque::insertFront(const Elem& d)
{
    DL.LaddFront(d);
    n++;
}
void LinkedDeque::insertBack(const Elem& d)
{
    DL.LaddBack(d);
    n++;
}
void LinkedDeque::removeFront()
{
    DL.LremoveFront();
    n--;
}
void LinkedDeque::removeBack()
{
    DL.LremoveBack();
    n--;
}

int main()
{
    DLinkedList D1;

    D1.LaddFront(3);
    D1.LaddFront(5);
    cout<<D1.Lfront()<<endl;
    D1.LremoveFront();
    D1.LaddBack(7);
    cout<<D1.Lback()<<endl;
    LinkedDeque D2;
    D2.insertFront(3);
    D2.insertFront(5);
    D2.front();
    D2.removeFront();
    D2.insertBack(7);
    D2.back();
    return 0;
    /*Output:
    5
    7
    5
    7
    */
}