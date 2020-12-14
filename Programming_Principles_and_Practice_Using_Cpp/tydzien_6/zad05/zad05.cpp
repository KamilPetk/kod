
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities
#include "std_lib_facilities.hpp"
#include "zad05_Person.hpp"
using namespace Graph_lib; 

 
istream& operator>>(istream& is, Person& p) 
{
    string firstname;
    string secondname;
    string age;
    
    cout << "Enter first name, second name and age: \n";
    
    is >> firstname >> secondname >> age;

    p.enterFirstName(firstname);
    p.enterSecondName(secondname);
    p.enterAge(age);
 
    return is;
}
 
ostream& operator<<(ostream& os, Person& p) {
    os << "First name: " << p.firstName() << " Second name: " << p.secondName() << " Age: " << p.age();
    return os;
}
 
int main()
try
{
    Person p1;//("Goofy", "63");
    //cin >> p1;
    //cout << p1 << endl;
    
    vector<Person> persons;
    int n;
    cout << "How many people do you want to add? \n";
    cin >> n;
    if(n > 0)
    {
    for(int i = 0; i < n; i++)
    {
        cin >> p1;
        persons.push_back(p1);
    }
    
    for (Person p : persons) {
        cout << p << endl;
    } 
    }else
    {
        error("Bad value \n");
        return 0;
    }
}
catch (exception& e) {
    cout << e.what() << endl;
    return 1;
}
catch (...) {
    cout << "Exiting" << endl;
    return 2;
}
//Kamil Petk
//07.04.2020
