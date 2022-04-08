#include <iostream>
#include <cstring>
using namespace std;

int m, n;
int arr[501][501];
int dp[501][501];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int dfs(int row, int col){
    if (row<0 || row>=m || col<0 || col>=n) return 0;
    if (dp[row][col] != -1) return dp[row][col];
    if (row==m-1 && col==n-1) return 1;
    int res = 0;
    for (int i=0; i<4; i++){
        int nextRow = row+dr[i];
        int nextCol = col+dc[i];
        if (arr[row][col] > arr[nextRow][nextCol]){
            res += dfs(nextRow, nextCol);
        }
    }
    return dp[row][col] = res;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin>>m>>n;
    for (int row=0; row<m; row++){
        for (int col=0; col<n; col++){
            cin>>arr[row][col];
        }
    }
    cout<<dfs(0,0);
}
