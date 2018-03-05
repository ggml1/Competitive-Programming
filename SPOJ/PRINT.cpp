#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e6 + 5;

int sieve[N], p[N];
int t, l, u;

void erat(){
    sieve[0] = sieve[1] = 1;

    for(int i = 2; i < N; ++i){
        if(!sieve[i]){
            for(int j = i + i; j < N; j += i){
                sieve[j] = 1;
            }
        }
    }
}

int get(int l, int i){
    int ret;

    if(l % i != 0) ret = l - l % i + i;
    else ret = l;

    if(ret == i) ret <<= 1;

    return ret;
}
 
int main(){
    // ios::sync_with_stdio(0); cout << fixed << setprecision(2);

    scanf("%d", &t);

    erat();

    while(t--){
        scanf("%d%d", &l, &u);

        memset(p, 1, sizeof(p));

        for(int i = 2; i <= u - l; ++i){
            if(!sieve[i]){
                for(int j = get(l, i); j <= u; j += i){
                    p[j - l] = 0;
                }
            }
        }

        for(int i = 0; i <= u - l; ++i){
            if(p[i] && i + l > 1){
                printf("%d\n", i + l);
            }
        }
    }
 
    return 0;
}