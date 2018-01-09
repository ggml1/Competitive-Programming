#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int t; cin >> t;

	while(t--){
		int a, b; cin >> a >> b;

		if(a > b) cout << ">" << endl;
		else if(a < b) cout << "<" << endl;
		else cout << "=" << endl;
	}

    return 0;
}