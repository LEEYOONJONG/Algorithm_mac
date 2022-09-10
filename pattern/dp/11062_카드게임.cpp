#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, cards[1001];
bool whos[1001];
int dp[1001][1001][2];
int calc(int start, int end, bool who){
    if (start>end) return 0;
    if (dp[start][end][who]) return dp[start][end][who];
    if (who==false){ // 근우인경우
        if (start==end) return cards[start];
        return dp[start][end][who] = max(cards[start] + calc(start+1, end, !who) , cards[end]+calc(start, end-1, !who));

    }
    else {// 명우인경우
        if (start==end) return 0;
        return dp[start][end][who] = min(0 + calc(start+1, end, !who) , 0 + calc(start, end-1, !who));

    }
}
// 근우 -> 명우

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>t;
    for (int tc=0; tc<t; tc++){
        memset(dp, 0, sizeof(dp));
        cin>>n;
        for (int i=0; i<n; i++) cin>>cards[i];
        cout<<calc(0, n-1, false)<<'\n';
    }

}
