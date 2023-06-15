//Q3
#include <iostream>
using namespace std;

typedef unsigned int Elem;
class nStack
{
    private:
        typedef struct Node
        {
            Elem data;
            Node* next;
        }*nodeptr;
        nodeptr header;
        int n;
        int arr[1000] = {0}; //using array of frequency 0->999

    public:
        int size();
        bool empty();
        void pop();
        void push(Elem d);
        Elem top();
        int topRep();
};

int nStack::size()
{
    return n;
}
bool nStack::empty()
{
    return (n==0);
}
void nStack::pop()
{
    int indTop = top();
    nodeptr old = header;
    header = header->next;
    delete old;
    n--;
    arr[indTop-1]--;
}
void nStack::push(Elem d)
{
    nodeptr v = new Node;
    v->data = d;
    if(empty())
    {
        header = v;
    }
    else
    {
        v->next = header;
        header = v;
    }
    arr[d-1]++;
    n++;
}
Elem nStack::top()
{
    return header->data;
}

int nStack::topRep()
{
    int indTop= top();
    return arr[indTop-1];
}
int main()
{
    nStack S;
    S.push(1);
    S.push(2);
    S.push(2);
    cout<<S.top()<<endl;
    cout<<S.topRep()<<endl;
    S.pop();
    cout<<S.top()<<endl;
    cout<<S.topRep()<<endl;
    return 0;
    /*Output:
    2
    2
    2
    1
    */
}