#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0); cout << fixed << setprecision(2);

    int n;
    int caso = 0;

    while(cin >> n){
        if(caso != 0) cout << endl;
        ++caso;

        pair<string, pii> people[n];

        for(int i = 0; i < n; ++i){
            string s; cin >> s;

            people[i] = {s, {0, 0}};
        }

        for(int i = 0; i < n; ++i){
            string s; int m, k; cin >> s >> m >> k;

            if(k != 0){
                int each = m / k;

                for(int j = 0; j < n; ++j){
                    if(people[j].first.compare(s) == 0){
                        people[j].second.first = each * k;
                        break;
                    }
                }

                for(int j = 0; j < k; ++j){
                    string to; cin >> to;

                    for(int l = 0; l < n; ++l){
                        if(people[l].first.compare(to) == 0){
                            people[l].second.second += each;
                            break;
                        }
                    }
                }
            }
        }

        for(auto k : people){
            cout << k.first << ' ' << k.second.second - k.second.first << endl;
        }
    }
 
    return 0;
}