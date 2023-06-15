/*-------------------Array Vector----------------------*/
#include <iostream>
using namespace std;

typedef int Elem;
class ArrayVector
{
    private:
        int capacity;
        int n;
        Elem* A;
    public:
        ArrayVector();
        int size();
        bool empty();
        const Elem& operator[](int i);
        const Elem& at(int i);
        void insert(int i, const Elem& E);
        void erase(int i);
        void reserve(int N);
        void set(int i, const Elem& E);
};

ArrayVector::ArrayVector() : A(NULL), n(0), capacity(0)
{}

int ArrayVector::size()
{
    return n;
}

bool ArrayVector::empty()
{
    return (n==0);
}

const Elem& ArrayVector::operator[](int i)
{
    try
    {
        if(i<0 || i>=n)
            throw("index out of range!");
        
    }
    catch(const char* cerr)
    {
        cout<<cerr<<endl;
    }
    return A[i];
}


const Elem& ArrayVector::at(int i)
{
    try
    {
        if(i<0 || i>=n)
            throw("index out of range!");
        
    }
    catch(const char* cerr)
    {
        cout<<cerr<<endl;
    }
    return A[i];
    
}

void ArrayVector::insert(int i, const Elem& E)
{
    if(n>=capacity)
    {
        reserve(max(1,2*capacity));
    }
    for(int j = n-1; j>=i; j--)
    {
        A[j+1]=A[j];
    }
    A[i] = E;
    n++;
}
void ArrayVector::erase(int i)
{
    for(int j = i; j<n; j++)
    {
        A[j] = A[j+1];
    }
    n--;
}
void ArrayVector::reserve(int N)
{
    if(capacity>=N)
        return;
    Elem* B = new Elem[N];
    for(int i = 0; i<n; i++)
    {
        B[i] = A[i];
    }
    if(A!=NULL)
        delete [] A;
    A=B;
    capacity = N;
}


void ArrayVector::set(int i, const Elem& E)
{
    try
    {
        if(i<0 || i>=n)
            throw("index out of range!");
        A[i] = E;
    }
    catch(char* cerr)
    {
        cout<<cerr<<endl;
    }
}
int main()
{
    ArrayVector AV;
    AV.insert(0,7);
    AV.insert(0,4);
    cout<<AV.at(1)<<endl;
    cout<<AV[1];
    AV.insert(2,2);
    AV.erase(1);
    AV.insert(1,5);
    AV.insert(1,3);
    AV.insert(4,9);
    cout<<AV.at(2)<<endl;
    AV.set(3,8);
    for(int i=0; i<5; i++)
    {
        cout<<AV[i]<<" ";
    }
    /*Output:
    7
    75
    4 3 5 8 9 
    */
    return 0;
}
/*-------------------End of Array Vector----------------------*/
