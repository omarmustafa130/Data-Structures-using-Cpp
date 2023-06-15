/*----------------------------------------Circular Linked List----------------------------------------*/
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
void CLinkedList<T>::addNode(const T& d)
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
void CLinkedList<T>::remove()
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
