#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        int g, l; cin >> g >> l;

        if(l%g != 0) cout << -1 << endl;
        else cout << g << ' ' << l << endl;
    }

    return 0;
}