#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
bool visited[501][501];
int row, col;
int cnt;
int dh[4] = {-1, 0, 1, 0}; // 왼 아래 오 위
int dv[4] = {0, 1, 0, -1};

int dfs(int r, int c){
    if (r<0 || r>= row || c < 0 || c >= col) return 0;
    if (visited[r][c]) return 0;
    
    visited[r][c] = true;
    if (map[r][c] == 0){
        return 0;
    }
    else {
        int counter=1; // map[r][c] == 1이므로
        for (int i=0; i<4; i++){
            counter += dfs(r+dv[i], c +dh[i]);
        }
        return counter;
        
    }
}

int main(){
    memset(visited, false, sizeof(visited));
    cin>>row>>col;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cin>>map[i][j];
        }
    }
    int pictureNum=0;
    int maxArea=0;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (visited[i][j] == false){ // 방문됐더라면 갈 필요없음
                if (map[i][j] == 1){
                    pictureNum++;
                    int area = dfs(i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
    }
    cout<<pictureNum<<'\n'<<maxArea;
}
