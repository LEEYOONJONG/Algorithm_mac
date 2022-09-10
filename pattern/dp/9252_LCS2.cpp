#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int dp[1010][1010];
bool visited[1010][1010];
queue<pair<int, int>> que;
stack<char> st;
string a, b;
int main(){
    cin>>a>>b;
    for (int mapB=1; mapB<=b.size(); mapB++){
        for (int mapA=1; mapA<=a.size(); mapA++){
            int strA = mapA-1;
            int strB = mapB-1;
            if (b[strB] == a[strA]){
                dp[mapB][mapA] = dp[mapB-1][mapA-1] + 1;
            }
            else{
                dp[mapB][mapA] = max(dp[mapB-1][mapA], dp[mapB][mapA-1]);
            }
            
        }
    }
//    for (int i=0; i<=b.size(); i++){
//        for (int j=0; j<=a.size(); j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    cout<<dp[b.size()][a.size()]<<'\n';
    
    if (dp[b.size()][a.size()] == 0) return 0;
    que.push(make_pair(b.size(), a.size()));

    
    while(!que.empty()){
        int toprow = que.front().first;
        int topcol = que.front().second;
        visited[toprow][topcol] = true;
        que.pop();
        if (toprow==0 || topcol==0) continue;
        // 왼쪽으로만 이동가능하다면
        if (dp[toprow][topcol-1] == dp[toprow][topcol]  &&  dp[toprow-1][topcol] != dp[toprow][topcol]){
            if (!visited[toprow][topcol-1])
                que.push(make_pair(toprow, topcol-1));
        }
        // 위쪽으로만 이동가능하다면
        else if (dp[toprow-1][topcol] == dp[toprow][topcol] && dp[toprow][topcol-1] != dp[toprow][topcol]){
            if (!visited[toprow-1][topcol])
                que.push(make_pair(toprow-1, topcol));
        }
        // 둘다 가능하다면
        else if (dp[toprow][topcol-1] == dp[toprow][topcol]  &&  dp[toprow-1][topcol] == dp[toprow][topcol]){
            if (!visited[toprow][topcol-1])
                que.push(make_pair(toprow, topcol-1));
            if (!visited[toprow-1][topcol])
                que.push(make_pair(toprow-1, topcol));
        }
//        둘다 불가능하다면
        else{
            st.push(a[topcol-1]);

            // 다 도달했다면 종료
            if (dp[toprow][topcol] == 1) break;
            que = queue<pair<int, int>>();

            if (!visited[toprow-1][topcol-1]) que.push(make_pair(toprow-1, topcol-1));
        }
       
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
