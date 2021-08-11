#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

vector<pair<int, int>> adj[1010];
int dest; // 목적지
bool visited[1010];
int maximumB = -1;

void dijkstra(int cost, int src){
    if (src == dest){
        maximumB = max(maximumB, cost);
        return;
    }
    for (int i=0; i<adj[src].size(); i++){
        int there = adj[src][i].first;
        if (visited[there] == true) continue;
        int minWeight = min(adj[src][i].second, cost);
        
        visited[src] = true;
        dijkstra(minWeight, there);
        visited[src] = false;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        // 테스트 케이스 별 초기화 작업
        maximumB = -1;
        memset(visited, false, sizeof(visited));
        for (int c=0; c<1010; c++){
            adj[c].clear();
        }
        
        int n, m, s; //노드, 엣지, 출발지
        cin>>n>>m>>s>>dest;
        for (int j=0; j<m; j++){
            int u, v, b;
            cin >>u>>v>>b;
            adj[u].push_back(make_pair(v, b));
            adj[v].push_back(make_pair(u, b));
        }
        dijkstra(987654321, s);
        cout<<maximumB<<'\n';
    }
}
