#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0); cout << fixed << setprecision(2);

    int t; cin >> t; cin.ignore();

    while(t--){
        string s; getline(cin, s);

        int ans = 0;

        for(char c : s){
            if(c == 'M') ans++;
            else if(c == 'F') ans--;
        }

        if(ans == 0 && s.size() >= 5) cout << "LOOP" << endl;
        else cout << "NO LOOP" << endl;
    }
 
    return 0;
}