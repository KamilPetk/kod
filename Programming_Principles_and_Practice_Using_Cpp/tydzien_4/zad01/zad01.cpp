#include "std_lib_facilities.h"

class Point
{
public:
    Point(double x, double y):
        x(x), y(y) {};
    Point() {};
     double x_coordinate() { return x; }
     double y_coordinate() { return y; }

private:
    double x;
    double y;
};

//VECTORS:
 vector<Point> original_points;
 vector<Point> processed_points;

ostream& operator<<(ostream& os, Point& p)
{
 return os << "( " << p.x_coordinate() << " , " << p.y_coordinate() << " )";
}

bool operator==(Point& o, Point& p)
{
    if(o.x_coordinate() == p.x_coordinate() && o.y_coordinate() == p.y_coordinate())
        return true;
    else return false;
}

void save_point(vector<Point> vec, string name)
{
    ofstream ost{name};
    if (!ost) error("can't open output file ",name);
        for(Point p: vec)
            ost << p.x_coordinate() << " " << p.y_coordinate() << "\n";
    ost.close();
}

void read_point(vector<Point>& points, string& name)
{
    ifstream ist{name};
    if (!ist) error("can't open input file ",name);

    double x;
    double y;

    while(ist >> x >> y)
    {
        points.push_back(Point{x,y});
    }
}

void enter_points(vector<Point>& points)
{
    cout << "Enter seven points: " << endl;

    double x, y;
    char comma;
    int i = 0;
    while(i < 7)
    {
        cin >> x >> comma >> y;
        if(comma != ',')
            cout << "Error: you forgot the comma" << endl;
        else
        {
        Point p(x,y);
        points.push_back(p);
        }

        i++;
    }
}

void print_vector(vector<Point> point)
{
    int n = 0;
    for(n; n < point.size(); n++)
        cout << point[n];
}

bool compare_vectors(vector<Point> original, vector<Point> processed)
{
    bool ft = true;
    if(original.size() == processed.size())
    {
        for(int i = 0; i<original.size(); i++)
        {
            if(original[i] == processed[i])
                ft = true;
            else ft = false;
        }
    }
    return ft;
}

int main()
try
{
    string nameMyFile = "mydata.txt";
    enter_points(original_points); //wprowadzenie pkt
            //cout << original_points[1];
    save_point(original_points, nameMyFile); //zapis pkt do pliku

    read_point(processed_points, nameMyFile); //odczyt z pliku

    cout << "Data elements from original_points vector: \n";
    print_vector(original_points);
    cout << endl;
    cout << "Data elements from processed_points vector: \n";
    print_vector(processed_points); //wypisanie punktow z wektora

    cout << endl;

    if(compare_vectors(original_points, processed_points) == true) //porownanie obu wektorow
        cout << "The vectors are equal";
    else cout << "The vectors are not equal";

    cout << endl;
    keep_window_open();
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
//20.03.2020
