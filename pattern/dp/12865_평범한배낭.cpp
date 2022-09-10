#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101][100001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    int w[101], v[101];
    
    cin>>n>>k;
    
    for (int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }
    for (int row=1; row<=n; row++){
        for (int col=0; col<=k; col++){
            if (col >= w[row]) dp[row][col] = max(dp[row-1][col], dp[row-1][col - w[row]] + v[row]);
            else dp[row][col] = dp[row-1][col];
        }
    }
    
    cout<<dp[n][k];
}
