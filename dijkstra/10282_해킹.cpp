#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Data {
    int node;
    int time;
    Data(int node, int time):node(node), time(time){};
    bool operator<(const Data d) const {
        return time > d.time;
    }
};
void input(){
    int n, d, c;
    bool visited[10001];
    int maxTime = -1;
    memset(visited, false, sizeof(visited));
    vector<pair<int, int>> adj[10001];
    cin>>n>>d>>c;
    for (int i=0; i<d; i++){
        int a, b, s; cin>>a>>b>>s;
        adj[b].push_back(make_pair(a, s));
    }
    priority_queue<Data> pque;
    pque.push(Data(c, 0));
    while(!pque.empty()){
        Data top = pque.top();
        pque.pop();
        int node = top.node;
        int time = top.time;
        if (visited[node]) continue;
        visited[node] = true;
        maxTime = max(maxTime, time);
        for (int i=0; i<adj[node].size(); i++){
            int nextnode = adj[node][i].first;
            int additional = adj[node][i].second;
            pque.push(Data(nextnode, time+additional));
        }
    }
    int cnt=0;
    for (int i=1; i<=n; i++){
        if (visited[i]) cnt++;
    }
    cout<<cnt<<" "<<maxTime<<'\n';
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    for (int i=0; i<t; i++){
        input();
    }
}
