#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool visited[1001] = {false};
void Inp(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u){
    visited[u] = true;
    cout << u << endl;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }                          
}
int main(){
    Inp();
    dfs(1);
}