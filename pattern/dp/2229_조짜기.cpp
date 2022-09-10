#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001][1001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=0; i<n; i++) cin>>arr[i];
    for (int row=0; row<n; row++) dp[row][row] = 0;
    for (int row=0; row<n-1; row++) dp[row][row+1] = abs(arr[row+1] - arr[row]);
    for (int gap=2; gap<n; gap++){
        for (int row=0; row<n-gap; row++){
            int res;

            int mini=arr[row], maxi=arr[row];
            for (int idx=row; idx<=row+gap; idx++){
                mini = min(mini, arr[idx]);
                maxi = max(maxi, arr[idx]);
            }
            res = maxi-mini;
            
            for (int idx=row; idx<row+gap; idx++){
                res = max(res, dp[row][idx] + dp[idx+1][row+gap]);
            }
            dp[row][row+gap] = res;
        }
    }
    cout<<dp[0][n-1];
}
