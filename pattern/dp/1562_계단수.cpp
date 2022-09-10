#include <iostream>
using namespace std;

int n;
int ans;
int dp[105][10][1<<10];
//long long number;

int dfs(int idx, int num, int bit){
  
    if (dp[idx][num][bit]) return dp[idx][num][bit];
    if (idx == n) return bit==(1<<10) - 1 ? 1 :0;
    
    int res = 0;
    if (num+1<10) res += dfs(idx+1, num+1, bit | 1<<(num+1));
    if (num-1>=0) res += dfs(idx+1, num-1, bit | 1<<(num-1));
    return dp[idx][num][bit] = (res%1000000000);
}

int main(){
    cin>>n;
    for (int i=1; i<=9; i++){
        ans += dfs(1, i, 1<<i);
        ans %= 1000000000;
    }
    cout<<ans;
}
