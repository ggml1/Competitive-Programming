#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		cout << (abs(((((n*63) + 7492)*5)-498))%100)/10 << endl;
	}

    return 0;
}