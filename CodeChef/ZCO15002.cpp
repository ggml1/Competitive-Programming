#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 1;

int main(){
	ios::sync_with_stdio(0); cout << fixed << setprecision(10);

	ll n, k; cin >> n >> k;

	int ans = 0;

	ll x[n];

	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}

	sort(x, x + n);

	int i = 0, j = 1;

	for(int i = 0, j = 1; i < n && j < n; ){
		if(abs(x[i] - x[j]) >= k){
			ans += n - j;
			++i;
		} else ++j;
	}

	cout << ans << endl;

	return 0;
}