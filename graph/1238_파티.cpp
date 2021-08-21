#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, x;

vector<pair<int, int>> route1[1010]; // route[도착지].p_b(출발지, 비용)
vector<pair<int, int>> route2[1010]; // route[출발지].push_back(도착지, 비용)

vector<int> dijkstra1(int dest){// 도착지 dest에 도착함.
    vector<int> dist(n+1, 987654321); // ..에서 dest까지 가는 총 비용
    dist[dest] = 0; // dest에서 dest까지 비용 = 0
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, dest));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int there = pq.top().second;
        pq.pop();
        if (dist[there] < cost) continue;
        for (int i=0; i < route1[there].size(); i++){
            int here = route1[there][i].first;
            int nextDist = route1[there][i].second + cost;
            if (dist[here] > nextDist){
                dist[here] = nextDist;
                pq.push(make_pair(-nextDist, here));
            }
        }
    }
    
    return dist;
}

vector<int> dijkstra2(int src){ // 출발지 src로부터 출발함.
    vector<int> dist(n+1, 987654321); // src에서 ..까지 가는 총 비용
    dist[src] = 0; // src까지 오는데 걸리는 시간은 0.
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    
    while(!pq.empty()){
        int cost = -pq.top().first; // origin cost
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue; // dist[here]보다 크면 하는 의미 없음
        for (int i=0; i < route2[here].size(); i++){
            int there = route2[here][i].first;
            int nextDist = cost + route2[here][i].second;
            if (dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main(){
    cin>>n>>m>>x;
    for (int i=0; i<m; i++){
        int start, end, time;
        cin>>start>>end>>time;
        route1[end].push_back(make_pair(start, time));
        route2[start].push_back(make_pair(end, time));
    }
    
    vector<int> startToX(n+1);
    vector<int> xToEnd(n+1);
    startToX = dijkstra1(x);
    xToEnd = dijkstra2(x);
    int maximumTime=-1;
    int mP=0;
    for (int i=1; i<=n; i++){
        int sum = 0;
        if (startToX[i] != 987654321) sum += startToX[i];
        if (xToEnd[i] != 987654321) sum += xToEnd[i];
        if (sum > maximumTime){
            maximumTime = sum;
            mP=i;
        }
    }
    cout<<maximumTime;
}
