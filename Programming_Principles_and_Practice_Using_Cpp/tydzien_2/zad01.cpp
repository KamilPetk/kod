#include "std_lib_facilities.hpp"

int main() {
	try {
		cout << "1. Success!\n";
		cout << "2. Success!\n";
		cout << "3. Success" << "!\n";
		cout << "4. Success!" << '\n';
		string res = "7"; vector<string> v(10); v[5] = res; cout << "5. Success!\n";
		vector<int> v1(10); v1[5] = 7; if (v1[5]==7) cout << "6. Success!\n";
		int cond = 1; if (cond == 1) cout << "7. Success!\n"; else cout << "Fail!\n";
        	bool c = false; if (c == false) cout << "8. Success!\n"; else cout << "Fail!\n";
		string s = "ape"; string boo = "fool"; if (boo == "fool") cout << "9. Success!\n";
		string s1 = "ape"; if (s1!="fool") cout << "10. Success!\n";
		string s2 = "ape"; if (s2!="fool") cout << "11. Success!\n";
		string s3 = "ape"; if (s3!="fool") cout << "12. Success!\n";
		vector<char> v2(5); for (int i=0; i<v2.size(); ++i); cout << "13. Success!\n";
		vector<char> v3(5); for (int i=0; i<=v3.size(); ++i) ; cout << "14. Success!\n";
        	string s4 = "15. Success!\n"; for (int i=0; i<6; ++i) cout << s4;
		if (true) cout << "16. Success!\n"; else cout << "Fail!\n";
        	int x = 50; char c1 = x; if (c1=='2') cout << "17. Success!\n";
		string s5 = "18. Success!\n"; for (int i=0; i<10; ++i) cout << s5;
		vector<int> v4(5); for (int i=0; i<=v4.size(); ++i) ; cout << "19. Success!\n";
		int i=0; int j = 9; while (i<10) ++i; if (j<i) cout << "20. Success!\n";
       		int x1 = 2; double d = 5/(x1-1); if (d==2*x1+1) cout << "21. Success!\n";
        	vector<string> s6(10); for(int i = 0; i<s6.size(); ++i) s6[i] = "22. Success!\n"; for (int i=0; i<10; ++i) cout << s6[i];
        	int i1=10; int j1=0; while (i<10) ++j1; if (j1<i1) cout << "23. Success!\n";
        	int x2 = 4; double d1 = 5/(x2-2); if (d1=2*x2+0.5) cout << "24. Success!\n";
        	cout << "25. Success!\n";
		return 0;

	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}
//Kamil Petk
//06.03.2020