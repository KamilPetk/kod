#include "std_lib_facilities.hpp"

//kod z ksiazki
//
//Message* get_input(Device&); // make a Message on the free store
//while(/* . . . */) {
// Message* p = get_input(dev);
// . . .
//Node* n1 = new Node(arg1,arg2);
// . . .
//delete p;
//Node* n2 = new Node (arg3,arg4);
// . . .
//}
//oraz
//
//while( . . . ) {
// Node* n1 = new Node;
// Node* n2 = new Node;
// Message* p = get_input(dev);
// . . . store information in nodes . . .
// delete p;
// . . .
//}
//zgodnie z powyzym:

struct Node
{
   int node1;
   int node2;
   Node *left;
   Node *right;
   Node(Node* left = nullptr, Node* right = nullptr)
            :left(left), right(right){}
   Node(int& node1, int& node2, Node* left = nullptr, Node* right = nullptr)
            :node1(node1), node2(node2), left(left), right(right){}
};

struct Message
{
    string mess;
    Message(string& mess)
        :mess(mess){}
};
//Message* get_input(Device&);
Message* get_input(istream& is)
{
    string mess;
    getline(is, mess);
    return new Message(mess);
}

int main()
try{
    //TEST
    //string test1 = "test1";
    //Message mess(test1);
    cout << "Message " << sizeof(Message) << " > " << sizeof(Node) << " Node" << endl;

    int arg1 = 1;
    int arg2 = 2;
    int arg3 = 3;
    int arg4 = 4;
    vector<Message*> mvec;
    vector<Node*> nvec;
    int i = 0;
    cout << "Enter 10 string " << endl;
    //zgodnie ze wzorem z ksiazki:
    while(i < 10)
    {
        Message* p = get_input(cin);
        mvec.push_back(p);//przechowuje adres p
        Node* n1 = new Node(arg1, arg2);
        delete p;
        nvec.push_back(n1);//przechowuje adres n1
        Node* n2 = new Node(arg3, arg4);
        nvec.push_back(n2);//przechowuje adres n2
        ++i;
    }
    cout << "p address: " << endl;
    for(auto i : mvec)
        cout << i << endl;

    cout << "n1 and n2 address: " << endl;
    for(auto i : nvec)
        cout << i << endl;

    cout << "Second loop" << endl;
    vector<Message*> mvec2;
    vector<Node*> nvec2;
    cout << "Enter 10 string " << endl;
    int j = 0;
    while(j < 10)
    {
        Node* n3 = new Node;
        Node* n4 = new Node;
        Message* p1= get_input(cin);
        mvec2.push_back(p1);//przechowuje adres p
        delete p1;
        nvec2.push_back(n3);//przechowuje adres n1
        nvec2.push_back(n4);//przechowuje adres n2
        ++j;
    }

    cout << "p address: " << endl;
    for(auto i : mvec2)
        cout << i << endl;

    cout << "n1 and n2 address: " << endl;
    for(auto i : nvec2)
        cout << i << endl;

    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    return 1;
}
catch (...) {
    cerr << "exception!\n"; // write error message
    return 2;
}
//Kamil Petk
//17.05.2020
