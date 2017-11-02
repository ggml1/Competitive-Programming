#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oi() cout << "oi\n";
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 0x3f3f3f3f;
const int ms = 1e5 + 5;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(4);

    int n; cin >> n;

    while(n){
    	int ans = 0;
    	int mx = 0;

    	for(int i = 0; i < n; ++i){
    		int x; cin >> x;
    		ans += x;
    		if(ans < 0) ans = 0;
    		else if(ans > mx) mx = ans;
    	}

    	if(mx == 0) cout << "Losing streak.\n";
    	else cout << "The maximum winning streak is " << mx << ".\n";

    	cin >> n;
    }

    return 0;
}