#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;



int main(){
	fast_io;

	int t; cin >> t;

	while(t--){
		string a; cin >> a;

		int n = a.size();

		if(a.compare("1") == 0 || a.compare("4") == 0 || a.compare("78") == 0) cout << "+" << endl;
		else if(n >= 2 && a[n - 1] == '5' && a[n - 2] == '3') cout << '-' << endl;
		else if(n >= 3 && a[n - 1] == '4' && a[0] == '9') cout << '*' << endl;
		else cout << '?' << endl;
	}

    return 0;
}