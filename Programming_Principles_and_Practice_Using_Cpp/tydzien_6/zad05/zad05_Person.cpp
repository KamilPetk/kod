#include "zad05_Person.hpp"
#include "std_lib_facilities.hpp"

void Person::enterFirstName(string firstname)
{
    for (char ch : firstname) 
    {
        if (!isalpha(ch)) //isalpha: book 397 page
            error("You can't use ; : \" ' [ ] * & ^ % $ # @ ! ");
    }
    fn = firstname;
}

void Person::enterSecondName(string secondname)
{
    for (char ch : secondname) 
    {
        if (!isalpha(ch)) //isalpha: book 397 page
            error("You can't use ; : \" ' [ ] * & ^ % $ # @ ! ");
    }
    sn = secondname;
}
 
void Person::enterAge(string age)
{
    
    for(char ch : age)
        if(!isdigit(ch)) error("Bad value"); //isdigit: book 397 page

    int ageInt = stoi(age); //string to int
    
    if(ageInt<0 || ageInt >=150)
    {
        error("Bad value");
    }
    
    a = age;
}

//Kamil Petk
//07.04.2020
