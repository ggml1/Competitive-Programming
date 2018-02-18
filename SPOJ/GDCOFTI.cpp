#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b){
	if(a == 0) return b;

	return gcd(b%a, a);
}
 
int main(){
 
	ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);

	printf("%lld\n", gcd(a, gcd(b, c)));
 
	return 0;
}  