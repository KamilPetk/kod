#include "std_lib_facilities.hpp"


struct Person
{
    Person(string first_name, string second_name, string age)
    {
        //FIRST_NAME:
        for (char ch : first_name) 
        {
            if (!isalpha(ch)) //isalpha: book 397 page
                error("You can't use ; : \" ' [ ] * & ^ % $ # @ ! ");
        }
        fn = first_name;
        
        //SECOND_NAME:
        for (char ch : second_name) 
        {
            if (!isalpha(ch)) //isalpha: book 397 page
                error("You can't use ; : \" ' [ ] * & ^ % $ # @ ! ");
        }
        sn = second_name;
        
        //AGE:
        for(char ch : age)
            if(!isdigit(ch)) error("Bad value"); //isdigit: book 397 page

        int ageInt = stoi(age); //string to int
    
        if(ageInt<0 || ageInt >=150)
        {
        error("Bad value");
        }
    
        a = age;    
    }
    
    Person() {}
    
    void enterFirstName(string firstname);
    void enterSecondName(string secondname);
    void enterAge(string age);
    
    const string firstName() {return fn;}
    const string secondName() {return sn;}
    const string age() {return a;}

private: 
    string fn;
    string sn;
    string a;
};

//Kamil Petk
//07.04.2020
