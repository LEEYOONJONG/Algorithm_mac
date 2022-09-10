#include <iostream>
using namespace std;

long long dp[1001][10];

int main(){
    int n; cin>>n;
    for (int i=0; i<=9; i++){
        dp[1][i] = 1;
    }
    for (int row=2; row<=n; row++){
        for (int col=0; col<=9; col++){
            if (col==0) dp[row][col] = 1;
            else{
                dp[row][col] = (dp[row-1][col] + dp[row][col-1])%10007;
            }
        }
    }
    long long res=0;
    for (int col=0; col<=9; col++){
        res = (res+dp[n][col])%10007;
    }
    cout<<res%10007;
}
