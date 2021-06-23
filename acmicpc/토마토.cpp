#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <tuple>
using namespace std;


vector<vector<vector<int>>> arr;
vector<vector<vector<bool>>> visited;

vector<tuple<int, int, int>> rot;

int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
int dz[6] = {1,-1,0,0,0,0};

void bfs(){
    queue<tuple<int, int, int>> q;
    for (int i=0; i<rot.size(); i++){
        q.push(rot[i]);
        int height = get<0>(rot[i]);
        int row = get<1>(rot[i]);
        int col = get<2>(rot[i]);
        visited[height][row][col] = true;
    }
    while(!q.empty()){
        tuple<int, int, int> top = q.front();
        q.pop();
        
        
    }
}

int main(){
    int m, n, h; // n은 row, m은 col
    cin>>m>>n>>h;
    arr = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int>(m, 0)));
    visited = vector<vector<vector<bool>>>(h, vector<vector<bool>>(n, vector<bool>(m, false)));
    for (int height = 0; height<h; height++){
        for (int row = 0; row < n; row++){
            for (int col = 0; col < m; col++){
                cin>>arr[height][row][col];
                if (arr[height][row][col] == 1) rot.push_back(make_tuple(height, row, col));
                
            }
        }
    }
    
    bfs();
}
