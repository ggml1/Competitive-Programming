#include <bits/stdc++.h>
 
using namespace std;
 
void show(priority_queue<int, vector<int>, greater<int>> pq, vector<int> adj[], int xx[], int n){
    vector<int> ans;
 
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        ans.push_back(x);
        for(auto k : adj[x]){
            xx[k]--;
            if(!xx[k]) pq.push(k);
        }
    }
    
    if(ans.size() != n) printf("Sandro fails.\n");
    else{
        for(int i = 0; i < n; ++i){
            if(n-i == 1) printf("%d\n", ans[i]);
            else printf("%d ", ans[i]);
        }
    }
}
 
int main(){
    int n, m;
 
    scanf("%d%d", &n, &m);
 
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> adj[n+1];
    int xx[n+1];
 
    memset(xx, 0, sizeof(xx));
 
    for(int i = 0; i < m; ++i){
        int x, y; scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        xx[y] += 1;
    }
 
    for(int i = 1; i <= n; ++i){
        if(!xx[i]) pq.push(i);
    }
 
    show(pq, adj, xx, n);
    
    return 0;
} 