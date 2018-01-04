#include <bits/stdc++.h>

#define fi first
#define se second
#define PI 3.14159265
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(4);

    int n; cin >> n;

    int mx = 0, wn = 0, p1 = 0, p2 = 0, diff = 0;

    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        p1 += x;
        p2 += y;

        diff = p1 - p2;

        if(diff > 0 && diff > mx){
            mx = diff;
            wn = 1;
        } else if(diff < 0 && -diff > mx){
            mx = -diff;
            wn = 2;
        }
    }

    cout << wn << ' ' << mx;

    return 0;
} 