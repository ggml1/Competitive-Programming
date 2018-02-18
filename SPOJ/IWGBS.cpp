#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

struct Number {
	string str;

	Number() {
		this->str = "-1";
	}

	Number (string x) {
		this->str = x;
	}

	bool operator!=(int x) const {
		return this->str != to_string(x);
	}

	Number operator+(Number x){
		string a = x.str;

		int sz1 = a.size();
		int sz2 = this->str.size();

		int n1[sz1];
		int n2[sz2];

		for(int i = sz1 - 1; i >= 0; --i){
			n1[i] = a[i] - '0';
		}

		for(int i = sz2 - 1; i >= 0; --i){
			n2[i] = this->str[i] - '0';
		}

		vector<int> n3(max(sz1, sz2) + 1, 0);

		int j, k;

		for(int i = sz1 - 1, j = sz2 - 1, k = 0; i >= 0 || j >= 0; --i, --j, ++k){
			if(i >= 0 && j >= 0) n3[k] += n1[i] + n2[j];
			else if(i >= 0) n3[k] += n1[i];
			else if(j >= 0) n3[k] += n2[j];
			
			if(n3[k] >= 10){
				n3[k] %= 10;

				n3[k + 1]++;
			}

			n3[k] = cur;
		}

		string ret = "";

		for(int i = n3.size() - 1; i >= 0; --i){
			ret += (n3[i] + '0');
		}

		while(ret.size() > 1 && ret[0] == '0') ret.erase(ret.begin());

		Number ofRet(ret);

		return ofRet;
	}
};

const int N = 1e4 + 2;

Number dp[N][2];

Number solve(int cur, int prev, int end){
	if(cur == end){
		Number ret("1");
		return ret;
	}

	if(dp[cur][prev] != -1) return dp[cur][prev];

	if(prev == 1) return dp[cur][prev] = solve(cur + 1, prev, end) + solve(cur + 1, 0, end);

	return dp[cur][prev] = solve(cur + 1, 1, end);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

   	int n; cin >> n;

   	Number ans = solve(1, 1, n) + solve(1, 0, n);

   	cout << ans.str << endl;

    return 0;
}
