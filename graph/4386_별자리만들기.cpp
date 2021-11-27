#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int, double>> adj[100]; // (연결된 정점번호, 가중치)
int V; // 정점 개수


struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n): parent(n), rank(n, 1) {
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    // u가 속한 트리의 루트의 번호를 반환
    int find(int u){
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u); v = find(v);
        // u, v가 이미 같은 집합에 속하는 경우를 걸러냄
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v); // 이를 통해 rank[v]가 rank[u] 이상이 되도록
        // rank[u]가 항상 작다. 따라서 u의 parent를 v로.
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
};

// 주의 : 노드가 0부터 V-1까지를 가정했음 !!!
// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected에 저장하고, 가중치의 합을 반환한다.
double kruskal(vector<pair<int, int>> &selected){
    double ret = 0;
    selected.clear();
    // (가중치, (정점1, 정점2))의 목록을 얻는다.
    vector<pair<double, pair<int, int>>> edges;
    for (int u=0; u<V; u++){
        for (int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            double cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    // 가중치 순 정렬
    sort(edges.begin(), edges.end());
    // 처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(V);
    for (int i=0; i<edges.size(); i++){
        // 간선 u, v를 검사한다.
        double cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // 이미 u, v가 연결되어 있다면 무시한다.
        if (sets.find(u) == sets.find(v)) continue;
        // 이 둘을 합친다.
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}
int main(){
    
    cin>>V;
    pair<double, double> coord[100];
    for (int i=0; i<V; i++){ // 0~99번째
        cin>>coord[i].first>>coord[i].second;
    }
    for (int u=0; u<V-1; u++){
        for (int v=u+1; v<V; v++){
            double dist = sqrt(pow((coord[u].first - coord[v].first), 2) + pow((coord[u].second - coord[v].second), 2));
            adj[u].push_back(make_pair(v, dist));
            adj[v].push_back(make_pair(u, dist));
        }
    }
    vector<pair<int, int>> res;
    double ret = kruskal(res);
    cout<<fixed;
    cout.precision(2);
    cout<<ret;
}
