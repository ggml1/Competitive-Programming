#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int t; cin >> t;
	int kse = 0;

	while(t--){
		++kse;
		int a, b, c; cin >> a >> b >> c;

		cout << "Case " << kse << ": " << a + b + c - min(a, min(b, c)) - max(a, max(b, c)) << endl;
	}

    return 0;
}