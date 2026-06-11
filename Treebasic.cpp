#include<bits/stdc++.h>
using namespace std;
int n, r;
int c[101][101];
vector<int> adj[1001];
bool visited[1001];
struct Edge{
    int x,y;
};
vector<Edge> Tree;
void inp(){
    cin >> n >> r;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] == 1 && i != j){
                adj[i].push_back(j);
            }
        }
    }
}

void TreeDFS(int u){

    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            Tree.push_back({u,v});
            TreeDFS(v);
        }
    }
}

void TreeBFS(int u){
    queue<int> Q;
    visited[u] = true;
    Q.push(u);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int x : adj[v]){
            if(!visited[x]){
                Tree.push_back({v,x});
                Q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t;
    cin >> t;
    inp();
    if(t == 1){
        TreeDFS(r);
        if(Tree.size() != n -1){
            cout << 0 ;
            return 0;
        }
        cout << Tree.size() << endl;
        for(Edge e : Tree){
            cout << e.x << " " << e.y << endl;
        }
    }else if(t == 2){
        TreeBFS(r);
         if(Tree.size() != n -1){
            cout << 0 ;
            return 0;
        }
        cout << Tree.size() << endl;
        for(Edge e : Tree){
            cout << e.x << " " << e.y << endl;
        }

    }
}