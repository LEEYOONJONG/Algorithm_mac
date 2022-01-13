#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

struct Data {
    int node;
    int weight;
    Data(){};
    Data(int node, int weight) : node(node), weight(weight){};
    bool operator<(const Data d) const {
        return weight>d.weight;
    }
};
vector<Data> adj[1001];
int dist[1001];
bool visited[1001];
priority_queue<Data> pq;
priority_queue<Data> dest[1001];

int n, m, k;
int a, b, c;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    
    for (int i=1; i<=n; i++){
        adj[i].clear();
        dist[i]=INF;
        visited[i]=false;
    }
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        adj[a].push_back(Data(b, c));
    }
    dist[1] = 0;
    pq.push(Data(1, 0));
    while(!pq.empty()){
        Data nowNode = pq.top();
        pq.pop();
        if (visited[nowNode.node]) continue;
        visited[nowNode.node] = true;
        for (int i=0; i<adj[nowNode.node].size(); i++){
            Data nextNode = adj[nowNode.node][i];
            if (dist[nextNode.node]> dist[nowNode.node] + nextNode.weight){
                dist[nextNode.node] = dist[nowNode.node] + nextNode.weight;
                pq.push(Data(nextNode.node, dist[nextNode.node]));
            }
        }
    }
    
    // result
}
