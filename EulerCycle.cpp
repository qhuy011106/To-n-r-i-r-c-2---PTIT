#include<bits/stdc++.h>
using namespace std;
int n, m;
set<int> adj[1001];
int deg[1001];
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
}
void EulerCycle(int s){
    stack<int> st;
    vector<int> EC;
    st.push(s);
    while(!st.empty()){
        int v = st.top();
        if(adj[v].size() != 0){
            int u = *adj[v].begin();
            st.push(u);
            // xoa (u,v);
            adj[u].erase(v);
            adj[v].erase(u);
        }else{
            st.pop();
            EC.push_back(v);
        }
    }
    for(int x : EC) cout << x << " ";
    cout << endl;
}
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    inp();
    EulerCycle(1);
}