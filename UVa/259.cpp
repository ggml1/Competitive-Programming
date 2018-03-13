#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int pcConstant = 31;
const int source = 42, sink = 43;
const int MAXAPPS = 30;
const int MAXSIZE = 50;
const int inf = 123456789;

vector<int> adj[MAXSIZE];
map<int, map<int, int>> cap;

void add(int from, int to, int garg){
	adj[from].push_back(to);
	adj[to].push_back(from);

	cap[to][from] = 0;
	cap[from][to] = garg;
}

int parse(string data){
	int app = data[0] - 'A';
	int count = data[1] - '0';

	add(source, app, count);

	for(int i = 3; data[i] != ';'; ++i){
		if(isspace(data[i])) continue;
		add(app, pcConstant + (data[i] - '0'), inf);
	}

	return count;
}

int augment(){
	queue<int> q;

	pii vis[50];

	int seen[50];

	memset(seen, 0, sizeof(seen));

	vis[source] = {-1, -1};

	seen[source] = 1;

	q.push(source);

	while(!q.empty()){
		int from = q.front();
		q.pop();

		for(int to : adj[from]){

			if(cap[from][to] > 0 && !seen[to]){
				seen[to] = 1;
				vis[to] = {from, cap[from][to]};
				q.push(to);
			}
		}
	}

	if(!seen[sink]) return 0;

	int v = sink, flow = inf;

	while(vis[v].first != -1){
		flow = min(flow, vis[v].second);

		v = vis[v].first;
	}

	v = sink;

	while(vis[v].first != -1){
		int from = vis[v].first;
		int to = v;

		cap[from][to] -= flow;
		cap[to][from] += flow;

		v = from;
	}

	return flow;
}

int getMaxFlow(){
	int flow = 0;
	int curFlow = 0;

	while((curFlow = augment()) != 0){
		flow += curFlow;
	}

	return flow;
}

void init(){
	for(int i = 0; i < MAXAPPS; ++i){
		adj[i].clear();
	}

	cap.clear();

	for(int i = 0; i < 10; ++i){
		add(pcConstant + i, sink, 1);
	}
}

int main(){
	ios::sync_with_stdio(0);

	string data;

	while(getline(cin, data)){

		//0-30 to APPS
		//31 - 41 to PCS
		//42 = source
		//43 = sink;

		init();

		int requests = parse(data);

		while(getline(cin, data) && data.compare("") != 0){
			requests += parse(data);
		}

		int flow = getMaxFlow();

		if(flow != requests) cout << "!" << endl;
		else{
			string computers(10, '_');

			for(int curAPP = 0; curAPP < 30; ++curAPP){
				for(int curPC : adj[curAPP]){
					if(cap.count(curAPP) && cap[curAPP].count(curPC) && cap[curAPP][curPC] != inf){
						computers[curPC - pcConstant] = curAPP + 'A';
					}
				}
			}

			cout << computers << endl;
		}
	}
}