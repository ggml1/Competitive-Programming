#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 7995;

bool sieve[N];
vector<int> sp;
ll dp[N][5];

void erat(){
    memset(sieve, 1, sizeof(sieve));

    for(int i = 2; i < N; ++i){
        if(sieve[i]){
            for(int j = i + i; j < N; j += i){
                sieve[j] = 0;
            }
        }
    }
}

ll solve(int n, int k){
    if(n == 0) return 1;

    if(k == 0 || n < 0) return 0;

    if(dp[n][k] != -1) return dp[n][k];

    return dp[n][k] = solve(n - k, k) + solve(n, k - 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    erat();

    for(int i = 2; i < N; ++i){
        if(sieve[i] && i % 4 == 1 || i == 2){
            sp.push_back(i);
        }
    }

    int t; cin >> t;

    memset(dp, -1, sizeof(dp));

    while(t--){
        int n, k; cin >> n >> k;

        cout << solve(sp[n - 1], k) << endl;
    }

    return 0;
}