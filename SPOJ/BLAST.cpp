#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 4005;
const int inf = 123456;

string s, r;
int blank, sa, sb;
int dp[N][N];

int solve(int x, int y){
    if(x >= sa && y >= sb) return 0;

    if(dp[x][y] != -1) return dp[x][y];

    if(x >= sa) return blank * (sb - y);

    if(y >= sb) return blank * (sa - x);

    return dp[x][y] = min(solve(x + 1, y + 1) + abs(s[x] - r[y]), min(solve(x, y + 1), solve(x + 1, y)) + blank);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s >> r >> blank;

    sa = s.length();
    sb = r.length();

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << endl;

    return 0;
}