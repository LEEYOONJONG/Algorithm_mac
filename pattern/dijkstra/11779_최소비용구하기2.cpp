#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 100000001
using namespace std;
struct Data{
    int node;
    long long price;
    Data(int node, long long price):node(node), price(price){};
    bool operator<(const Data d) const {
        return price > d.price;
    }
};

vector<Data> adj[1001];
int route[1001];
int n, m;
int x, y;
long long dist[1001];

void printRoute(){
    int cnt=0;
    queue<int> que;
    vector<int> vc;
    que.push(y);
    cnt++;
    while(!que.empty()){
        int top = que.front();
        vc.push_back(top); // 경로
        if (top == x){
            break;
        }
        que.push(route[top]);
        cnt++;
        que.pop();
    }
    reverse(vc.begin(), vc.end());
    cout<<cnt<<'\n';
    for (int i=0; i<vc.size(); i++){
        cout<<vc[i]<<' ';
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int a, b, price;
    for (int i=0; i<m; i++){
        cin>>a>>b>>price;
        adj[a].push_back(Data(b, price));
    }
    cin>>x>>y;
    
    for (int i=1; i<=n; i++) dist[i] = INF;
    dist[x] = 0;
    priority_queue<Data> pq;
    pq.push(Data(x, 0));
    
    while(!pq.empty()){
        Data top = pq.top();
        pq.pop();
        if (top.node == y){
            cout<<top.price<<'\n';
            break;
        }
        for (int i=0; i<adj[top.node].size(); i++){
            Data next = adj[top.node][i];
            if (dist[next.node] > dist[top.node] + next.price){
                dist[next.node] = dist[top.node] + next.price;
                route[next.node] = top.node;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }
    printRoute();
}
