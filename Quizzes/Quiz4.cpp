#include <iostream>
using namespace std;

class StringNode { // a node in a list of strings
    private:
        string elem; // element value
        StringNode* next; // next item in the list
        friend class StringLinkedList; // provide StringLinkedList access
};



class StringLinkedList { // a linked list of strings
    public:
        StringLinkedList(); // empty list constructor
        ~StringLinkedList(); // destructor
        bool empty() const; // is list empty?
        const string& front() const; // get front element
        void addFront(const string& e); // add to front of list
        void removeFront(); // remove front item list
        StringNode* maxSequenceOfOnes();
    private:
        StringNode* head; // pointer to the head of list
};

StringLinkedList::StringLinkedList() // constructor
: head(NULL) { }

StringLinkedList::~StringLinkedList() // destructor
{ 
    while (!empty()) removeFront(); 
}

bool StringLinkedList::empty() const // is list empty?
{ 
    return head == NULL; 
}

const string& StringLinkedList::front() const // get front element
{ 
    return head->elem; 
}

void StringLinkedList::addFront(const string& e) 
{ // add to front of list
    StringNode* v = new StringNode; // create new node
    v->elem = e; // store data
    v->next = head; // head now follows v
    head = v; // v is now the head
}

void StringLinkedList::removeFront() 
{ // remove front item
    StringNode* old = head; // save current head
    head = old->next; // skip over old head
    delete old; // delete the old head
}


StringNode* StringLinkedList::maxSequenceOfOnes() 
{
    int count_0 = 0; 
    int count_1 = 0;
    int max_seq = 0;
    StringNode* ptr = head; StringNode* ptr_return = head; StringNode *temp = head;
    while(ptr != NULL)
    {
        if(ptr->elem == 0 && count_0<=3)
        {
            count_0++;
            ptr= ptr->next;
            continue;
        }
        else if(ptr->elem == 1 && count_0<=3)
        {
            count_1++; ptr=ptr->next;
            continue;
        }
        if(count_0>3)
        {
            if(count_1 > max_seq)
            {
                max_seq = count_1;
                ptr_return = temp;
            }

            while(temp!=NULL)
            {
                if(temp->elem != 0)
                {
                    temp = temp->next;
                    continue;
                }
                temp = temp->next;
                ptr= temp;
                count_0 = 0;
                count_1 = 0;
                break;
            }
            if(temp == NULL)
                return ptr_return;
            
        }
    }
    if(ptr == NULL) 
    {
        ptr_return = temp;
        max_seq = count_1;
    }
    return ptr_return;

}