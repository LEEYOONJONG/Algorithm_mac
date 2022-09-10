#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000002
using namespace std;

int dp[101][10001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >>m;
    int bytes[101];
    int cost[101], costSum=0;
    for (int i=1; i<=n; i++) cin>>bytes[i];
    for (int i=1; i<=n; i++) {
        cin>>cost[i];
        costSum += cost[i];
    }
    int minCost = INF;
    for (int row=1; row<=n; row++){
        for (int col=0; col<=costSum; col++){
            if (col>=cost[row]) dp[row][col] = max(dp[row-1][col], dp[row-1][col-cost[row]]+bytes[row]);
            else dp[row][col] = dp[row-1][col];
            if (dp[row][col] >= m && col < minCost){
                minCost = col;
                break;
            }
        }
    }
    cout<<minCost;
}
