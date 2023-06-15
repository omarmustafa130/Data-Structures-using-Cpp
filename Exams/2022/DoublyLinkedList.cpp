#include <iostream>
using namespace std;

typedef int Elem;
typedef struct Node
{
    Elem data;
    Node* next;
    Node* prev;
    friend class DLinkedList;
}*nodeptr;

class DLinkedList
{
    private:
        nodeptr header;
        nodeptr trailer;

    protected:
        void add(nodeptr n, const Elem& d);
        void remove(nodeptr n);
    
    public:
        DLinkedList(); // constructor
        ~DLinkedList(); // destructor
        bool empty(); // is list empty?
        const Elem& front(); // get front element
        const Elem& back(); // get back element
        void addFront(const Elem& e); // add to front of list
        void addBack(const Elem& e); // add to back of list
        void removeFront(); // remove from front
        void removeBack(); // remove from back
        void SinglePairsProductEqualToX(int x);
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
        removeFront();
    }
    delete header;
    delete trailer;
}


void DLinkedList::add(nodeptr n, const Elem& d)
{
    nodeptr n_new = new Node;
    n_new->data = d;
    n_new->prev = n->prev;
    n_new->next = n;
    n->prev->next = n_new;
    n->prev =n_new;
}
void DLinkedList::remove(nodeptr n)
{
    nodeptr temp = n;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete temp;
}


bool DLinkedList::empty()
{
    return (header->next == trailer);
}


const Elem& DLinkedList::front()
{
    return (header->next->data);
}
const Elem& DLinkedList::back()
{
    return (trailer->prev->data);
}


void DLinkedList::addFront(const Elem& e) // add to front of list
{
    add(header->next, e);
}
void DLinkedList::addBack(const Elem& e) // add to back of list
{
    add(trailer, e);
}
void DLinkedList::removeFront() // remove from front
{
    remove(header->next);
}
void DLinkedList::removeBack() // remove from back
{
    remove(trailer->prev);
}
//Q4
void DLinkedList::SinglePairsProductEqualToX(int x)
{
    nodeptr curr = header->next;
    nodeptr trailer_curr = trailer->prev;
    while(curr!=trailer_curr)
    {
        if(curr->data * trailer_curr->data == x)
        {
            cout<<"("<<curr->data<<", "<<trailer_curr->data<<")\n";
            trailer_curr=trailer_curr->prev;
            continue;
        }
        else if(curr->data * trailer_curr->data < x)
        {
            curr=curr->next;
        }
        else 
        {
            trailer_curr = trailer_curr->prev;
        }
    }
}

int main()
{
    DLinkedList DL;
    DL.addBack(1);
    DL.addBack(2);
    DL.addBack(4);
    DL.addBack(5);
    DL.addBack(6);
    DL.addBack(8);
    DL.addBack(9);
    DL.SinglePairsProductEqualToX(8);
    cout<<"-------------------------------\n";
    DLinkedList DL2;
    DL2.addBack(1);
    DL2.addBack(2);
    DL2.addBack(3);
    DL2.addBack(4);
    DL2.addBack(5);
    DL2.addBack(6);
    DL2.addBack(7);
    DL2.SinglePairsProductEqualToX(6);
    return 0;
}