#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int n,m;
char map[101][101];
bool visited[101][101];

struct Maze{
    int row;
    int col;
    int kans;
    
    Maze(int row, int col, int kans):row(row), col(col), kans(kans){};
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    cin>>n>>m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
//    cout<<"----\n";
    queue<Maze> que;
    que.push(Maze(0, 0, 1));
    
    while(!que.empty()){
        int row = que.front().row;
        int col = que.front().col;
        int kans = que.front().kans;
        if (row==n-1 && col==m-1){
            cout<<kans;
            return 0;
        }
        que.pop();
        if (visited[row][col]) continue;;
        
        visited[row][col] = true;
        
        for (int i=0; i<4; i++){
            int newRow = row+dr[i];
            int newCol = col+dc[i];
            if (newRow < 0 || newRow>=n || newCol<0 || newCol>=m) continue;
            if (map[newRow][newCol] == '0') continue;
            
            if (visited[newRow][newCol]) continue;
            que.push(Maze(newRow, newCol, kans+1));
        }
    }
    
}
