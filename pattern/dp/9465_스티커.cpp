#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[2][100001];
int dp[2][100001];


int calc(){
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[0][1] = dp[1][0]+arr[0][1];
    dp[1][1] = dp[0][0]+arr[1][1];
    for (int col=2; col<n; col++){
        dp[0][col] = arr[0][col] + max(dp[1][col-1], dp[1][col-2]);
        dp[1][col] = arr[1][col] + max(dp[0][col-1], dp[0][col-2]);
    }
    return max(dp[0][n-1], dp[1][n-1]);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    for (int i=0; i<t; i++){
        memset(dp, 0, sizeof(dp));
        
        cin>>n;
        for (int row=0; row<2; row++){
            for (int col=0; col<n; col++){
                cin>>arr[row][col];
            }
        }
        
        cout<<calc()<<'\n';
    }
}
