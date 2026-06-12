#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[101][101];
vector<pair<int, int>> adj[1001];
bool used[1001];

struct Edge{
    int x, y, w;
};

void inp(){
   cin >> n >> m;
   for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
        cin >> c[i][j];
        if(c[i][j] != 0 ){
            adj[i].push_back({j,c[i][j]});
        }
    }
   }
    memset(used, false, sizeof(used));

}
void prim( int u){
    int d = 0;
    used[u] = true;// dua dinh u vao V(MST)
    
    vector<Edge> MST;
    while(MST.size() < n -1){
        int x,y;
        int min_w = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(used[i]){
                for(auto it : adj[i]){
                    int j = it.first; int w = it.second;
                    if(!used[j] && w < min_w){
                        min_w = w;
                        x = j, y = i;
                    }
                }
            }
        }
        MST.push_back({x,y,min_w});
        d += min_w;
        used[x] = true;
    }
    if(MST.size() == 0) cout << 0;
    else{
        
        cout << d << endl;
        for(Edge e : MST){
            cout << min(e.x, e.y) << " " << max(e.x, e.y) << " " << e.w << endl;
        }
    }

}
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    inp();
    prim(m);
}