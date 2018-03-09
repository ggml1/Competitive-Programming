#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h(string str, int len){
    int ret = 0;

    for(int i = 0; i < len; ++i){
        ret += ((int) str[i]) * (i + 1);
    }

    return 19 * ret;
}

int hahash(string str, int len, string table[]){
    int c = h(str, len);
    int t1 = c % 101;

    int j = 1;

    while(table[t1].size() != 0){
        if(j == 20) return -1;

        t1 = (c + j * j + 23 * j) % 101;

        ++j;
    }

    return t1;
}

int main(){
    ios::sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        set<string> has;
        string table[150];

        for(int i = 0; i < n; ++i){
            string line; cin >> line;
            string str = line.substr(4);

            if(line[0] == 'A'){
                if(has.count(str) == 0){
                    int key = hahash(str, str.length(), table);

                    if(key != -1){
                        table[key] = str;
                        has.insert(str);
                    }
                }
            } else{
                if(has.count(str)){
                    has.erase(str);

                    for(int j = 0; j < 150; ++j){
                        if(table[j].compare(str) == 0){
                            table[j] = "";
                            break;
                        }
                    }
                }
            }
        }

        cout << has.size() << endl;

        for(int i = 0; i < 150; ++i){
            if(table[i].size() != 0){
                cout << i << ":" << table[i] << endl;
            }
        }
    }

    return 0;
}