#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int V; // 정점 개수
vector<pair<int, int>> adj[100001]; // 인접리스트(연결된 정점번호, 가중치)

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

// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected에 저장하고, 가중치의 합을 반환한다.
int kruskal(vector<pair<int, pair<int, int>>> &selected){
    int ret = 0;
    selected.clear();
    // (가중치, (정점1, 정점2))의 목록을 얻는다.
    vector<pair<int, pair<int, int>>> edges;
    for (int u=0; u<V; u++){
        for (int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    // 가중치 순 정렬
    sort(edges.begin(), edges.end());
    // 처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(V);
    for (int i=0; i<edges.size(); i++){
        // 간선 u, v를 검사한다.
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // 이미 u, v가 연결되어 있다면 무시한다.
        if (sets.find(u) == sets.find(v)) continue;
        // 이 둘을 합친다.
        sets.merge(u, v);
        selected.push_back(make_pair(cost, make_pair(u, v)));
        ret += cost;
    }
    return ret;
}
//bool cmp(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y){
//    return x.first > y.first;
//}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>V>>m;
    int a, b, c;
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }
    
    vector<pair<int, pair<int, int>>> ret;
    int res = kruskal(ret);
    sort(ret.begin(), ret.end());
    cout<< res - ret[ret.size()-1].first;
}
