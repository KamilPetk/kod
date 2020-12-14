#include "std_lib_facilities.hpp"
#include <set>

struct Fruit { //page 788
     string name;
     int ccount;
     double unit_price;
     Fruit()
        {}
     Fruit(string name, int ccount, double unit_price = 0.0)
        :name(name), ccount(ccount), unit_price(unit_price)
        {}

    // Date last_sale_date;
     // . . .
};

struct Fruit_comparison { //page 788
     bool operator()(const Fruit* a, const Fruit* b) const
     {
        return a -> name < b -> name; //z uwagi na wskazniki
     }
};

int main()
try{
    set<Fruit*, Fruit_comparison> inventory;

    inventory.insert(new Fruit("quince",5));
    inventory.insert(new Fruit("apple",200,0.37));
    inventory.insert(new Fruit("orange",300,0.57));
    inventory.insert(new Fruit("banana",100,0.89));

    for (const auto& x : inventory) //page 789
        cout << x->name << "\t" << x->ccount << "\t" << x->unit_price << '\n';
    //ROZNICE
    //W tej implementacji z uwagi na wskaznik ustawiony na obiekt klasy *Fruit
    //nalezalo skorzystac z operatora -> aby odniesc sie do elementow skladowych
    //tego obiektu

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
//05.05.2020
