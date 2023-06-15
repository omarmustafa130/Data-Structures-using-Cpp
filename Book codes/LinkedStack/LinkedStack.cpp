/*---------------------------Linked Stack-------------------------------*/
#include <iostream>
using namespace std;

template <typename T>
class TLinkedList
{
    private:
        typedef struct Node
        {
            T data;
            Node* next;
        } *nodeptr;
        nodeptr head;
        nodeptr curr;
        nodeptr temp;
    public:
        TLinkedList();
        T& Front();
        void addFront(T d);
        void removeFront();
        void printList();
};

template <typename T>
TLinkedList<T>::TLinkedList()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

template <typename T>
void TLinkedList<T>::addFront(T d)
{
    nodeptr n = new Node;
    n->data = d;
    if(head == NULL)
    {
        head = n;
        head->next = NULL;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

template <typename T>
void TLinkedList<T>::removeFront()
{
    nodeptr temp = head;
    head = temp->next;
    delete temp;
}

template <typename T>
T& TLinkedList<T>::Front()
{
        return head->data;
}

template <typename T>
void TLinkedList<T>::printList()
{
    if(head != NULL)
    {
        curr= head;

        while(curr->next != NULL)
        {
            cout<<curr->data<<"  ";
            curr = curr->next;
        }  
        cout<<curr->data;   
    }
    else
        cout<<"List is empty!"<<endl;
}

template <typename T>
class LinkedStack
{
    private:
        TLinkedList<T> LS;
        int n;

    public:
        LinkedStack();
        int size();
        bool empty();
        void push(const T& d);
        const T top();
        void pop();
};

template <typename T>
LinkedStack<T>::LinkedStack() : LS(), n(0)
{}

template <typename T>
int LinkedStack<T>::size()
{
    return n;
}

template <typename T>
bool LinkedStack<T>::empty()
{
    return (n==0);
}

template <typename T>
void LinkedStack<T>::push(const T& d)
{
    LS.addFront(d);
    n++;
}

template <typename T>
void LinkedStack<T>::pop()
{
    LS.removeFront();
    n--;
}


template <typename T>
const T LinkedStack<T>::top()
{
    return(LS.Front());
}

int main()
{
    cout<<"Testing template linked stack :\n";
    LinkedStack<int> L2;
    if(L2.empty())
        cout<<"Stack is empty\n";
    else
        cout<<"stack not empty\n";
    L2.push(2);
    L2.push(3);
    L2.push(4);
    L2.push(5);
    L2.push(6);
    L2.push(7);
    cout<<L2.top()<<endl;
    L2.pop();
    cout<<L2.top()<<endl;

    /*Output:
    Testing template linked stack :
    Stack is empty
    7
    6
    */
    return 0;
}