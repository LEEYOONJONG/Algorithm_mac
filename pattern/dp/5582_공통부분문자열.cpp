#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[4001][4001];
int main(){
    string a, b;
    cin>>a>>b;
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            if (a[i] == b[j]){
                dp[i][j] = 1;
            }
        }
    }
    int res=0;
    for (int row=1; row<a.size(); row++){
        for (int col=1; col<b.size(); col++){
            if (dp[row-1][col-1] > 0 && dp[row][col]==1) {
                dp[row][col] = dp[row-1][col-1]+1;
                res = max(res, dp[row][col]);
            }
        }
    }
    cout<<res;
}
