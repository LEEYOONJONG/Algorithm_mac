#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[1001];

int n, m, k;
struct Data {
    int node;
    int weight;
    Data();
    Data(int node, int weight) : node(node), weight(weight) {};
    bool operator<(const Data d) {
        return weight > d.weight; // 오름차순
    }
};
void dijkstra(){
    priority_queue<int> dist[1001];
    priority_queue<Data> pq;
    pq.push(Data(1, 0));
    while(!pq.empty()){
        Data top = pq.top();
        int topNode =top.node;
        int topW = top.weight;
        for (int i=0; i<adj[topNode].size(); i++){
            int newNode = adj[topNode][i].first;
            int newDist = topW + adj[topNode][i].second;
            // dist[i] 우선순위큐의 사이즈가 k에 도달하지 않았으면 무조건 추가.
            // dist[i] 우선순위큐의 top이 새 dist보다 크다면 pop 후 새 dist 추가.
            // 다시생각
        }
    }
}

int main(){
    cin>>n>>m>>k; // 도시, 도로, k
    for (int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c; // 출발 도착 시간
        adj[a].push_back(make_pair(b, c));
    }
    dijkstra();
}
