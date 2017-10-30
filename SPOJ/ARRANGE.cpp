#include <bits/stdc++.h>
 
#define fr(a, b, c) for(int a = b, _ = c; a < _; ++a)
 
using namespace std;
 
typedef long long ll;
 
int main(){   
    ios::sync_with_stdio(0);
 
    int t; cin >> t;
 
    while(t--){
        int n; cin >> n;
 
        int arr = 0;
        vector<int> nbs;
 
        fr(i, 0, n){
            int k; cin >> k;
            if(k == 1) arr++;
            else nbs.push_back(k);
        }
 
        fr(i, 0, arr) cout << 1 << ' ';
 
        sort(nbs.rbegin(), nbs.rend());
 
        if(nbs.size() == 2 && nbs[1] == 2 && nbs[0] == 3){
            cout << 2 << ' ' << 3 << endl;
        } else{
            fr(i, 0, nbs.size()){
                cout << nbs[i] << " \n"[nbs.size() - i == 1];
            }
        }
    }
    return 0;
} 