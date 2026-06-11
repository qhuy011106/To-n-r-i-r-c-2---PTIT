#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool visited[1001];
int n, m;
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x,y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void bfs(int u){
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        cout << v << " ";
        for(int x : adj[v]){
            if(!visited[x]){
                visited[x] = true;
                Q.push(x);
               
            }
        }
    }
}
int main(){
    inp();
    bfs(1);
}