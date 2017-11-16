#include <bits/stdc++.h>

#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int ms = 1234;

int qtdSol;

bool sieve[ms];
vector<int> primes;

bool valid(int x, int y, int actual[]){
	for(int i = 0; i < 8; ++i){
		if(i != y && actual[i] != -1){
			if(actual[i] == x) return 0;
			if(abs(i - y) == abs(x - actual[i])) return 0;
		}
	}
	return 1;
}

void bt(int actual[], vector<string>& solutions, int done){
	if(done == 8){
		string a;
		for(int i = 0; i < 8; ++i){
			a += to_string(actual[i] + 1);
			if(8 - i != 1) a += " ";
		}
		solutions.push_back(a);
		qtdSol++;
	} else{
		if(actual[done] != -1) bt(actual, solutions, done+1);
		else{
			for(int i = 0; i < 8; ++i){
				if(valid(i, done, actual)){
					actual[done] = i;
					bt(actual, solutions, done+1);
					actual[done] = -1;
				}
			}
		}
	}
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int kse = 0;

    if(n == 0) return 0;

    while(n--){
    	kse++;
    	if(kse != 1) cout << endl;

    	cout << "SOLN       COLUMN" << endl;
    	cout << " #      1 2 3 4 5 6 7 8" << endl;
    	cout << endl;

    	/// cout << " " << number << "      ";

    	int x, y; cin >> x >> y; x--; y--;

    	vector<string> solutions;

    	int actual[8];

    	memset(actual, -1, sizeof(actual));

    	actual[y] = x;

    	qtdSol = 0;

    	bt(actual, solutions, 0);

    	if(qtdSol != 0) sort(solutions.begin(), solutions.end());

    	for(int i = 0; i < qtdSol; ++i){
    		if(i < 9) cout << " ";
    		cout << i+1 << "      " << solutions[i] << endl;
    	}
    }

    return 0;
}
