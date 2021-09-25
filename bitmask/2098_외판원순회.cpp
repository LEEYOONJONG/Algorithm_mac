#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// 많이 참고햇음..//
int n;
int arr[20][20];
int dp[20][1<<20];

int travel(int here,  int visited){
//    cout<<here<<' ';
    //만약 다 방문했을 경우, 출발지가 0이었으므로 arr[here][0]를 반환해야
    if (visited == ((1<<n)-1)){
        //만약 here에서 0으로 돌아가는게 존재하면 그것 리턴하면 됨.
        if (arr[here][0] != 0) return arr[here][0];
        // 없으면 절대 답이 될 수 없음.
        else return 987654321;
    }
    int& res = dp[here][visited];
    if (res != -1) return res;
    res = 987654321;

    for (int next=0; next<n; next++){
        if (visited & (1 << next) || arr[here][next]==0) continue; // next가 이미 방문했던 곳이라면 통과
        //현재까지의 값과 next를 지나가는 비용을 비교하여 작은값 반영
        res = min(res, arr[here][next] + travel(next, visited | 1<<next) );
    }
    return res;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    // 0에서 출발. 0 을 방문한채로 출발
    cout<<travel(0, 1);
}
