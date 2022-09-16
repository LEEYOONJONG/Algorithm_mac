#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m; cin>>n>>m;
    int a, b;
    int indegree[32001];
    vector<int> adj[32001];
    queue<int> que;

    memset(indegree, 0, sizeof(indegree));
    for (int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b); // 1 -> 2
        indegree[b]++;
    }

    for (int from=1; from<=n; from++){
        if (indegree[from] == 0) que.push(from);
    }

    while(!que.empty()){
        int front = que.front();
        cout<<front<<' ';
        que.pop();
        for (int i=0; i<adj[front].size(); i++){
            int to = adj[front][i];
            indegree[to]--;
            if (indegree[to] == 0) que.push(to);
        }
    }
}