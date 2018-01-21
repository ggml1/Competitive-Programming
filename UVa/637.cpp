#include <bits/stdc++.h>

#define FRONT 1
#define BACK 0

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);

	int n;

	while(cin >> n && n != 0){
		cout << "Printing order for " << n << " pages:\n";

		int sheet = (n/4) + (n%4 != 0);
		int c1 = 1;
		int c2 = 4*sheet;

		for(int i = 1; i <= sheet; ++i){
			cout << "Sheet " << i << ", " << "front: ";

			if(c2 > n) cout << "Blank, " << c1 << endl;
			else cout << c2 << ", " << c1 << endl;

			if(n == 1) break;

			c2--; c1++;

			cout << "Sheet " << i << ", " << "back : ";

			if(c2 > n) cout << c1 << ", Blank" << endl;
			else cout << c1 << ", " << c2 << endl;

			c2--; c1++;
		}
	}

	return 0;
}