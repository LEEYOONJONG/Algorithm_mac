#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<int> adj[32001];
    int indegree[32001]={0,};
    
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        indegree[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (indegree[i]==0) q.push(i);
    }
    
    while(!q.empty()){
        int top = q.front(); // 1
        cout<<top<<' ';
        q.pop();
        for (int i=0; i < adj[top].size(); i++){
            int neighbor = adj[top][i]; // top에서 출발하여 이웃하는 노드
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }
    
}
