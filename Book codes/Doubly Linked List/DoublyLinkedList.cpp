/*--------------------Doubly linked list--------------------*/
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
        void add(nodeptr n, const Elem& d); //add node before n
        void remove(nodeptr n);             //remove n
    
    public:
        DLinkedList(); // constructor
        ~DLinkedList(); // destructor
        bool empty() const; // is list empty?
        const Elem& front() const; // get front element
        const Elem& back() const; // get back element
        void addFront(const Elem& e); // add to front of list
        void addBack(const Elem& e); // add to back of list
        void removeFront(); // remove from front
        void removeBack(); // remove from back
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

bool DLinkedList::empty() const
{
    return (header->next == trailer);
}
const Elem& DLinkedList::front() const
{
    return header->next->data;
}
const Elem& DLinkedList::back() const
{
    return trailer->prev->data;
}

int main()
{
    DLinkedList DL;
    DL.addBack(1);
    cout<<DL.front();
    return 0;
}