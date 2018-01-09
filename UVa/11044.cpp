#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int t; cin >> t;

	while(t--){
		int a, b; cin >> a >> b;

		cout << (a/3)*(b/3) << endl;
	}

    return 0;
}