#include <bits/stdc++.h>

#define fi first
#define se second
#define PI 3.14159265
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

int ans;
vector<int> chosen;

void solve(int ch, int time, int n, int q, int songs[], vector<int> actual){
    if(ch == q){
        if(time > ans){
            ans = time;
            chosen = actual;
        }
    } else{
        bool nth = 1;
        for(int i = ch; i < q; ++i){
            if(time + songs[i] <= n){
                actual.push_back(songs[i]);
                solve(i+1, time + songs[i], n, q, songs, actual);
                actual.pop_back();
                nth = 0;
            }
        }
        if(nth){
           if(time > ans){
               ans = time;
               chosen = actual;
           }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(4);

    int n;

    while(cin >> n){
        int q; cin >> q;

        int songs[q];

        for(int i = 0; i < q; ++i){
            cin >> songs[i];
        }

        vector<int> actual;

        chosen.clear();

        ans = -1;

        solve(0, 0, n, q, songs, actual);

        for(auto k : chosen){
            cout << k << ' ';
        }

        cout << "sum:" << ans << endl;
    }

    return 0;
} 