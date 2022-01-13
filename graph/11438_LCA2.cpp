#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 20
using namespace std;

int N, M;
int a, b;
int dp[MAX+1][100001];
int depth[100001];
bool visited[100001];
vector<int> v[100001];

void dfs(int n, int d){
    visited[n] = true;
    depth[n]=d; // 1. 깊이를 기록
    int adj;
    for (int i=0; i<v[n].size(); i++){
        adj = v[n][i];
        if (visited[adj]) continue;
        dp[0][adj] = n; // 2. 직속 부모를 dp배열의 첫 행에 기록
        dfs(adj, d+1);
    }
}
void setDP(){
    for (int i=1; i<MAX; i++){
        for (int j=1; j<=N; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}
int lca(int x, int y){
    if (depth[x] > depth[y]){
        swap(x, y); // 항상 y가 더 깊다
    }
    for (int i=MAX; i>=0; i--){ // 깊이 동일하도록 맞추기.
        if (depth[y] - depth[x] >= (1<<i))
            y = dp[i][y];
    }
    if (x==y) return x;
    for (int i=MAX; i>=0; i--){
        if (dp[i][x] != dp[i][y]){ // 최대한 조상으로 올리기
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>N;
    for (int i=1; i<N; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    dfs(1, 1);
    setDP();
    cin>>M;
    for (int i=1; i<=M; i++){
        cin>>a>>b;
        cout<<lca(a, b)<<'\n';
    }
}
