//Q2
template <typename T>
class BasicVector 
{   // a simple vector class
    public:
        BasicVector(int capac = 10); // constructor
        T& operator[ ](int i) // access element at index i
        { return a[i]; }
        // . . . other public members omitted
        T& maxValue();
        void insert(T, int ind);
        void changeSize(int N);
    private:
        T* a; // array storing the elements
        int capacity; // length of array a
};

template <typename T> // constructor
BasicVector<T>::BasicVector(int capac) {
    capacity = capac;
    a = new T[capacity]; // allocate array storage  
    for (int i = 0; i<capacity; i++)
    {
        a[i] = 0;
    }
}


template <typename T> // constructor
T& BasicVector<T>::maxValue() {
    T max = a[0];
    for(int i = 1; i<capacity; i++)
    {
        if(a[i]> max)
        {
            max = a[i];
        }
    }
    return max;
}


template <typename T> // constructor
void BasicVector<T>::insert(T data, int ind) {
    for(int i = capacity-1; i>ind; i--)
    {
        a[i] = a[i-1];
    }
    a[ind] = data;
}


template <typename T> 
void BasicVector<T>::changeSize(int N) {
    if (capacity >= N) 
        return; // already big enough
    T* B = new T[N]; // allocate bigger array
    for (int j = 0; j < n; j++) // copy contents to new array
        B[j] = a[j];
    if (a != NULL) 
        delete [ ] a; // discard old array
    a = B; // make B the new array
    capacity = N; // set new capacity  
}