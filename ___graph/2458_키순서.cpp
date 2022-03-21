#include <iostream>
#define INF 987654321
using namespace std;
int main(){
    int n, m; cin>>n>>m;
    int a, b;
    int dp[501][501];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = INF;
        }
    }
    for (int i=0; i<m; i++){
        cin>>a>>b;
        dp[a][b] = 1;
    }
    for (int pass=1; pass<=n; pass++){
        for (int start=1; start<=n; start++){
            for (int end=1; end<=n; end++){
                if (dp[start][pass] == INF || dp[pass][end] == INF || start==end) continue;
                if (dp[start][end] > dp[start][pass] + dp[pass][end]){
                    dp[start][end] = dp[start][pass] + dp[pass][end];
                }
            }
        }
    }
    int cnt=0;
    bool exist=false;
    
//    for (int start=1; start<=n; start++){
//        for (int end=1; end<=n; end++){
//            if (dp[start][end]==INF) cout<<'X'<<' ';
//            else cout<<dp[start][end]<<' ';
//        }
//        cout<<endl;
//    }
    
    
    for (int end=1; end<=n; end++){
        exist = true;
        for (int start=1; start<=n; start++){
            if (start==end) continue;
            if (dp[start][end] == INF && dp[end][start] == INF){
                exist = false;
                break;
            }
        }
        if (exist==true){
            cnt++;
//            cout<<end<<endl;
        }
    }
    cout<<cnt;
}
