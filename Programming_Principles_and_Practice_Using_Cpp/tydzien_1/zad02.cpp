#include "std_lib_facilities.hpp"
int main()
{
 cout << "Enter the name of the person you want to write to:\n";
 string first_name; // first_name is a variable of type string
 string friend_name;
 char friend_sex = 0;
 int age;

 cin >> first_name; // read characters into first_name
 cout << "Dear " << first_name << ",\n";
 cout << "   How are you? \n I am fine.\n";
 cout << "Enter the name of another friend: \n";
 cin >> friend_name;
 cout << "Have you seen " << friend_name << " lately?\n";
 cout << "Enter m if your friend is male and f if your friend is female: ";
 cin >> friend_sex;
    if(friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me \n";
    if(friend_sex == 'f')
        cout << "If you see" << friend_name << " please ask her to call me \n";

cout << "Enter the age of the recipient: \n";
cin >> age;
    if(age <= 0 || age >= 110)
        simple_error("you're kidding!");
    else
        cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if(age < 12)
        cout << "Next year you will be " << age+1 << ".\n";
    if(age == 17)
        cout << "Next year you will be able to vote.\n";
    if(age > 70)
        cout << "I hope you are enjoying retirement.\n";

    cout << "Yours sincerely,\n\n";
    cout << "Kamil Petk";
}
//Kamil Petk 27.02.2020
