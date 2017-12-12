#include <bits/stdc++.h>

#define fi first
#define se second
#define PI 3.14159265
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll ms = 500001;
const ll mod = 10000;
const int N = 1e6 + 5;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string a;
    
    while(getline(cin, a)){
        int n = a.size();

        string final;

        int begPos = 0;

        int w = 1;

        for(int i = 0; i < n; ++i){
            string aux;
            if(a[i] == '['){
                w = 0;
                begPos = 0;
            } else if(a[i] == ']'){
                w = 1;
            } else{
                switch(w){
                    case 0:
                        aux = a[i];
                        final.insert(begPos++, aux);
                        break;
                    case 1:
                        final += a[i];
                        break;
                }
            }
        }

        cout << final << endl;   
    }
 
    return 0;
} 