#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 7995;

bool sieve[N];
vector<int> sp;
ll dp[5][N];

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

void pre(){
    for(int i = 1; i <= 4; ++i){
        for(int j = 0; j < N; ++j){
            if(j == 0 || i == 1) dp[i][j] = 1;
            else if(j >= i) dp[i][j] = dp[i][j - i] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
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

    pre();

    while(t--){
        int n, k; cin >> n >> k;

        cout << dp[k][sp[n - 1]] << endl;
    }

    return 0;
}