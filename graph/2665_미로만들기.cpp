#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int room[51][51];
vector<int> dijkstra(int src){
    vector<int> dist(n, 987654321);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost) continue;
//        for (
    }
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>room[i][j];
        }
    }
    // bfs로 그룹만들기.
    queue<pair<int, pair<int, int>>> que;
    que.push(make_pair(1, make_pair(0, 0)));
}
