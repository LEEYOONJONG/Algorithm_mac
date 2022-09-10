#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Data{
    int a, b, c;
    Data(int a, int b, int c):a(a), b(b), c(c){};
};

int n, m;

int main(){
    cin>>n>>m;
    vector<Data> list;
    long long dist[501];
    
    for (int i=1; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    
    for (int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        list.push_back(Data(a, b, c));
    }
    
    for (int i=1; i<n; i++){ // 499
        for (int j=0; j<list.size(); j++){ // 6000
            int from = list[j].a;
            int to = list[j].b;
            int cost = list[j].c; // -10000
            
            if (dist[from] == INF) continue;
            
            if (dist[to] > dist[from]+cost){
                dist[to] = dist[from]+cost;
            }
        }
    }
    bool isCycle = false;
    
    for (int j=0; j<list.size(); j++){
        int from = list[j].a;
        int to = list[j].b;
        int cost = list[j].c;
        
        if (dist[from] == INF) continue;
        
        if (dist[to] > dist[from]+cost){
            isCycle = true;
            break;
        }
    }
    
    if (isCycle) cout<<-1;
    else{
        for (int i=2; i<=n; i++){
            if (dist[i] != INF) cout<<dist[i]<<'\n';
            else cout<<-1<<'\n';
        }
    }
}

