#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int n, m, k, x;
vector<int> adj[300001];
vector<int> res;
int visited[300001];

struct Data{
    int node;
    int cnt;
    Data(int node, int cnt):node(node), cnt(cnt){};
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    memset(visited, -1, sizeof(visited));
    cin>>n>>m>>k>>x;
    int a, b;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<Data> que;
    que.push(Data(x, 0));
    visited[x] = 0;
    
    while(!que.empty()){
        int node = que.front().node;
        int cnt = que.front().cnt;
        que.pop();
        
        
        
        if (cnt == k){
            res.push_back(node);
        }
        for (int i=0; i<adj[node].size(); i++){
            int nowNode = adj[node][i];
            if (visited[nowNode] == -1){
                que.push(Data(nowNode, cnt+1));
                visited[nowNode] = cnt+1;
            }
        }
    }
    
    sort(res.begin(), res.end());
    if (res.size() == 0) cout<<-1;
    else {
        for (int i=0; i<res.size(); i++){
            cout<<res[i]<<'\n';
        }
    }
}
