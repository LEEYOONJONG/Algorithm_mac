#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k, s, p, q;
int state[100001]={0,};
vector<int> route[100001];
bool visited[100001];


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(visited, false, sizeof(visited));
    vector<int> dangerous;
    cin>>n>>m>>k>>s; // 도시 길 좀비수 위험범위
    cin>>p>>q; // 안전 위험숙박비
    
    // 점령당한 도시 입력
    for (int i=0; i<k; i++){
        int danger;
        cin>>danger;
        state[danger] = -2;
        dangerous.push_back(danger);
    }
    // 도로 정보
    for (int i=0; i<m; i++){
        int from, to;
        cin >>from >> to;
        route[from].push_back(to);
        route[to].push_back(from);
    }
    
    //bfs
    queue<int> que;
    bool tempVisit[100001]={false,};
    
    for (int i=0; i<dangerous.size(); i++){
        que.push(dangerous[i]);
        tempVisit[dangerous[i]] = true;
    }
    
    for (int i=0; i<s; i++){
        // 현재 queue에 있는걸 다 꺼내서 그 이웃 집어넣고 state에 반영
        int queSize = que.size();
        for (int j=0; j<queSize; j++){
            int top = que.front();
            
            que.pop();
            // top 이웃의 상태를 '위험'으로
            for (int neigh=0; neigh<route[top].size(); neigh++){
                int now = route[top][neigh];
                if (tempVisit[now]) continue; // 방문했으면 다시 넣을필요 없다.
                state[now] = -1;
                tempVisit[now] = true; // 방문처리
                que.push(now);
            }
        }
    }
    
    //dijkstra
    vector<long long> dist(n+1, 10000000000); // 현재
    dist[1] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, 1)); // 비용, 노드
    while(!pq.empty()){
        long long cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost) continue;
        for (int i=0; i<route[here].size(); i++){
            int there = route[here][i];
            if (state[there]==-2) continue;
            long long nextDist;
            
            if (state[there] == -1) nextDist = cost+q;
            else nextDist = cost+p;
            
            
            if (dist[there] > nextDist){ // 이걸로 인해 방문여부 체크필요없음
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    if (state[n]==-1) cout<<dist[n]-q;
    else cout<<dist[n]-p;
}
