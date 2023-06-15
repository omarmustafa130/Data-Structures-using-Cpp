class SpecialStack
{
    private:
        struct Elem
        {
            int data;
            int min;
        };
        int capacity;
        Elem* AS;
        int t;
    public:
        SpecialStack(int cap = 100);
        bool isEmpty();
        bool isFull();
        void push(int d);
        int& pop();
        int& getMin();
        int& top();
    };

SpecialStack::SpecialStack(int cap = 100) : capacity(cap), AS(new Elem [capacity]), t(-1)
{}

bool SpecialStack::isEmpty()
{
    return (t==-1);
}

bool SpecialStack::isFull()
{
    return (t==capacity-1);
}

void SpecialStack::push(int d)
{
    Elem e;
    e.data = d;
    if(isEmpty())
    {
        e.min = d;
    }
    else
    {
        if(AS[t].min>d)
        {
            e.min = d;
        }
        else
        {
            e.min = AS[t].min;
        }
    }
    t++;
    AS[t] = e;
}
int& SpecialStack::pop()
{
    t--;
}
int& SpecialStack::getMin()
{
    return AS[t].min;
}

int& SpecialStack::top()
{
    return AS[t].data;
}