#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int dp[1001][1001];

int main(){
    string a, b;
    cin>>a>>b;
    
    for (int i=1; i<=a.size(); i++){
        for (int j=1; j<=b.size(); j++){
            if (a[i-1] == b[j-1]){
                dp[i][j] = 1;
            }
        }
    }
    int res=0;
    for (int i=1; i<=a.size(); i++){
        for (int j=1; j<=b.size(); j++){
            if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    for (int i=0; i<=a.size(); i++){
        for (int j=0; j<=b.size(); j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<res;
    queue<pair<int, int>> que;
    que.push(make_pair(a.size(), b.size()));
    
    // 위, 왼쪽 중 숫자가 같은 방향으로 이동해야.
//    while(!que.empty()){
//        pair<int, int> top = que.front();
//        que.pop();
//        int aIndex = top.first-1;
//        int bIndex = top.second-1;
//        if (a[aIndex] == b[bIndex]){
//
//        }
//        else {
//            que.push(make_pair(top.first-1, top.second));
//            que.push(make_pair(top.first, top.second-1));
//        }
//    }
}
