/*--------------------Linked Queue----------------------*/
#include <iostream>
using namespace std;

template<typename T>
class CLinkedList
{
    private:
        typedef struct Node
        {
            T data;
            Node* next;
        } *nodeptr;
        nodeptr cursor;
    public:
        CLinkedList();
        bool empty();
        const T& front();
        const T& back();
        void advance(); 
        void remove();
        void addNode(const T& d);
};

template<typename T>
CLinkedList<T>::CLinkedList()
{
    cursor = NULL;
}

template<typename T>
void CLinkedList<T>::addNode(const T& d) //add to the front - after cursor
{
    nodeptr n = new Node;
    n->data = d;
    if(cursor == NULL)
    {
        n->next = n;
        cursor = n;
    }    
    else
    {
        n->next = cursor->next;
        cursor->next = n;
    }
}

template <typename T>
bool CLinkedList<T>::empty()
{
    return (cursor==NULL);
}


template <typename T>
const T& CLinkedList<T>::back()
{
    return (cursor->data);
}


template <typename T>
const T& CLinkedList<T>::front()
{
    return (cursor->next->data);
}

template <typename T>
void CLinkedList<T>::advance()
{
    cursor=cursor->next;
}

template <typename T>
void CLinkedList<T>::remove() //delete node after cursor - first node
{
    nodeptr old=cursor->next;
    if(old == cursor)
    {
        cursor = NULL;
    }
    else
    {
        cursor->next = old->next;
    }
    delete old;
}

template<typename T>
class LinkedQueue
{
    private:
        CLinkedList<T> CL; //Circular Linked List
        int n;
    public:
        LinkedQueue();
        int size();
        bool empty();
        const T& front();
        void enqueue(const T& d);
        void dequeue();
};

template<typename T>
LinkedQueue<T>::LinkedQueue() : CL(), n(0)
{}

template<typename T>
int LinkedQueue<T>::size()
{
    return n;
}

template<typename T>
bool LinkedQueue<T>::empty()
{
    return (n==0);
}

template<typename T>
const T& LinkedQueue<T>::front()
{
    return (CL.front());
}


template<typename T>
void LinkedQueue<T>::enqueue(const T& d)
{
    CL.addNode(d);
    CL.advance();
    n++;
}
template<typename T>
void LinkedQueue<T>::dequeue()
{
    CL.remove();
    n--;
}
int main()
{
    cout<<"\nTesting Linked Queue: \n";
    LinkedQueue<int> L1;
    if(L1.empty())
        cout<<"Queue is empty\n";
    L1.enqueue(1);
    L1.enqueue(2);
    L1.enqueue(3);
    cout<<L1.front()<<endl;
    cout<<"The size is : "<<L1.size()<<endl;
    L1.dequeue();
    L1.dequeue();
    cout<<L1.front()<<endl;
    L1.enqueue(4);
    L1.dequeue();
    cout<<L1.front();
    return 0;
    /*Output:
    Testing Linked Queue: 
    Queue is empty
    1
    The size is : 3
    3
    4
    */
}