#include <iostream>
using namespace std;

template <typename E>
struct SNode { // singly linked list node
    E elem; // linked list element value
    SNode* next; // next item in the list
};



template <typename E>
class SLinkedList { // a singly linked list
    public:
        
        SLinkedList(); // empty list constructor
        ~SLinkedList(); // destructor
        bool empty() const; // is list empty?
        const E& front() const; // return front element
        void addFront(const E& e); // add to front of list
        void removeFront(); // remove front item list
        int NumOfNodes();
        int GetNumOfObjects();
        void removeNode(SNode<E>*);
        void removeFirstNodeWithValueX(E x);
    private:
        inline static int NumOfObjects;
        SNode<E>* head; // head of the list
        int n;
        
};


template <typename E>
SLinkedList<E>::SLinkedList() // constructor
: head(NULL), n(0)
{ NumOfObjects++;}

template <typename E>
bool SLinkedList<E>::empty() const // is list empty?
{ return head == NULL; }

template <typename E>
int SLinkedList<E>::NumOfNodes()
{ return n; }

template <typename E>
int SLinkedList<E>::GetNumOfObjects()
{ return NumOfObjects; }

template <typename E>
const E& SLinkedList<E>::front() const // return front element
{ return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList() // destructor
{ while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e) { // add to front of list
    SNode<E>* v = new SNode<E>; // create new node
    v->elem = e; // store data
    v->next = head; // head now follows v
    head = v; // v is now the head
    n++;
}

template <typename E>
void SLinkedList<E>::removeFront() { // remove front item
    SNode<E>* old = head; // save current head
    head = old->next; // skip over old head
    delete old; // delete the old head
    n--;
}

template <typename E>
void SLinkedList<E>::removeNode(SNode<E>* N) 
{ // remove item
    if(N == head)
        removeFront();
    else
    {
        SNode<E>* curr = head->next;
        SNode<E>* beforeCurr = head;
        while(curr!=NULL)
        {
            if(curr == N)
            {
                beforeCurr->next = curr->next;
                delete curr;
                n--;
                return;
            }
            else
            {
                curr = curr->next;
                beforeCurr = beforeCurr->next;
            }
        }
    }

}


template <typename E>
void SLinkedList<E>::removeFirstNodeWithValueX(E x) 
{ // remove item
    if(head->elem == x)
        removeFront();
    else
    {
        SNode<E>* curr = head->next;
        SNode<E>* beforeCurr = head;
        while(curr!=NULL)
        {
            if(curr->elem == x)
            {
                beforeCurr->next = curr->next;
                delete curr;
                n--;
                return;
            }
            else
            {
                curr = curr->next;
                beforeCurr = beforeCurr->next;
            }
        }
    }

}

int main()
{
    SNode<int>* link;
    
    SLinkedList<int> SL;
    SL.addFront(1);
    SL.addFront(2);
    SL.addFront(3);
    cout<<"Number of nodes: "<<SL.NumOfNodes()<<"  and the number of objects is: "<<SL.GetNumOfObjects()<<"\n";
    cout<<"front: "<<SL.front()<<endl;
    SL.removeFirstNodeWithValueX(3);
    cout<<"Number of nodes: "<<SL.NumOfNodes()<<"  and the number of objects is: "<<SL.GetNumOfObjects()<<"\n";
    cout<<"front: "<<SL.front()<<endl;
    return 0;
}

