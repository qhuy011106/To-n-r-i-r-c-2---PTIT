#include<bits/stdc++.h>
using namespace std;
// Kosaraju dung de kiem tra tinh lien thong manh cua do thi ( strong connected component)
// buoc 1 : duyet dfs cua do thi roi luu thu tu duyet vao 1 stack
// buoc 2 : cd transpose graph
// buoc 3: lan luot pop cac dinh trong stack  va goi thuat toan dfs de liet ke cac thanh phan lien thong

int n;
int c[101][101];
vector<int> adj[1001];
vector<int> readj[1001];
vector<int> undirected[1001];
stack<int> st;
bool visited[1001];
void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; i <= n; j++){
            cin >> c[i][j];
            if(c[i][j] == 1 && i != j){
                adj[i].push_back(j);
                readj[j].push_back(i);
                undirected[i].push_back(j);
                undirected[j].push_back(i);
            }
        }
    }
}
// topo sort
void dfs1(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) dfs1(v);
    }
    st.push(u);
}

//TG

void dfs2(int u){
    visited[u] = true;
    for(int v : readj[u]){
        if(!visited[v]) dfs2(v);
    }
}

// check lien thon

void dfs3(int u){
    visited[u] = true;
    for(int v : undirected[u]){
        if(!visited[v]) dfs3(v);
    }
}

bool check(){
    memset(visited, false, sizeof(visited));
    dfs3(1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]) return false;
        
    }
    return true;
}

void SCC(){
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs1(i);
    }

    memset(visited, false, sizeof(visited));
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            dfs2(u);
            cnt++;
        }
        
    }
    if(cnt == 1) cout << 1;
    else{
        if(check()) cout << 2;
        else cout << 0;
    }

}
int main(){
    inp();
    SCC();
}