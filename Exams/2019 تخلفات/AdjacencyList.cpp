#include <iostream>
using namespace std;

typedef int Elem;
typedef struct Node
{
    Elem data;
    Node* next; 
}*nodeptr;


class AdjacencyList
{
    private:
        int n;
        nodeptr ADJ_L;
    public:
        AdjacencyList(int n_);
        void AddConnection(Elem a, Elem b);
        bool AreConnected(Elem a, Elem b);
};

AdjacencyList::AdjacencyList(int n_) : n(n_), ADJ_L(new Node[n])
{
    for(int i =0; i<n; i++)
    {
        ADJ_L[i].data = i;
        ADJ_L[i].next = NULL;
    }
}

void AdjacencyList::AddConnection(Elem a, Elem b)
{
    if((a>=0 && a<n) && (b>=0 && b<n))
    {
        nodeptr curr_a = &ADJ_L[a];
        nodeptr curr_b = &ADJ_L[b];
        while(curr_a->next!=NULL)
        {
            curr_a = curr_a->next;
        }

        curr_a->next = new Node;
        curr_a->next->data = b;
        curr_a = curr_a->next;
        curr_a->next = NULL;

        while(curr_b->next!=NULL)
        {
            curr_b = curr_b->next;
        }
        curr_b->next = new Node;
        curr_b->next->data = a;
        curr_b = curr_b->next;
        curr_b->next = NULL;


    }
}

bool AdjacencyList::AreConnected(Elem a, Elem b)
{
    int flag = 0;
    if((a>=0 && a<n) && (b>=0 && b<n))
    {
        for(int i = 0; i< n; i++)
        {
            nodeptr curr_a = &ADJ_L[i];
            while(curr_a!=NULL)
            {
                if(curr_a->data == a)
                {
                    flag++;
                }
                else if(curr_a->data == b)
                    flag++;
                curr_a = curr_a->next;
            }
            if(flag == 2)
            {
                return true;
            }
            else 
            {
                flag = 0;
                continue;
            }

        }
        return false;
    }
}

int main()
{
    AdjacencyList AD(2);
    AD.AddConnection(0,1);
    cout<<AD.AreConnected(1,0);
    return 0;
}