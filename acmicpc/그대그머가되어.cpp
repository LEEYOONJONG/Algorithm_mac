#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<pair<int, int>> adj[20001]; // 인접 리스트
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    
    int a, b, n, m;
    cin >> a >> b;
    cin>>n>>m; // n은 전체 문자의 수, m은 문자쌍
    vector<int> dist(n + 1, 987654321);
    
    priority_queue<pair<int, int>> pq;
    for (int i=0; i<m; i++){
        int input1, input2;
        cin>>input1>>input2;
        adj[input1].push_back(make_pair(input2, 1));
        adj[input2].push_back(make_pair(input1, 1));
        
    }
    pq.push(make_pair(0, a));
    if (a==b){
        cout<<0;
    }
    if (pq.empty()){
        cout<<-1;
        return 0;
    }
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
//        cout<<"cost : "<<cost<<", here : "<<here<<endl;
        
        if (dist[here] < cost) continue;
//        if (here == b && cost < dist[here]){
//            dist[here] = cost;
//        }
        
        for (int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = cost + 1;
            if (dist[there] >nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-dist[there], there));
            }
        }
    }
    if (dist[b] == 987654321) cout<<-1;
    else cout<<dist[b];
}
