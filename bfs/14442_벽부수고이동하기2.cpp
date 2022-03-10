#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k;

char map[1002][1002];
bool visited[1001][1001];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int minCrushed[1001][1001];

struct Data{
    int row;
    int col;
    int route;
    int crushed;
    Data(int row, int col, int route, int crushed):row(row), col(col), route(route), crushed(crushed){};
};

int main(){
    memset(minCrushed, -1, sizeof(minCrushed));
    cin>>n>>m>>k;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    queue<Data> que;
    que.push(Data(0, 0, 1, 0));
    
    while(!que.empty()){
        int row = que.front().row;
        int col = que.front().col;
        int route = que.front().route;
        int crushed = que.front().crushed;
//        cout<<row<<", "<<col<<" / "<<route<<" / "<<crushed<<endl;
        que.pop();
        if (row==n-1 && col==m-1){
            cout<<route;
            return 0;
        }
        if (crushed > k) continue;
        if (visited[row][col]){
            if (crushed >= minCrushed[row][col]) continue;
        }
        visited[row][col] = true;
        
        if (minCrushed[row][col] == -1) minCrushed[row][col] = crushed; // 처음이거나
        if (minCrushed[row][col] > crushed) minCrushed[row][col] = crushed; // 나중온게 더 작으면 업뎃
        
        
        for (int i=0; i<4; i++){
            int newRow = row+dr[i];
            int newCol = col+dc[i];
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;
            if (visited[newRow][newCol]){
                // 만약 crushed가 minCrush보다 작다면 기회는 남아있다.
                if (crushed >= minCrushed[newRow][newCol]) continue;
            }
            if (map[newRow][newCol] == '0'){
                que.push(Data(newRow, newCol, route+1, crushed));
            }
            else {
                que.push(Data(newRow, newCol, route+1, crushed+1));
            }
        }
        
    }
    
    cout<<-1;
    return 0;
}

