#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <float.h>
using namespace std;

int n, m; //node, edge
//vector<pair<int, double>> adj[10001];

void dijkstra(int src, vector<pair<int, double>> adj[]){
    vector<double> dist(n, DBL_MAX);
    dist[src]=1;
    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(-dist[src], src));
    while(!pq.empty()){
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost) continue;
        for (int i=0; i<adj[here].size(); i++){
            double nextDist = (cost)*(adj[here][i].second);
            int there = adj[here][i].first;
            if (dist[there] > nextDist){
                dist[there] = nextDist;
//                cout<<"updating : dist["<<there<<"]  - "<<nextDist<<endl;
                pq.push(make_pair(-dist[there], there));
            }
        }
    }
    cout<<fixed;
    cout.precision(10);
    cout<<dist[n-1]<<endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin>>c;
    for (int i=0; i<c; i++){
        
        cin>>n>>m;
        int a, b;
        double c;
        vector<pair<int, double>> adj[10001];
        for (int j=0; j<m; j++){
            cin>>a>>b>>c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        dijkstra(0, adj);
    }
}
