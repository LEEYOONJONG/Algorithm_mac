#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int m, n;
int k;
int cabbage[51][51];
int visited[51][51];

void dfs(int row, int col){
    if (row<0 || row>=n ||col <0 || col>=m) return;
    if (visited[row][col] == 1 || cabbage[row][col] == 0) return; // 이미 방문했다면, 배추없다면 취소!
    visited[row][col] = 1;
    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
}


int dfsAll(){
    int count=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (visited[i][j]==0 && cabbage[i][j] == 1){
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        cin>>m>>n>>k;
        memset(cabbage, 0, sizeof(cabbage));
        memset(visited, 0, sizeof(visited));
        for (int j=0; j<k; j++){
            int x, y;
            cin>>x>>y;
            cabbage[y][x] = 1;
        }
        cout<<dfsAll()<<endl;
    }
}
