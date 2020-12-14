#include "std_lib_facilities.hpp"

struct Item
{
    Item()
        {}
    Item(string name, int iid, double value)
        :name(name), iid(iid), value(value)
        {}
    string name;
    int iid;
    double value;
};

istream& operator>>(istream& is, Item& item)
{
    string newString;
    int newInt;
    double newDouble;
    is >> newString >> newInt >> newDouble;
    item = Item(newString, newInt, newDouble);
    return is;
}

ostream& operator<<(ostream& os, Item& item)
{
    os << item.name << " " << item.iid << " " << item.value << " ";
    return os;
}

struct Cmp_by_name //page 768
{
    bool operator()(const Item& one,const Item& two) const
    {
        return one.name < two.name;
    };
};

struct Cmp_by_iid//page 768
{
    bool operator()(const Item& one,const Item& two) const
    {
        return one.iid < two.iid;
    };
};

struct Cmp_by_value//page 768
{
    bool operator()(const Item& one,const Item& two) const
    {
        return one.value > two.value;
    };
};

struct Remove_by_name//page 768
{
string nameRemove;
public:
    Remove_by_name(string nameRemove)
        :nameRemove(nameRemove)
        {}
    bool operator()(const Item& one) const
    {
        return one.name == nameRemove;
    };
};

struct Remove_by_iid//page 768
{
int iidRemove;
public:
    Remove_by_iid(int iidRemove)
        :iidRemove(iidRemove)
        {}
    bool operator()(const Item& one) const
    {
        return one.iid == iidRemove;
    };
};

//make_pair 782 page
void reads_value_pairs(map<string, int>& msi)
{
    string newValueString;
    int newValueInt;
    for(int i = 0; i < 10; i++)
    {
        cin >> newValueString >> newValueInt;
        msi.insert(make_pair(newValueString, newValueInt));
    }
}

int calculate(int v, pair<string, int>& p)
{
    return v += p.second;
}

class Less_than { //page 765
    int v;
public:
    Less_than(int vv) : v(vv) { } // store the argument
    bool operator()(int x) const { return x<v; } // compare
};

int main()
try{
    vector<Item> vi;
    string from = "values.txt";

    ifstream is{from};

    Item values;
    //cout << values;
    while(is >> values)
        vi.push_back(values);
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;;
    is.close();
    cout << endl;

    cout << "Sort vi by name:" << endl;
    sort(vi.begin(), vi.end(), Cmp_by_name());
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;
    cout << endl;

    cout << "Sort vi by iid:" << endl;
    sort(vi.begin(), vi.end(), Cmp_by_iid());
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;
    cout << endl;

    cout << "Sort vi by value(largest value first):" << endl;
    sort(vi.begin(), vi.end(), Cmp_by_value());
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;
    cout << endl;

    Item new1("horse shoe",99,12.34);
    Item new2("Canon S400", 9988,499.95);

    vi.push_back(new1);
    vi.push_back(new2);
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;
    cout << endl;

    cout << "Remove \"Kamil\" and \"Canon\"" << endl;
    auto r = find_if(vi.begin(), vi.end(), Remove_by_name("Kamil")); //page 758
    vi.erase(r);
    r = find_if(vi.begin(), vi.end(), Remove_by_name("Canon")); //page 758
    vi.erase(r);
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;
    cout << endl;

    cout << "Remove \"2\" and \"8\"" << endl;
    r = find_if(vi.begin(), vi.end(), Remove_by_iid(2)); //page 758
    vi.erase(r);
    r = find_if(vi.begin(), vi.end(), Remove_by_iid(8)); //page 758
    vi.erase(r);
    for(int i = 0; i < vi.size(); ++i)
        cout << vi[i] << endl;
    cout << endl;
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    //LIST
    cout << "LIST:" << endl;
    list<Item> lis;
    Item valuesList;
    ifstream isList{from};
    while(isList >> valuesList)
        lis.insert(lis.end(), valuesList);
    isList.close();
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;

    cout << "Sort list by name:" << endl;
    lis.sort(Cmp_by_name());
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;

    cout << "Sort list by iid:" << endl;
    lis.sort(Cmp_by_iid());
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;

    cout << "Sort list by value(largest value first):" << endl;
    lis.sort(Cmp_by_value());
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;

    lis.insert(lis.end(), new1);
    lis.insert(lis.end(), new2);
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;

    cout << "Remove \"Kamil\" and \"Kacper\"" << endl;
    list<Item>::iterator pl = find_if(lis.begin(), lis.end(), Remove_by_name("Kamil"));
    lis.erase(pl);
    pl = find_if(lis.begin(), lis.end(), Remove_by_name("Kacper"));
    lis.erase(pl);
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;

    cout << "Remove \"5\" and \"15\"" << endl;
    pl = find_if(lis.begin(), lis.end(), Remove_by_iid(5));
    lis.erase(pl);
    pl = find_if(lis.begin(), lis.end(), Remove_by_iid(15));
    lis.erase(pl);
    for(list<Item>::iterator p = lis.begin(); p != lis.end(); ++p)
        cout << *p << endl;
    cout << endl;
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//MAP
    cout << "MAP" << endl;

    map<string, int> msi;
    msi["lecture"] = 21;
    msi["person1"] = 15;
    msi["person2"] = 65;
    msi["person3"] = 55;
    msi["person4"] = 5;
    msi["person5"] = 23;
    msi["person6"] = 51;
    msi["person7"] = 13;
    msi["person8"] = 43;
    msi["person9"] = 6;
    int i = 0;
    for (const auto& p : msi) //page 777
        cout << p.first << ": " << p.second << '\n';

    msi.erase(msi.begin(),msi.end());
    for (const auto& p : msi) //page 777
        cout << p.first << ": " << p.second << '\n';
    cout << endl;
    cout << "Enter 10 pairs: " << endl;
    reads_value_pairs(msi);

    for (const auto& p : msi) //page 777
        cout << p.first << ": " << p.second << '\n';

    //page 759
    int sumMsiInt = accumulate(msi.begin(), msi.end(), 0, [](int value, const map<string, int>::value_type& p){return value += p.second;});
    cout << "Sum integer values = " << sumMsiInt << endl;

    map<int, string> mis;
    for (const auto& p : msi)
        mis[p.second] = p.first;
    cout << "mis:" << endl;
    for (const auto& p : mis)
        cout << p.first << ": " << p.second << '\n';
    cout << endl;
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//MORE VECTOR
    cout << "MORE VECTOR:" << endl;
    vector<double> vd;
    string from_double = "values_double.txt";

    ifstream is_double{from_double};

    double values_double;
    //cout << values;
    while(is_double >> values_double)
        vd.push_back(values_double);
    for(int i = 0; i < vd.size(); ++i)
        cout << vd[i] << endl;;
    is.close();
    cout << endl;

    vector<int> vi2(vd.size());
    copy(vd.begin(), vd.end(), vi2.begin());
    cout << "vd and vi" << endl;
    for(int i = 0; i < vi2.size(); ++i)
        cout << vd[i] << "\t" << vi2[i] << endl;

    double sumDouble = accumulate(vd.begin(), vd.end(), 0.0, [](double value, const vector<double>::value_type& p){return value += p;});
    cout << "Sum double values = " << sumDouble << endl;

    int sumVi2 = accumulate(vi2.begin(), vi2.end(), 0, [](int value, const vector<int>::value_type& p){return value += p;});
    cout << "sum vd elements - sum vi elements = " << sumDouble - sumVi2 << endl;

    cout << "reverse:" << endl;
    reverse(vd.begin(), vd.end());
    for(int i = 0; i < vd.size(); ++i)
        cout << vd[i] << endl;;
    cout << endl;

    cout << "mean value of elements = ";
    double mean_value = sumDouble / vd.size();
    cout << mean_value << endl;
    cout << endl;

    int sizeVec = count_if(vd.begin(), vd.end(), Less_than(mean_value));
    vector<double> vd2(sizeVec);
    cout << "vd2" << endl;
    copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(mean_value));
    for(int i = 0; i < vd2.size(); ++i)
        cout << vd2[i] << endl;;
    cout << endl;

    cout << "sort vd:" << endl;
    sort(vd.begin(), vd.end());
    for(int i = 0; i < vd.size(); ++i)
        cout << vd[i] << endl;;
    cout << endl;
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
//04.05.2020
