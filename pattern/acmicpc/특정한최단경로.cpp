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

int n, e;
int v1, v2;
vector<pair<int, int>> adj[801]; // pair<목적지, 비용>

vector<int> dijkstra(int src){
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0; //src에서 src까지 거리는 0
    priority_queue<pair<int, int>> pq; // pair<there까지 총 거리, there>
    pq.push(make_pair(dist[src], src));
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost) continue; // 현재 here까지의 거리 < cost ?
        for (int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] <= nextDist) continue;
            
            dist[there] = nextDist;
            pq.push(make_pair(-dist[there], there));
        }
    }
    return dist;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>e;
    
    int a, b, c;
    for (int i=0; i<e; i++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    cin>>v1>>v2;
    
    int startToV1 = dijkstra(1)[v1];
    int startToV2 = dijkstra(1)[v2];
    int v1ToV2 = dijkstra(v1)[v2];
    int v1ToEnd = dijkstra(v1)[n];
    int v2ToEnd = dijkstra(v2)[n];
    
    int case1, case2;
    //case1 : 1->2 + 2->3 + 3->4
    if (startToV1 != INT_MAX && v1ToV2 != INT_MAX && v2ToEnd != INT_MAX){
        case1 = startToV1 + v1ToV2 + v2ToEnd;
    } else { case1 = INT_MAX; }
    //case2 : 1->3 + 3->2 + 2->4
    if (startToV2 != INT_MAX && v1ToV2 != INT_MAX && v1ToEnd != INT_MAX){
        case2 = startToV2 + v1ToV2 + v1ToEnd;
    } else { case2 = INT_MAX; }
    
    if (case1==INT_MAX && case2==INT_MAX) cout<<-1;
    else cout<<min(case1, case2);
    
}
