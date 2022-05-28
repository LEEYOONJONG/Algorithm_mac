#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data {
    int node1, node2, weight;
    Data(int node1, int node2, int weight):node1(node1), node2(node2), weight(weight){};
    bool operator<(const Data d) const{ // 
        return weight > d.weight; // weight의 오름차순
    }
};
int n, m;
bool isMale[1001];
int parent[1001];

int find(int x){
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void uni(int x, int y){
    parent[find(x)] = find(y); // x의 조상의 부모는 y의 조상.
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    char gender;
    for (int i=1; i<=n; i++){
        cin >> gender;
        parent[i] = i;
        if (gender == 'M') isMale[i] = true;
        else isMale[i] = false;
    }
    int u, v, d;

    priority_queue<Data> pq;
    for (int i=0; i<m; i++){
        cin >> u >> v >> d;
        if (isMale[u] == isMale[v]) continue;
        pq.push(Data(u, v, d));
    }
    int edgeCount=0;
    int res=0;
    while(1){
        if (edgeCount == n-1) break;
        if (pq.empty()){
            cout<< -1;
            return 0;
        }
        Data top = pq.top();
        pq.pop();
        if (find(top.node1) != find(top.node2) && isMale[top.node1] != isMale[top.node2]){
            uni(top.node1, top.node2);
            edgeCount++;
            res += top.weight;
        }
    }
    cout<<res;
}