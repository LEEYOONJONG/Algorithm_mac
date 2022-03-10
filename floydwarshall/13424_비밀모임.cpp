#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int t, n, m;
int dp[101][101];

int main(){
    
    
    
    cin>>t;
    for (int l=0; l<t; l++){
        
        // initialization
        for (int i=0; i<101; i++){
            for (int j=0; j<101; j++){
                if (i==j) dp[i][j] = 0;
                else dp[i][j] = INF;
            }
        }
        
        cin>>n>>m;
        int a, b, c;
        for (int i=0; i<m; i++){
            cin>>a>>b>>c;
            dp[a][b] = c;
            dp[b][a] = c;
        }
        for (int pass=1; pass<=n; pass++){
            for (int from=1; from<=n; from++){
                for (int to=1; to<=n; to++){
                    if (from == to) continue;
                    if (dp[from][pass] == INF || dp[pass][to] == INF) continue;
                    if (dp[from][to] > dp[from][pass] + dp[pass][to]){
                        dp[from][to] = dp[from][pass] + dp[pass][to];
                        dp[to][from] = dp[from][pass] + dp[pass][to];
                    }
                }
            }
        }
        
        int k;
        int friends[101];
        cin>>k;
        for (int i=0; i<k; i++){
            cin>>friends[i];
        }
        
        int minRoute=987654321;
        int minIdx=-1;
        for (int pass=1; pass<= n; pass++){
            int sum=0;
            for (int i=0; i<k; i++){
                int buddy = friends[i];
                sum += dp[buddy][pass];
            }
            if (sum < minRoute){
                minRoute = sum;
                minIdx = pass;
            }
        }
        cout<<minIdx<<'\n';
    }
}
