#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;

const double eps = 1e-6;

int sum(int total){
    int ret = 0;

    while(total){
        ret += total%10;

        total /= 10;
    }

    return ret;
}

double work(string s){
    int total = 0;

    for(char c : s){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) total += tolower(c) - 'a' + 1;
    }

    while(total >= 10){
        total = sum(total);
    }

    return (double) total;
}
 
int main(){
    ios::sync_with_stdio(0); cout << fixed << setprecision(2);

    int n;

    while(cin >> n && n != 0){
        int k; cin >> k;

        set<string> freddie;

        for(int i = 0; i < n; ++i){
            string s; cin >> s;

            freddie.insert(s);
        }

        bool cant = 0;

        for(int i = 0; i < k; ++i){
            int cur, need; cin >> cur >> need;

            int total = 0;

            for(int j = 0; j < cur; ++j){
                string h; cin >> h;

                if(freddie.count(h)) total++;
            }

            if(total < need){
                cant = 1;
            }
        }

        if(cant) cout << "no" << endl;
        else cout << "yes" << endl;
    }
 
    return 0;
}