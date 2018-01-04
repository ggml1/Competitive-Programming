#include <bits/stdc++.h>

#define fi first
#define se second
#define PI 3.14159265
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(4);

    int n, h; cin >> n >> h;
    
    int stacks[n];

    for(int i = 0; i < n; ++i){
        cin >> stacks[i];
    }

    int cmd; cin >> cmd;
    int pos = 0, available = 1;
    
    while(cmd){
        switch(cmd){
            case 1:
                if(pos >= 1) pos--;
                break;
            case 2:
                if(pos <= n-2) pos++;
                break;
            case 3:
                if(available && stacks[pos] > 0){
                    stacks[pos]--;
                    available = 0;
                }
                break;
            case 4:
                if(!available && stacks[pos] < h){
                    stacks[pos]++;
                    available = 1;
                }
                break;
        }

        cin >> cmd;
    }

    for(int i = 0; i < n; ++i){
        cout << stacks[i] << " \n"[n - i == 1];
    }

    return 0;
} 