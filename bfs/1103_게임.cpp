#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>
#include <cstring>

int n, m;
char board[51][51];
bool visited[51][51];
bool isCycle=false;
int maxCount;
int dp[51][51];

int dfs(int row, int col){
//    cout<<row<<", "<<col<<" : "<<cnt<<endl;
    if (isCycle) return 0;
    if (row < 0 || row >= n || col < 0 || col >= m) return 0;
    if (dp[row][col] != 0) return dp[row][col];
    
    if (visited[row][col]){
        isCycle = true;
        return 0;
    }
    if (board[row][col] == 'H') return 0;
    int boardNum = board[row][col] - '0';
    visited[row][col] = true;
    
    int up = dfs(row-boardNum, col)+1;
    int down = dfs(row+boardNum, col)+1;
    int left = dfs(row, col-boardNum)+1;
    int right = dfs(row, col+boardNum)+1;
    
    visited[row][col] = false;
    return dp[row][col] = max(max(up, down), max(left, right));
}
int main(){
    cin>>n>>m;
    memset(visited, false, sizeof(visited));
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            cin>>board[row][col];
        }
    }
//    bfs();
    int cnt = dfs(0, 0);
    if (isCycle) cout<<-1;
    else cout<<cnt;
}
