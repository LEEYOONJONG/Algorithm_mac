#include <iostream>
#include <string.h>
using namespace std;
int cabbage[51][51];
bool visited[51][51];
int m, n; //m은 가로, n은 세로

void dfs(int row, int col){
    if (row<0 || row>=n || col<0 || col>=m) return; // 범위 벗어난다면 0 리턴
    if (visited[row][col]) return; // 이미 방문했다면 0 리턴
    visited[row][col]=1;
    if (cabbage[row][col]==1){ // 현재 위치에 배추가 존재한다면 주변 또한 탐색하며 visited를 1로 처리해주자.
        dfs(row+1, col);
        dfs(row-1, col);
        dfs(row, col+1);
        dfs(row, col-1);
    }
    return;
}

//전체 좌표를 탐색하며 dfs 진입하기
void dfsAll(){
    int count = 0;
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            // 아직 방문한 적 없고, 배추가 존재한다면 카운트한다.
            if (visited[row][col] == 0 && cabbage[row][col]==1){
                count++;
                dfs(row, col);
            }
        }
    }
    cout<<count<<'\n';
}

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        memset(cabbage, 0, sizeof(cabbage)); //memset으로 cabbage 2차원 배열의 초기값을 0으로
        memset(visited, 0, sizeof(visited)); //memset으로 visited 2차원 배열의 초기값을 0으로
        int k;
        cin>>m>>n>>k;
        for (int j=0; j<k; j++){ // 배추 위치 입력받기
            int x, y;
            cin>>x>>y;
            cabbage[y][x] = 1;
        }
        dfsAll();
        
    }
    
}
