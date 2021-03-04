#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int m, n; //세로 n, 가로 m
int arr[101][101];
int garo[4] = {1, 0, -1, 0};
int sero[4] = {0, -1, 0, 1};

int dijkstra(int srcrow, int srccol){
    vector<vector<int>> dist(n+1, vector<int>(m+1, INFINITY));
    dist[srcrow][srccol]=0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(srcrow, srccol)));
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int hererow = pq.top().second.first;
        int herecol = pq.top().second.second;
        if (hererow==n && herecol==m){
            break;
        }
        pq.pop();
        if (dist[hererow][herecol] < cost) continue; // 기존값보다 크면 패스
        for (int i=0; i<4; i++){
            int thererow = hererow+sero[i];
            int therecol = herecol+garo[i];
            if ((thererow<1 || thererow>n) ||(therecol<1 || therecol>m)) continue;
            int nextDist = cost+arr[thererow][therecol]; // 벽에 부닥치면 1을 더하게 됨
            if (nextDist<dist[thererow][therecol]){ //지금 선출한 값이 기존값보다 작다면
                dist[thererow][therecol] = nextDist;    //기존값을 새로 업데이트하고
                pq.push(make_pair(-nextDist, make_pair(thererow, therecol))); // 푸시
            }
        }
    }
    return dist[n][m];
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    
    string str;
    for (int i=1; i<=n; i++){
        cin>>str;
        for (int j=1; j<=m; j++){
            arr[i][j] = str[j-1] - '0'; // arr[1][1] = str[0]
        }
    }
    cout<<dijkstra(1, 1);
}
