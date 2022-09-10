#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321

using namespace std;

int n, m, k, u, v, c, d;
struct Data{
    int node;
    int money;
    int time;
    Data(int node, int money, int time):node(node), money(money), time(time){};
    bool operator<(const Data d) const{
        return money > d.money;
    }
};
bool visited[101];
int cost[101]; // 소요시간
int moneySum[101];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for (int a=0; a<t; a++){
        memset(visited, false, sizeof(visited));
        memset(cost, 0, sizeof(cost));
        memset(moneySum, 0, sizeof(moneySum));
        cin>>n>>m>>k;
        for (int i=1; i<=n; i++) {
            cost[i] = INF;
            moneySum[i] = INF;
        }
        
        vector<Data> adj[101];
        for (int i=0; i<k; i++){
            cin>>u>>v>>c>>d;
            adj[u].push_back(Data(v, c, d)); // 도착공항, 비용, 소요시간
        }
        priority_queue<Data> que;
        que.push(Data(1, 0, 0));
        cost[1] = 0;
        moneySum[1] = 0;
        
        while(!que.empty()){
            Data now = que.top();
            que.pop();
            if (visited[now.node]) {
                // 비싸더라도 시간 짧다면 들어가도 됨! 근데 시간마저 짧지 않다면 볼 것도 없다.
                if (now.time > cost[now.node])  continue;
            }
            
            visited[now.node] = true;
            for (int i=0; i<adj[now.node].size(); i++){
                Data next = adj[now.node][i]; // 4
                
//                if (cost[next.node] > now.time + next.time && now.money + next.money <= m){
                if (now.money+ next.money <= m){
                    cost[next.node] = min(cost[next.node], now.time + next.time);
                    
                    moneySum[next.node] = min(moneySum[next.node], now.money + next.money);
                    que.push(Data(next.node, now.money+next.money, now.time+next.time));
                }
            }
        }
//        for (int i=1; i<=n; i++){
//            cout<<i<<" : "<<cost[i]<<'\n';
//        }
        if (cost[n] == INF) cout<<"Poor KCM\n";
        else cout<<cost[n]<<'\n';
    }
}
