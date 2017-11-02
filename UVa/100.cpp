#include <bits/stdc++.h>

#define fi first
#define se second
#define th third
#define pb push_back
#define MOD int(1e9) + 7
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend();
#define dbg(x) cout << "variable '" << #x << "' -> " << x << '\n';
#define oi() cout << "oi" << endl;
#define fr(a, b, c) for(int a = b, _ = c; a < _; ++a)
#define mset(x,y) memset(x, y, sizeof(x));

using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int solve(int a){
	if(a == 1) return 1;
	if(a%2) return 1 + solve(3*a + 1);
	return 1 + solve(a/2);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout << fixed; cout << setprecision(5);

	int i, j;

	while(cin >> i >> j){
		int maior = 0;

		fr(k, min(i, j), max(i, j) + 1){
			int x = solve(k);
			if(x > maior) maior = solve(k);
		}

		cout << i << ' ' << j << ' ' << maior << endl;
	}

	return 0;
}