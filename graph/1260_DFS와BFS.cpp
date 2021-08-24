#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset
using namespace std;

vector<int> adj[1010];
bool visited[1010];
void dfs(int start){
    if (visited[start]) return;
    visited[start] = true;
    cout<<start<<' ';
    for (int i=0; i<adj[start].size(); i++){
        dfs(adj[start][i]);
    }
}
void bfs(int start){
    queue<int> que;
    que.push(start);
    while(!que.empty()){
        int top = que.front();
        que.pop();
        if (!visited[top]){
            cout<<top<< ' ';
            visited[top] = true;
        }
        else continue;
        
        for (int i=0; i<adj[top].size(); i++){
            int node = adj[top][i];
            if (!visited[node]) que.push(node);
        }
    }
}
int main(){
    int n, m, v;
    cin>>n>>m>>v;
    for (int i=0; i<m; i++){
        int start, end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    
    // DFS
    memset(visited, false, sizeof(visited));
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    cout<<'\n';
    
    // BFS
    memset(visited, false, sizeof(visited));
    bfs(v);
    
}

