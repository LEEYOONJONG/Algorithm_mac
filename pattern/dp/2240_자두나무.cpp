#include <iostream>
using namespace std;

int t, W;
int arr[1001];
int dp[1001][31][3];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>t>>W;
    for (int i=0; i<t; i++) cin>>arr[i];
    
    if (arr[0]==1)  dp[0][0][1] = 1;
    if (arr[0]==2)  dp[0][1][2] = 1;
    
    for (int i=1; i<t; i++){
        for (int w=0; w<=W; w++){
            if (arr[i]==1){
                if (w==0){
                    dp[i][0][1] = dp[i-1][0][1] + 1;
                    continue;
                }
                dp[i][w][1] = max(dp[i-1][w][1], dp[i-1][w-1][2]) + 1;
                dp[i][w][2] = max(dp[i-1][w-1][1], dp[i-1][w][2]);
            }
            else {
                if (w==0){
                    dp[i][0][2] = dp[i-1][0][2] + 1;
                    continue;
                }
                dp[i][w][1] = max(dp[i-1][w][1], dp[i-1][w-1][2]);
                dp[i][w][2] = max(dp[i-1][w-1][1], dp[i-1][w][2])+1;
            }
        }
    }
    int ans=-1;
    for (int i=0; i<=W; i++)
        ans = max(ans, max(dp[t-1][i][1], dp[t-1][i][2]));
    cout<<ans;
}
