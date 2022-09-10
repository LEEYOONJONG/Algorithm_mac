#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;
int n, m;
int cost[101][101];
int a, b, c;

void initCost(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i!=j) cost[i][j] = INF;
            else cost[i][j] = 0;
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    initCost();
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        cost[a][b] = min(cost[a][b], c);
    }
    for (int pass=1; pass<=n; pass++){
        for (int from=1; from<=n; from++){
            for (int to=1; to<=n; to++){
                cost[from][to] = min(cost[from][pass] + cost[pass][to], cost[from][to]);
            }
        }
    }
    for (int from=1; from<=n; from++){
        for (int to=1; to<=n; to++){
            if (cost[from][to] != INF)cout<<cost[from][to]<<' ';
            else cout<<0<<' ';
        }
        cout<<'\n';
    }
}
