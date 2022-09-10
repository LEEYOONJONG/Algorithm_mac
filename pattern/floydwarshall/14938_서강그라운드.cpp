#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m, r, t;
int item[101];
int dist[101][101];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>r;
    for (int i=1; i<=n; i++){
        cin>>item[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dist[i][j] = INF;
        }
    }


    int a, b, l;
    for (int i=0; i<r; i++){
        cin>>a>>b>>l;
        dist[a][b] = l;
        dist[b][a] = l;
    }
    for (int pass = 1; pass <= n; pass++){
        for (int from = 1; from <=n; from++){
            for (int to = 1; to <= n; to++){
                if (dist[from][to] > dist[from][pass] + dist[pass][to]){
                    dist[from][to] = dist[from][pass] + dist[pass][to];
                }
            }
        }
    }

    int itemMax=-1;
    for (int start=1; start<=n; start++){
        int itemSum = item[start];
        for (int end=1; end<=n; end++){
            if (start == end ) continue;
            if (dist[start][end] <= m) itemSum += item[end];
        }
        itemMax = max(itemMax, itemSum);
    }
    cout<<itemMax;
}