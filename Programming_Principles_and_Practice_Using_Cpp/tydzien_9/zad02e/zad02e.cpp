#include <iostream>
using namespace std;
//KOD Z ROZDZIALOW 18, 19
///////////////////////////////////////////////////////////////////
class vector {
 int sz; // the size
 double* elem; // a pointer to the elements
 int space;
public:
     vector() : sz{0}, elem{nullptr}, space{0} { }
     explicit vector(int s) :sz{s}, elem{new double[s]}, space{s}
     {
     for (int i=0; i<sz; ++i) elem[i]=0; // elements are initialized
     }
     vector(const vector&); // copy constructor
     vector& operator=(const vector&); // copy assignment
     vector(vector&&); // move constructor
     vector& operator=(vector&&);
    ~vector() { delete[] elem; } // destructor
     double& operator[ ](int n) { return elem[n]; } // access: return reference
     const double& operator[](int n) const { return elem[n]; }
     int size() const { return sz; }
     int capacity() const { return space; }
     void resize(int newsize); // growth
     void push_back(double d);
     void push_front(double d);
     void reserve(int newalloc);
};

vector::vector(vector&& a)
    :sz{a.sz}, elem{a.elem} // copy a’s elem and sz
{
     a.sz = 0; // make a the empty vector
     a.elem = nullptr;
}

vector& vector::operator=(vector&& a) // move a to this vector
{
     delete[] elem; // deallocate old space
     elem = a.elem; // copy a’s elem and sz
     sz = a.sz;
     a.elem = nullptr; // make a the empty vector
     a.sz = 0;
     return *this; // return a self-reference (see §17.10)
}

void vector::reserve(int newalloc)
{
     if (newalloc<=space) return; // never decrease allocation
     double* p = new double[newalloc]; // allocate new space
     for (int i=0; i<sz; ++i) p[i] = elem[i]; // copy old elements
     delete[] elem; // deallocate old space
     elem = p;
     space = newalloc;
}

void vector::push_back(double d)
 // increase vector size by one; initialize the new element with d
{
     if (space==0)
        reserve(8); // start with space for 8 elements
    else if (sz==space)
    reserve(2*space); // get more space
    elem[sz] = d; // add d at end
    ++sz; // increase the size (sz is the number of elements)
}
///////////////////////////////////////////////////////////////////
void vector::push_front(double d)
 // increase vector size by one; initialize the new element with d
{
    if (space==0)
        reserve(8); // start with space for 8 elements
    else if (sz==space)
        reserve(2*space); // get more space
    for(int i = sz; i > 0; i--)
    {
            elem[i] = elem[i-1];
    }
    elem[0] = d;
    ++sz; // increase the size (sz is the number of elements)
}
int main()
{
    vector v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    cout << "push_front(1)" << endl;
    v.push_front(1);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}
//Kamil Petk
//03.05.2020
