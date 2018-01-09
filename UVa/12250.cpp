#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	map<string, string> eq;
	int kse = 0;

	eq["HELLO"] = "ENGLISH";
	eq["HOLA"] = "SPANISH";
	eq["BONJOUR"] = "FRENCH";
	eq["HALLO"] = "GERMAN";
	eq["CIAO"] = "ITALIAN";
	eq["ZDRAVSTVUJTE"] = "RUSSIAN";

	string a;

	while(getline(cin, a) && a.compare("#") != 0){
		++kse;
		cout << "Case " << kse << ": ";
		
		if(eq.count(a)) cout << eq[a] << endl;
		else cout << "UNKNOWN" << endl;
	}

    return 0;
}