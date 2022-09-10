#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

// 감염된 신규감염자가 3개면 됨
int n, m;
int board[8][8];
int board2[8][8];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> virus;
queue<pair<int, int>> vir2;

int bfs()
{
    while(!vir2.empty()){
        pair<int, int> front = vir2.front();
        // cout<<"** "<<front.first<<", "<<front.second<<endl;
        vir2.pop();
        for (int i=0; i<4; i++){
            int nextRow = front.first + dr[i];
            int nextCol = front.second + dc[i];
            if (nextRow < 0 || nextRow >= n || nextCol < 0 ||nextCol>=m) continue;
            if (board2[nextRow][nextCol] == 0){
                board2[nextRow][nextCol] = 2;
                vir2.push(make_pair(nextRow, nextCol));
            }
        }
    }
    int cnt=0;
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            if (board2[row][col] == 0) cnt++;
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    int oneCount=0;
    int maxRes=-1;
    vector<pair<int, int>> candidates;
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            cin >> board[row][col];
            if (board[row][col] == 2) virus.push(make_pair(row, col));
            else if (board[row][col] == 1) oneCount++;
            else if (board[row][col] == 0) candidates.push_back(make_pair(row, col));
        }
    }
    for (int i=0; i<candidates.size(); i++){
        for (int j=i+1; j<candidates.size(); j++){
            for (int k=j+1; k<candidates.size(); k++){
                int cand1row = candidates[i].first;
                int cand1col = candidates[i].second;
                int cand2row = candidates[j].first;
                int cand2col = candidates[j].second;
                int cand3row = candidates[k].first;
                int cand3col = candidates[k].second;
                board[cand1row][cand1col] = 1;
                board[cand2row][cand2col] = 1;
                board[cand3row][cand3col] = 1;
                vir2 = virus;
                memcpy(board2, board, sizeof(board));
                int temp = bfs();
                maxRes = max(maxRes, temp);
                board[cand1row][cand1col] = 0;
                board[cand2row][cand2col] = 0;
                board[cand3row][cand3col] = 0;
                
            }
        }
    }
   
    cout<<maxRes;
}
