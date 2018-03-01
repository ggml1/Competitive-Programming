#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0);

    int caso = 0;
 
    string s;

    while(getline(cin, s)){
        ++caso;

        int l = s.length();

        if(l == 0) break;

        string curString = "@" + s;

        int zeros[l + 1], ones[l + 1];

        zeros[0] = ones[0] = 0;

        for(int i = 1; i <= l; ++i){
            zeros[i] = zeros[i - 1] + (curString[i] == '0');
            ones[i] = ones[i - 1] + (curString[i] == '1');
        }

        int n; cin >> n;

        cout << "Case " << caso << ":" << endl;

        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;

            ++x;
            ++y;

            if(x > y) swap(x, y);

            // @10000

            if(ones[y] == ones[x - 1] || zeros[y] == zeros[x - 1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

        cin.ignore();
    }
 
    return 0;
}