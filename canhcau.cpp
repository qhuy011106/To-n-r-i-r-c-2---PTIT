#include<bits/stdc++.h>
using namespace std;
int n;
bool visited[1001];
vector<int> adj[1001];
int c[101][101];
vector<pair<int, int>> dscanh;

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] == 1 && i != j){
                adj[i].push_back(j);
                if(i < j) dscanh.push_back({i, j});
            }
        }
}

void dfs(int u){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]) dfs(v);
        }
}

void dfss(int u, int s, int t){//loai bo canh s-t
    visited[u] = true;
    for(int v : adj[u]){
        if((u == s && v == t) || (u == t && s == v)) continue;
        if(!visited[v]) dfss(v,s,t);
    }
}

void canhcau(){
    memset(visited, false, sizeof(visited));
    int tplt = 0;
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            tplt++;
        }
    }

    for(auto it : dscanh){
        memset(visited, false,sizeof(visited));
        int x = it.first, y = it.second;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfss(i,x,y);
                cnt++;
            }
        }
        if(cnt > tplt) ans.push_back({x,y});

    }
    if(ans.size() == 0) cout << 0 << endl;
    else{
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it.first << " " << it.second << endl;
        }
    }
}
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    inp();
    canhcau();
}
