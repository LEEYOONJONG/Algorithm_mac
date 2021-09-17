#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> route[1010];
int timeArray[1010];
int dp[1010]; // dp[some]은 some의 비용을 제거한 최대 비용
int calc(int start){
    if (dp[start] != -1) return dp[start];
    int maximum = 0;
    
    for (int i=0; i<route[start].size(); i++){
        int end = route[start][i];
        maximum = max(maximum, timeArray[end] + calc(end));\
//        cout<<"start : "<<start<<", end : "<<end<<", maximum : "<<maximum << endl;
    }
    
    return dp[start] = maximum; //
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        
        int n, k;
        cin>>n>>k; // 노드 개수, 규칙 개수
        
        for (int j=1; j<=n; j++) route[j].clear(); // 초기화
        memset(dp, -1, sizeof(dp));
        
        for (int j=1; j<=n; j++){
            cin>>timeArray[j];
        }
        for (int j=0; j<k; j++){
            int start, end;
            cin>>start>>end;
            route[end].push_back(start);
        }
        int w;
        cin>>w;
        cout<<calc(w)+timeArray[w]<<endl;
    }
}
