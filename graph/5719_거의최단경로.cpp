#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define INF 987654321
using namespace std;

vector<int> parent[501];
bool deletingEdge[501][501];

void edgecheck(int end){
    for (int i=0; i<parent[end].size(); i++){
        int start = parent[end][i];
        if (deletingEdge[start][end]) continue;
        deletingEdge[start][end] = true;
        edgecheck(start);
    }
}
struct Data{
    int node;
    int weight;
    Data(){};
    Data(int node, int weight): node(node), weight(weight){};
    bool operator<(const Data d) const {
        return weight > d.weight; //오름차순
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    int s, d;
    int u, v, p;
    
    vector<Data> adj[501];
    int dist[501];
    bool visited[501];
    
    while(1){
        cin>>n>>m; // 장소 , 도로
        if (n==0 && m==0) break;
        cin>>s>>d;  // 시작점 도착점
        for (int i=0; i<500; i++){ // 초기화
            parent[i].clear();
            adj[i].clear();
            dist[i] = INF;
        }
        memset(visited, false, sizeof(visited));
        priority_queue<Data> pqueue;

        
        for (int i=0; i<m; i++){
            cin>>u>>v>>p;
            adj[u].push_back(Data(v, p));
        }
        dist[s]=0;
        pqueue.push(Data(s, 0));
        
        while(!pqueue.empty()){
            Data currNode = pqueue.top();
            pqueue.pop();
            if (visited[currNode.node]) continue;
            visited[currNode.node] = true;
            for (int i=0; i<adj[currNode.node].size(); i++){
                Data nextNode = adj[currNode.node][i];
                if (dist[nextNode.node] > dist[currNode.node] + nextNode.weight){
                    dist[nextNode.node] = dist[currNode.node] + nextNode.weight;
                    pqueue.push(Data(nextNode.node, dist[nextNode.node]));
                    parent[nextNode.node].clear();
                    parent[nextNode.node].push_back(currNode.node);
                }
                else if (dist[nextNode.node] == dist[currNode.node] + nextNode.weight){
                    parent[nextNode.node].push_back(currNode.node);
                }
            }
        }
        memset(deletingEdge, false, sizeof(deletingEdge));
        edgecheck(d);
        
        
        // 다시 다익스트라
        for (int i=0; i<500; i++){ // 초기화
            dist[i] = INF;
        }
        dist[s]=0;
        memset(visited, false, sizeof(visited));
        priority_queue<Data> pq;
        pq.push(Data(s, 0));
        while(!pq.empty()){
            Data currNode = pq.top();
            pq.pop();
            if (visited[currNode.node]) continue;
            visited[currNode.node] = true;
            for (int i=0; i<adj[currNode.node].size(); i++){
                Data nextNode = adj[currNode.node][i];
                if (deletingEdge[currNode.node][nextNode.node] == true) continue; // 추가된 부분.
                
                if (dist[nextNode.node] > dist[currNode.node] + nextNode.weight){
                    dist[nextNode.node] = dist[currNode.node] + nextNode.weight;
                    pq.push(Data(nextNode.node, dist[nextNode.node]));
                }
                else if (dist[nextNode.node] == dist[currNode.node] + nextNode.weight){
                }
            }
        }
        
        
        
        if (dist[d] == INF) cout<<-1<<'\n';
        else cout<<dist[d]<<'\n';
        
    }
}
