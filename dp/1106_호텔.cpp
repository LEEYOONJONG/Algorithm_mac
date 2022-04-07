#include <algorithm>
#include <iostream>
using namespace std;
int n, c;
int costs[21], customers[21];
int dp[21][100011];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>c>>n;
    for (int i=1; i<=n; i++){
        cin>>costs[i]>>customers[i];
    }
    int minRes=987654321;
    for (int row=1; row<=n; row++){
        for (int col=1; col<=100010; col++){
            if (col >= costs[row]) dp[row][col] = max(dp[row-1][col], dp[row][col-costs[row]] + customers[row]);
            else dp[row][col] = dp[row-1][col];
            if (dp[row][col] >= c){
                minRes = min(minRes, col);
                break;
            }
        }
    }
    
    cout<<minRes;
}
