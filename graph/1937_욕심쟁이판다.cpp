#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[501][501];
int dp[501][501];
int n;

int calc(int before, int row, int col){
    if (row<0 || row>=n || col<0 || col>=n) return -1;
    
    if (before < arr[row][col]){
        // dp[row][col] 이 존재한다면 이를 이용.
        if (dp[row][col] != -1) return dp[row][col];

        int up = 1 + calc(arr[row][col], row-1, col);
        int down = 1 + calc(arr[row][col], row+1, col);
        int left = 1 + calc(arr[row][col], row, col-1);
        int right = 1 + calc(arr[row][col], row, col+1);
        return dp[row][col] = max(max(up, down), max(left, right));
    }
    else {
        return -1;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    int maximum =-1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int calcRes = calc(-1, i, j);
            if (maximum < calcRes){
//                cout<<i<<", "<<j<<" : "<<calcRes<<endl;
                maximum = calcRes;
            }
        }
    }
    cout<<maximum+1;
}
