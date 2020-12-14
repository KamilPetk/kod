#include "std_lib_facilities.h"

vector<string> name;
vector<double> age;
int howMany;

void save_names(string name_from_user)
{
    string checkedName;
    for(int i = 0; i< name_from_user.size(); ++i)
        if(isalpha(name_from_user[i]))
            checkedName += name_from_user[i];
        else
        {
          cout << "Invalid name" << endl;
          return;
        }

    name.push_back(checkedName);
}

void save_age(double age_from_user)
{
    age.push_back(age_from_user);
}

void print(vector<string> names, vector<double> ages)
{
    int j = 0;
    int sizeVec = names.size();
    while(j<sizeVec)
    {
        cout << "Name: " << names[j] << " age: " << ages[j] << endl;
        j++;
    }
}

void pairsVectors(vector<string> names, vector<double> ages)
{
    vector<int> number;
    vector<string> copyName = names;
    vector<double> copyAge = ages;
    int sizeVecName = copyName.size();

    sort(names.begin(), names.end());

    int w = 0;
    for(int n = 0; n<sizeVecName; n++)
    {
        for(int k = 0; k < sizeVecName; k++)
        {
            if( names[n] == copyName[k])
            {
                number.push_back(k);
            }
        }
    }
    for(int n = 0; n<sizeVecName; n++)
        copyAge[n] = ages[number[n]];

     copyName = names;

    cout << "After sort: " << endl;
    print(copyName, copyAge);
}

void enterName()
{
    string name_from_user;

    cout << "How many names do you want to add?" << endl;

    cin >> howMany;

    cout << "Please enter " << howMany << " names: " << endl;
    for(int i = 0; i<howMany; i++)
    {
        cin >> name_from_user;
        save_names(name_from_user);
    }
}

void enterAge()
{
    double age_from_user;

    cout << "Enter ages of the people named: " << endl;
    for(int i = 0; i<howMany; i++)
    {
        cin >> age_from_user;
        save_age(age_from_user);
    }
}

int main()
try
{
    enterName();

    enterAge();

    print(name, age);

    pairsVectors(name, age);

    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception!\n"; // write error message
    keep_window_open("~~");
    return 2;
}
//Kamil Petk
//18.03.2020
