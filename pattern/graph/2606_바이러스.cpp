#include <iostream>
#include <vector>
using namespace std;

bool visited[101];
vector<int> adj[101];

int dfs(int start){
    if (visited[start]) return 0;
    visited[start] = true;
    int sum=0;
    for (int i=0; i<adj[start].size(); i++){
        int end = adj[start][i];
        sum += dfs(end);
    }
    return 1 + sum;
}


int main(){
    int n; cin>>n;
    int ssang; cin>>ssang;
    int a, b;
    for (int i=0; i<ssang; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<< dfs(1)-1; // 노드 1은 제외
}