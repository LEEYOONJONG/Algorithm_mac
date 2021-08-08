#include <iostream>
#include <vector>
using namespace std;
int n, m, x;

int dist[1001][1001];


int main(){
    cin>>n>>m>>x;
    vector<pair<int, int>> route[1001];
    
    for (int i=0; i<m; i++){
        int start, end, time;
        cin>>start>>end>>time;
        route[start].push_back(make_pair(end, time));
    }
    for (int i=1; i<=n; i++){
        if (i==x) continue;
//        int tmp = dijkstra(i); // i를 출발지로 하는 i -> x -> i
    }
}
