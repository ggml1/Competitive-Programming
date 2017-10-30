#include <bits/stdc++.h>
 
#define fr(a, b, c) for(int a = b, _ = c; a < _; ++a)
#define mset(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oi() cout << "oi\n";
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
bool okok(int stalls[], int n, int c, int ds){
	int ct = 1;
	int la = stalls[0];
	fr(i, 1, n){
		if(stalls[i] - la >= ds){
			ct++;
			la = stalls[i];
		}
		if(ct == c) return 1;
	}
 
	return 0;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(7);
 
    int t; cin >> t;
 
    while(t--){
    	int n, c; cin >> n >> c;
 
    	int stalls[n];
 
    	fr(i, 0, n) cin >> stalls[i];
 
    	sort(stalls, stalls + n);
 
    	int lo = 1, hi = int(1e9)+1;
 
    	while(lo + 1 < hi){
    		int mid = lo + (hi - lo)/2;
 
    		if(okok(stalls, n, c, mid)){
    			lo = mid;
    		} else hi = mid;
    	}
 
    	cout << lo << endl;
    }
 
    return 0;
} 