#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
char map[51][51];
bool visited[51][51];
struct Data{
    int row;
    int col;
    int rank;
    Data(int row, int col, int rank):row(row), col(col), rank(rank){};
    
    bool operator< (const Data d) const{
        return rank > d.rank; // rank에 대한 오름차순
    }
};

int main(){
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    memset(visited, false, sizeof(visited));
    cin>>n;
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            cin>>map[row][col];
        }
    }
    priority_queue<Data> pqueue;
    pqueue.push(Data(0,0,0));
    
    while(1){
        Data now = pqueue.top();
        int nowRow = now.row;
        int nowCol = now.col;
        int nowRank = now.rank;
        pqueue.pop();
        if (nowRow == n-1 && nowCol == n-1){
            cout<<nowRank;
            return 0;
        }
        if (visited[nowRow][nowCol]) continue;
        visited[nowRow][nowCol] = true;
        
        for (int i=0; i<4; i++){
            int nextRow = nowRow+dr[i];
            int nextCol = nowCol+dc[i];
            if (visited[nextRow][nextCol]) continue;
            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) continue;
            if (map[nextRow][nextCol] == '1') pqueue.push(Data(nextRow, nextCol, nowRank));
            else pqueue.push(Data(nextRow, nextCol, nowRank+1));
        }
    }
}
