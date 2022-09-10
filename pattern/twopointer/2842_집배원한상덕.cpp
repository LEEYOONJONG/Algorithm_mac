#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    char map[51][51];
    bool visited[51][51];
    int height[51][51];
    int horizon[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int vertical[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 동쪽부터
    memset(visited, false, sizeof(visited));
    vector<int> numset;
    int n; cin>>n;
    int srow=-1, scol=-1;
    int kcount=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>map[i][j];
            if (map[i][j]=='P'){
                srow = i;
                scol = j;
            }
            else if (map[i][j] == 'K'){
                kcount++;
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>height[i][j];
            numset.push_back(height[i][j]);
        }
    }
    sort(numset.begin(), numset.end());
    numset.erase(unique(numset.begin(), numset.end()), numset.end());
    int start = numset[0];
    int end = numset[0];
    
    while(1){ // start, end
        queue<pair<int, int>> que;
        if (start <= map[srow][scol] && map[srow][scol] <= end ){
            
        }
        que.push(make_pair(srow, scol));
        while(!que.empty()){ // queue
            int nowrow = que.front().first;
            int nowcol = que.front().second;
            que.pop();
            
        }
    }
}
