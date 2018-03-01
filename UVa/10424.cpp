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

    string s, s2;

    while(getline(cin, s) && getline(cin, s2)){
        int total = 0;

        double w1 = work(s);
        double w2 = work(s2);

        if(abs(w1 - w2) <= eps) cout << "100.00 %" << endl;
        else{
            if(w2 > w1) swap(w1, w2);
            
            cout << (w2 / w1)*100.00 << " %" << endl;
        }
    }
 
    return 0;
}