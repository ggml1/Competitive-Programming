#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll fexp(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
 
    int n; cin >> n;
    int c = 0;
 
    while(n--){
        ++c;
        ll a, b, mod; cin >> a >> b >> mod;
 
        cout << c << ". " << fexp(a, b, mod) << endl;
    }
    
    return 0;
} 