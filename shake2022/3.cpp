#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[200001];
int color[200001];
bool visited[200001];
int res;

void bfs(int parent, int parentColor){
    if (visited[parent]) return;
    visited[parent] = true;
    for (int i=0; i<adj[parent].size(); i++){
        int child = adj[parent][i];
        if (visited[child]) continue;
        if (color[child] == parentColor){
            bfs(child, color[child]);
        }
        else{ // 다르다면
            res++;
            bfs(child, color[child]);
        }
    }
    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for (int i=1; i<=n; i++){
        cin>>color[i];
    }
    int a, b;
    for (int i=0; i<n-1; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (color[1] != 0) res++;
    bfs(1, color[1]);
    cout<<res;
}
