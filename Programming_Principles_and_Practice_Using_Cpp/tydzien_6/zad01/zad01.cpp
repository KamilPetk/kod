#include "std_lib_facilities.hpp"
using namespace std;
class B1
{
public:
     virtual void vf() { cout << "B1::vf()" << endl; };
     void f() { cout << "B1::f()" << endl; };
     
     virtual void pvf() = 0; //pure virtual function

private:

};

class D1 : public B1
{
public:
    void vf() { cout << "D1::fv()" << endl; };
    void f() { cout << "D1::f()" << endl; }
    
    //str.512
    void pvf() override { cout << "D1::pvf()" << endl; }
};

class D2 : public D1
{
public:
    void pvf() override { cout << "D2::pvf()" << endl; }
};

class B2
{
public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
public:
    string data;
    void pvf() override { cout << data << endl; };
};

class D22 : public B1
{
public:
    int data;
    void pvf() override { cout << data << endl; };
};

//str.509
void call(B1& b)
{
    b.vf();
    b.f();
    b.pvf(); //drill 5
}

void f(B2& b)
{
    b.pvf();
}

int main() 
{
try{
    //B1 test1; //error: B1 is abstract
                //Drill 5: powoduje error poniewaz B1 jest abstract
                //Dlatego nalezy wykorzystac klase D1 i tam 
                //nadpisac pvf() aby moc ja wywolywac
    //test1.vf();
    //test1.f();
    ////////////////////////
    cout << endl;
    D1 test2;
    test2.vf();
    test2.f();
    test2.pvf();//Drill 5
    ////////////////////////
    cout << endl;
    D1 test3;
    call(test3);
    //wyswietla D1::fv() poniewaz nastapilo nadpisanie
    ////////////////////////
    cout << endl;
    D2 test4;
    test4.f();
    test4.vf();
    test4.pvf();
    ////////////////////////
    cout << endl;
    D21 test5;
    D22 test6;
    test5.data = "drill";
    test5.pvf();
    test6.data = 7;
    test6.pvf();

    keep_window_open();
    return 0;
}
catch(exception& e){
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch(...){
    cerr << "Oopsss: unknown exception!\n";
    keep_window_open();
    return 2;

}
}
//Kamil Petk
//04.04.2020











    
    
    
    
