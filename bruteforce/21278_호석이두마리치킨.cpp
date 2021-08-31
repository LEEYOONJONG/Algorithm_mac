#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int road[110][110];


int main(){
    cin>>n>>m; // 건물개수, 도로개수

    memset(road, 123456789, sizeof(road));

    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        road[a][b] = 1;
        road[b][a] = 1;
    }
    for (int i=1; i<=n; i++){
        road[i][i] = 0;
    }
    for (int k=1; k<=n; k++){ // 거쳐가는 정점
        for (int i=1; i<n; i++){ // 출발
            for (int j=i+1; j<=n; j++){ // 도착
                if (road[i][k] + road[k][j] < road[i][j]){
                    road[j][i] = road[i][j] = road[i][k] + road[k][j];
                }
            }
        }
    }
    
    int minimumTime = 987654321;
    int ch1=-1, ch2=-1;
    for (int i=1; i<n; i++){ // 첫번째 치킨집
        for (int j=i+1; j<=n; j++){ // 두번째 치킨집
            int timesum=0;
            for (int node=1; node<=n; node++){
                // 첫번째 치킨집과 두번째 치킨집 중 가까운 곳
                timesum += 2 * min(road[node][i], road[node][j]);
            }
            if (timesum < minimumTime){
                minimumTime = timesum;
                ch1 = i;
                ch2 = j;
            }
        }
    }
    cout<<ch1<<" "<<ch2 << " "<<minimumTime;
}
