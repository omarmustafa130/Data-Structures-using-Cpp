/*------------------------Linked List-----------------------*/

#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node* next;
} *nodeptr;
class LinkedList
{
    private:
        nodeptr head;
        nodeptr curr;
        nodeptr temp;

    public:
        LinkedList();
        int getNode(int pos);
        void addNode(int d);
        void insertNode(int p, int d);
        void deleteNodeByPos(int p);
        void deleteNodeByData(int d);
        void printList();
};

LinkedList::LinkedList()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void LinkedList::addNode(int d)
{
    nodeptr n = new Node;
    n->data = d;
    n->next = nullptr;
    if(head != NULL)
    {
        curr= head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        cout<<"List is empty..."<<endl;
        head = n;
    }
}

int LinkedList::getNode(int pos)
{
    if(head != NULL)
    {
        curr= head;
        for(int i = 0; i<pos; i++)
        {
            if(curr->next != NULL)
                curr = curr->next;
            else
            {
                cout<<"List does not have a node in position "<<pos<<endl;
                return 0;
            }
        }
        
        return curr->data;
    }
    else
    {
        cout<<"List is empty!"<<endl;
        return 0;
    }
}

void LinkedList::insertNode(int p, int d)
{
    nodeptr n = new Node;
    n->data = d;

    if(head != NULL)
    {
        curr= head;
        for(int i = 0; i<p-1; i++)
        {
            if(curr->next != NULL)
                curr = curr->next;
            else
            {
                cout<<"List does not have a node in position "<<p<<endl;
                break;
            }
        }        
        n->next = curr->next;
        curr->next = n;

    }
    else if(head == NULL && p==1)
    {
        cout<<"List is empty..."<<endl;
        head = n;
    }
    else
        cout<<"List does not have a node in position "<<p<<endl;

}
void LinkedList::deleteNodeByPos(int p)
{

    if(head != NULL)
    {
        nodeptr delptr;
        curr= head;

        for(int i = 0; i<p-2; i++)
        {
            if(curr->next != NULL)
                curr = curr->next;
            else
            {
                cout<<"List does not have a node in position "<<p<<endl;
                break;
            }
        }   
        temp = curr->next; 
        curr->next = temp->next;
        delptr = temp; 
        
        delete delptr;
    }
    else
        cout<<"List does not have a node in position "<<p<<endl;


}
void LinkedList::deleteNodeByData(int d)
{
    nodeptr delptr;
    bool dFlag=0;
    curr = head;
    temp = curr;
    if(curr == NULL)
    {
        cout<<"Linked List is empty!";
        return;
    }
    else if(curr!=NULL && curr->data == d)
    {
        dFlag = 1;
        delptr = curr;
        delete delptr;
    }
    else
    {
        while(curr !=NULL)
        {
            if(curr->next != NULL)
                curr=curr->next;
            if(curr->data == d)
            {
                delptr = curr;
                curr=curr->next;
                temp->next = curr;
                dFlag = 1;
                delete delptr;
            }
            temp = curr;
        }
    }
    if(!dFlag)
    {
        cout<<"No node with data ("<<d<<") was in the list!\n";
    }
    else
        cout<<"Data ("<<d<<") deleted successfully!\n";
}
void LinkedList::printList()
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


int main()
{
    LinkedList L1;
    L1.printList();
    L1.addNode(1);
    L1.addNode(2);
    L1.addNode(3);
    L1.addNode(4);
    L1.addNode(5);
    L1.addNode(6);
    L1.deleteNodeByData(6);
    L1.printList();
    return 0;

    /*Output:
        List is empty!
        List is empty...
        Data (6) deleted successfully!
        1 2 3 4 5
    */
}