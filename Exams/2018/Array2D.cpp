#include <iostream>
using namespace std;

class Array2D
{

    private:
        int ** Arr;
        int rows;
        int cols;
    public:
        Array2D(int r, int c);
        int& operator()(int r, int c);
        void resize(int new_r, int new_c);
        int* getRow(int r);
        Array2D operator+(Array2D D2);
        int maxRowSum();

};

Array2D::Array2D(int r, int c) : rows(r), cols(c)
{
    Arr = new int* [rows];
    for(int i =0; i<rows; i++)
    {
        Arr[i] = new int[cols];
    }
}
int& Array2D::operator()(int r, int c)
{
    return Arr[r][c];
}
void Array2D::resize(int new_r, int new_c)
{
    int** b;
    b = new int* [new_r];
    for(int i = 0;i<new_r; i++)
        b[i] = new int [new_c];
    
    for(int i = 0; i<new_r; i++)
    {
        for(int j =0; j<new_c; j++)
        {
            b[i][j] = Arr[i][j];
        }
    }

    int ** old = Arr;
    Arr = b;

    for(int i =0; i<rows; i++)
    {
        delete[] old[i];
    }
    delete[] old;
    rows = new_r;
    cols = new_c;
}

int* Array2D::getRow(int r)
{
    int * row_arr = new int[cols];
    for(int i = 0; i<cols; i++)
    {
        row_arr[i] = Arr[r][i];
    }
    return row_arr;
}
Array2D Array2D::operator+(Array2D D2)
{
    if(rows != D2.rows || cols!=D2.cols)
    {
        Array2D result(0,0);
        return result;
    }

    Array2D result(rows, cols);
    for(int i =0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            result.Arr[i][j] = Arr[i][j] + D2.Arr[i][j];
        }
    }
    return result;

}

int Array2D::maxRowSum()
{
    int max = 0;
    int rowSum = 0;
    int maxRowIndex;
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            rowSum += Arr[i][j];
        }
        if (rowSum>max)
        {
            max = rowSum;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}