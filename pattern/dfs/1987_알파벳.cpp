#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c;
bool visited[27];
char map[21][21];

int dr[4] = { 0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int maxi=1;

void dfs(int row, int col, int kan){
    
    maxi = max(maxi, kan);
    
    for (int i=0; i<4; i++){
        int nowRow = row+dr[i];
        int nowCol = col+dc[i];
        if (nowRow <0 || nowRow>=r || nowCol < 0 || nowCol >= c) continue;
        
        int ch = map[nowRow][nowCol] - 'A';
        if (visited[ch]) continue;
        
        visited[ch] = true;
        dfs(nowRow, nowCol, kan+1);
        visited[ch] = false;
        
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin>>map[i][j];
        }
    }
    
    int ch = map[0][0] - 'A';
    visited[ch] = true;
    dfs(0, 0, 1);
    cout<<maxi;
}
