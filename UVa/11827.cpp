#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n; cin.ignore();

	while(n--){

		string a; getline(cin, a);

		stringstream k(a);

		int x, cnt = 0;

		vector<int> nbs;

		while(k >> x){
			nbs.push_back(x);
			cnt++;
		}

		map<ll, ll> div;

		int grtst = 1;

		for(int i = 0; i < cnt; ++i){
			for(int k = 1, c = sqrt(nbs[i]); k <= c; ++k){
				if(nbs[i]%k == 0){
					div[k]++;
					if(div[k] >= 2 && k > grtst){
						grtst = k;
					}
					if(k != nbs[i]/k){
						div[nbs[i]/k]++;
						if(div[nbs[i]/k] >= 2 && nbs[i]/k > grtst){
							grtst = nbs[i]/k;
						}
					}
				}
			}
		}

		cout << grtst << endl;
	}
	
	return 0;
}
