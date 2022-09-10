#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_V 50001
int V; // 정점의 개수
vector<pair<int, int>> adj[MAX_V];
vector<int> dijkstra(int src){
    vector<int> dist(V+1, 987654321); // 노드가 1부터일 때!
    dist[src] = 0; // dist[1] = 0
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 만약 지금 꺼낸 것 보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것 무시한다.
        if (dist[here] < cost) continue;
        // 인접한 정점들 모두 검사
        for (int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 더 짧은 경로를 발견하면 dist[] 갱신하고 우선순위큐에 넣는다.
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main(){
    int m;
    cin>>V>>m;
    int from, to, w;
    for (int i=0; i<m; i++){
        cin>>from>>to>>w;
        adj[from].push_back(make_pair(to, w));
        adj[to].push_back(make_pair(from, w));
    }
    vector<int> res = dijkstra(1);
    cout<<res[V]<<endl;
//    for (int elem:res){
//        cout<<elem <<" ";
//    }
}
