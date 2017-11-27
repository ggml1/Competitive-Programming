#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll ms = 500001;
const ll mod = 10000;
 
ll sieve[ms];
bool flag;
 
void doSieve(){
    memset(sieve, 0, sizeof(sieve));

    for(ll i = 2; i <= 250000; ++i){
        for(ll j = 2; j*i <= 500000; ++j){
            sieve[i*j]++;
        }
    }
}

ll fexp(ll x, ll ex){
    ll ret = 1;

    bool sett = 0;

    if(x >= mod){
        x %= mod;
        sett = 1;
    }

    while(ex){
        if(ex & 1){
            ret *= x;
            if(ret >= mod){
                ret %= mod;
            }
            if(sett) flag = 1;
        }
        x *= x;
        if(x >= mod){
            x %= mod;
            sett = 1;
        }
        ex >>= 1;
    }

    return ret;
}
 
int main(){
 
    doSieve();
 
    ll t; scanf("%lld", &t);
 
    while(t--){
        ll n; scanf("%lld", &n);

        ll divs = sieve[n];

        ll ans = 1;

        flag = 0;

        if(divs > 0){
            if(divs%2){
                ans *= (int) sqrt(n);
                if(ans >= mod){
                    flag = 1;
                    ans %= mod;
                }
            }

            ans *= fexp(n, divs/2);

            if(ans >= mod){
                flag = 1;
                ans %= mod;
            }
        }
 
        if(flag){
            printf("%04lld\n", ans);
        } else printf("%lld\n", ans);
    }
 
    return 0;
} 