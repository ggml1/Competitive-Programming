#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int a, b, c, d;

	cin >> a >> b >> c >> d;

	while(a || b || c || d){
		int ans = 1080;

		ans += ((a - b + 40)%40)*9;

		ans += ((c - b + 40)%40)*9;

		ans += ((c - d + 40)%40)*9;

		cout << ans << endl;

		cin >> a >> b >> c >> d;
	}

    return 0;
}