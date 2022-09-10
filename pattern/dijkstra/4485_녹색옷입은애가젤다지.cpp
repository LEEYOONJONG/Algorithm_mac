#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[126][126];
bool visited[126][126];
int dist[126][126];
int n;

struct Data{
    int row;
    int col;
    int weight;
    Data();
    Data(int row, int col, int weight) : row(row), col(col), weight(weight){};
    bool operator<(const Data d) const{
        return weight > d.weight;
    }
};

void dijkstra(){
    dist[0][0] = arr[0][0];
    visited[0][0] = true;
    priority_queue<Data> pq;
    pq.push(Data(0, 0, dist[0][0]));
    while(!pq.empty()){
        Data top = pq.top();
        pq.pop();
        int topRow = top.row;
        int topCol = top.col;
        // 위
        if ((0 <= topRow-1)){
            if (!visited[topRow-1][topCol]){
                visited[topRow-1][topCol] = true;
                int newDist = top.weight + arr[topRow-1][topCol];
                if (dist[topRow-1][topCol] > newDist){
                    dist[topRow-1][topCol] = newDist;
                    pq.push(Data(topRow-1, topCol, newDist));
                }
            }
        }
        //아래
        if ((topRow+1 < n)){
            if (!visited[topRow+1][topCol]){
                visited[topRow+1][topCol] = true;
                int newDist = top.weight + arr[topRow+1][topCol];
                if (dist[topRow+1][topCol] > newDist){
                    dist[topRow+1][topCol] = newDist;
                    pq.push(Data(topRow+1, topCol, newDist));
                }
            }
        }
        //왼쪽
        if ((0 <= topCol-1)){
            if (!visited[topRow][topCol-1]){
                visited[topRow][topCol-1] = true;
                int newDist = top.weight + arr[topRow][topCol-1];
                if (dist[topRow][topCol-1] > newDist){
                    dist[topRow][topCol-1] = newDist;
                    pq.push(Data(topRow, topCol-1, newDist));
                }
            }
        }
        //오른쪽
        if ((topCol+1 < n)){
            if (!visited[topRow][topCol+1]){
                visited[topRow][topCol+1] = true;
                int newDist = top.weight + arr[topRow][topCol+1];
                if (dist[topRow][topCol+1] > newDist){
                    dist[topRow][topCol+1] = newDist;
                    pq.push(Data(topRow, topCol+1, newDist));
                }
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int cnt=1;
    while(1){
        cin>>n;
        if (n==0) break;
        
        memset(visited, false, sizeof(visited));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dist[i][j] = 987654321;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        dijkstra();
        
        cout<<"Problem "<<cnt++<<": "<<dist[n-1][n-1]<<'\n';
    }
}
