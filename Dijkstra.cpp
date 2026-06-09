#include<bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<pair<int,int>> adj[1001];
int pre[1001];
 
void inp(){
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
    }
}
void Dijkstra(int s, int t){
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q; // kc, dinh
    Q.push({0, s});
    while(!Q.empty()){
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }
    cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
}
int main(){
    inp();
    Dijkstra(1, 6);
}