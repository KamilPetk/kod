#include "std_lib_facilities.hpp"

void showMyStack(stack <int> myStack)
{
    while(!myStack.empty())
    {
        cout << "Value: "
            << myStack.top()
            << ", Address: "
            << &myStack.top()
            << endl;
        myStack.pop();
    }
}

int main()
{
    cout << "STACK:" << endl;
    stack <int> test1;
    for(int i = 0; i < 5; i++)
    {
        cout << "Add " << i << " to the stack " << endl;
        test1.push(i);
    }
    cout << "Stack created:" << endl;
    showMyStack(test1); //kolejne elementy sa umieszczane na gorze stosu

    cout << endl;
    cout << "FREE STORE:" << endl;
    int* p = new int[5];

    for(int i = 0; i < 5; i++)
        cout << i << ". Address " << (p+i) << endl;

    return 0;
}
//Kamil Petk
//14.04.2020
