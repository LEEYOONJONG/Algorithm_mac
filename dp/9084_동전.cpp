#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t;
    int n, m;
    int coin[21];
    int dp[21][10001];
    cin>>t;
    for (int a=0; a<t; a++){
        cin>>n;
        coin[0] = 0;
        for (int i=1; i<=n; i++){
            cin>>coin[i];
        }
        cin>>m;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int row=1; row<=n; row++){
            int price = coin[row];
            for (int col=0; col<=m; col++){
                if (col-price < 0) dp[row][col] = dp[row-1][col];
                else dp[row][col] = dp[row-1][col] + dp[row][col-price];
            }
        }
        cout<< dp[n][m] <<'\n';
    }
}
