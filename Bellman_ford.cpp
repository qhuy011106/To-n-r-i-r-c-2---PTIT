#include<bits/stdc++.h>
using namespace std;
int a[101][101];
const int INF = 10000;
int n, s , t;
struct edge{
    int x,y ,w;
};
int pre[101];
vector<edge> adj;
void inp(){
    cin >> n >> s >> t;
    for(int i =1 ; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i != j && a[i][j] != INF ) adj.push_back({i, j, a[i][j]});
        }
}
void bellman_ford(){
    vector<int> d(n +1, 1e9);
    d[s] = 0;
    pre[s] = s;
    for(int i = 1; i <= n - 1; i++){
        bool check = false;
        for( edge e : adj){
            int u = e.x;
            int v =  e.y;
            int w = e.w;
            if(d[u] != 1e9){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pre[v] = u;
                    check = true;
                }
            } 
        }
        if(!check) break;
    }
    // kiem tra chu trinh am
    for(edge e : adj){
        int u = e.x, v = e.y, w = e.w;
        if(d[u] != 1e9 && d[v] > d[u] + w){
            cout << -1 << endl;
            return;
        }
    }
    if(d[t] == 1e9){
        cout << 0 << endl;
        return;
    }
    vector<int> path;
    cout << d[t] << endl;
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
    cout << endl;
    
}
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    inp();
    bellman_ford();

}