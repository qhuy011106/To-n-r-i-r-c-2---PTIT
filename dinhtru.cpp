#include<bits/stdc++.h>
using namespace std;
int a[101][101];
vector<int> adj[10001];
bool visited[1001];
int n;
void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1 && i != j) adj[i].push_back(j);
        }
}
void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void dinhtru(){
    memset(visited, false, sizeof(visited));
    int tplt = 0;
    vector<int> ans;
   // dem so thanh phan lien thong ban dau
    for(int i = 1; i <= n; i++ ){
        if(!visited[i]){
            dfs(i);
            tplt++;
        }
    }
    for(int i = 1; i <= n; i++ ){
    memset(visited,false, sizeof(visited));
    int cnt = 0;
    visited[i] = true;
    for(int j = 1; j <= n; j++){
        if(!visited[j]){
            dfs(j);
            cnt++;
        }
    }
        if(cnt > tplt) ans.push_back(i);


        
    }
    if(ans.size() == 0) cout << 0;
    else{
        cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    }
}
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    inp();
    dinhtru();
}