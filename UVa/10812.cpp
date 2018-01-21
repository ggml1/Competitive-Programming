#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);

	int t; cin >> t;

	while(t--){
		int a, b; cin >> a >> b;

		if(b > a || (b%2 && !(a%2)) || (!(b%2) && (a%2))){
			cout << "impossible\n";
		} else{
			int x = (a + b) >> 1;
			int y = (a - b) >> 1;
			cout << max(x, y) << ' ' << min(x, y) << endl;
		}
	}

	return 0;
}