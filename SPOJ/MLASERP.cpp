#include <bits/stdc++.h>
 
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
const int sz = 105;
 
char pst[sz][sz];
int dist[sz][sz];
int dirx[] = { 0, 1, 0, -1 };
int diry[] = { 1, 0, -1, 0 };
 
bool okok(int x, int y, int rows, int cols){
    return x >= 0 && x < rows && y >= 0 && y < cols;
}
 
void showboard(int rows, int cols){
    system("cls");
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            cout << "  " << dist[i][j] << "   ";
        }
        cout << endl;
    }
}
 
int bfs(pair<int, int> cow1, pair<int, int> cow2, int rows, int cols){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            dist[i][j] = 8585;
        }
    }
 
    pair<int, int> x = cow1;
 
    int endx = cow2.f, endy = cow2.s;
 
    dist[x.f][x.s] = -1;
 
    queue<pair<int, int>> trr;
 
    trr.push(x);
 
    while(!trr.empty()){
        //showboard(rows, cols);
        x = trr.front();
        trr.pop();
 
        for(int i = 0; i < 4; ++i){
            int gx = x.f + dirx[i];
            int gy = x.s + diry[i];
 
            while(okok(gx, gy, rows, cols) && pst[gx][gy] != '*'){
                if(dist[gx][gy] > dist[x.f][x.s] + 1){
                    dist[gx][gy] = dist[x.f][x.s] + 1;
                    trr.push({gx, gy});
                }
                if(gx == endx && gy == endy) return dist[gx][gy];
 
                gx += dirx[i];
                gy += diry[i];
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
 
    int w, h; cin >> w >> h;
 
    pair<int, int> cow1, cow2;
 
    int cnt = 0;
 
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> pst[i][j];
            if(pst[i][j] == 'C'){
                if(cnt == 1){
                    cow2 = {i, j};
                    cnt++;
                } else{
                    cow1 = {i, j};
                    cnt++;
                }
            }
        }
    }
 
    cout << bfs(cow1, cow2, h, w) << endl;
 
    return 0;
