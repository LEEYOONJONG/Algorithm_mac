#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int boardMaxX, boardMaxY;
bool visited[101][101]; // [x][y]
void fill(int minX, int minY, int maxX, int maxY){
    for (int x = minX; x<maxX; x++){
        for (int y = minY; y<maxY; y++){
            visited[x][y] = true;
        }
    }
}
int dfs(int x, int y){
    if (x<0 || x>=boardMaxX || y<0 || y>=boardMaxY) return 0;
    if (visited[x][y]) return 0;
    visited[x][y] = true;
    return 1 + dfs(x+1, y) + dfs(x-1, y) + dfs(x, y+1) + dfs(x, y-1);
}
int main(){
    int m, n, k; cin>>m>>n>>k;
    boardMaxX = n; boardMaxY = m;
    int minY, minX, maxY, maxX;
    vector<int> s;
    for (int i=0; i<k; i++){
        cin>>minX>>minY>>maxX>>maxY;
        fill(minX, minY, maxX, maxY);
    }

    for (int x=0; x<boardMaxX; x++){
        for (int y=0; y<boardMaxY; y++){
            if (visited[x][y]) continue;
            int res = dfs(x, y);
            if (res != 0)  {
                s.push_back(res);
            }
        }
    }
    sort(s.begin(), s.end());
    cout<<s.size()<<endl;
    for (int i=0; i<s.size(); i++) cout<<s[i]<<' ';
}