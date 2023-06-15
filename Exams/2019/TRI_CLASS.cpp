/*---------------------2019 exam--------------------*/
//Q1 - Triangle class
#include <iostream>
using namespace std;

class Tri
{
    private:
        double L1, L2, L3;
    public:
        Tri(double L1_, double L2_, double L3_);
        void printTr();
        bool operator==(Tri T2);
        bool isObtuseTriangle();

};

Tri::Tri(double L1_, double L2_, double L3_) : L1(L1_), L2(L2_), L3(L3_)
{}

void Tri::printTr()
{
    cout<<"L1 is: "<<L1<<endl;
    cout<<"L2 is: "<<L2<<endl;
    cout<<"L3 is: "<<L3<<endl;
}

bool Tri::operator==(Tri T2)
{
    if(L1 != T2.L1 && L1 !=T2.L2 && L1!= T2.L3)
        return false;
    if(L2 != T2.L1 && L1 !=T2.L2 && L1!= T2.L3)
        return false;
    if(L3 != T2.L1 && L1 !=T2.L2 && L1!= T2.L3)
        return false;
    return true;
}
bool Tri::isObtuseTriangle()
{
    double max = L1;
    double min1 = L2, min2=L3;
    if(L2>max)
    {
        max = L2;
        min1 = L1;
    }
    if(L3>max)
    {
        max = L3;
        min1 = L1;
        min2 = L2;
    }    

    if((max*max)>((min1*min1)+(min2*min2)))
        return true;
    else
        return false;
    
}

int main()
{
    Tri T(3,4,5);
    Tri T2(5,3,4);
    Tri T3(3,4,6);
    cout<<"The triangles initialised are as follows:\nTriangle 1: \n";
    T.printTr();
    cout<<"Triangle 2: \n";
    T2.printTr();
    cout<<"Triangle 3: \n";
    T3.printTr();
    cout<<"T1: 3,4,5 --- T2: 5,3,4\nAre the two traingles identical?\nExpected Output = true(1) ----- Your output: "<<(T==T2)<<endl;
    cout<<"Is T1: (3,4,5) an obtuse triangle?\nExpected output: No (0) ----- Output: "<<T.isObtuseTriangle()<<endl;
    cout<<"Is T2: (5,3,4) an obtuse triangle?\nExpected output: No (0) ----- Output: "<<T2.isObtuseTriangle()<<endl;
    cout<<"Is T3: (3,4,6) an obtuse triangle?\nExpected output: Yes (1) ----- Output: "<<T3.isObtuseTriangle()<<endl;
    return 0;
    
    /*Output:
    The triangles initialised are as follows:
    Triangle 1: 
    L1 is: 3
    L2 is: 4
    L3 is: 5
    Triangle 2: 
    L1 is: 5
    L2 is: 3
    L3 is: 4
    Triangle 3: 
    L1 is: 3
    L2 is: 4
    L3 is: 6
    T1: 3,4,5 --- T2: 5,3,4
    Are the two traingles identical?
    Expected Output = true(1) ----- Your output: 1
    Is T1: (3,4,5) an obtuse triangle?
    Expected output: No (0) ----- Output: 0
    Is T2: (5,3,4) an obtuse triangle?
    Expected output: No (0) ----- Output: 0
    Is T3: (3,4,6) an obtuse triangle?
    Expected output: Yes (1) ----- Output: 1
    */
}