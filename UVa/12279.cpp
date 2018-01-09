#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int n; cin >> n;
	int kse = 0;

	while(n){
		int a = 0, b = 0;
		++kse;

		for(int i = 0; i < n; ++i){
			int x; cin >> x;

			a += (x == 0);
			b += (x > 0);
		}

		cout << "Case " << kse << ": " << b - a << endl;

		cin >> n;
	}

    return 0;
}