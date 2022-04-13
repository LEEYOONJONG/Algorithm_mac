#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;
int v, e;
int cost[401][401];
int a, b, c;

void initCost(){
    for (int i=1; i<=v; i++){
        for (int j=1; j<=v; j++){
            cost[i][j] = INF;
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>v>>e;
    initCost();
    for (int i=0; i<e; i++){
        cin>>a>>b>>c;
        cost[a][b] = c;
    }
    
    for (int pass=1; pass<=v; pass++){
        for (int from=1; from<=v; from++){
            for (int to=1; to<=v; to++){
                cost[from][to] = min(cost[from][pass] + cost[pass][to], cost[from][to]);
            }
        }
    }
    int minV = INF;
    for (int from=1; from<=v; from++){
        if (minV > cost[from][from]) minV = cost[from][from];
    }
    if (minV != INF) cout << minV;
    else cout<<-1;
}
