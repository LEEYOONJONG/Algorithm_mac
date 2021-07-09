#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int num[2001];
int dp[200002]; // 중간값*2
int main(){
// 바깥이 팰린드롬이면 안쪽도 팰린드롬일 가능성 높다.
// 안쪽이 팰린드롬 아니라면 바깥도 팰린드롬 아닐 가능성 높다. ( )
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int n, m;
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>num[i];
    }
    
    cin>>m;
    
    for (int i=0; i<m; i++){
        int s, e;
        cin>>s>>e; // 1 3
        
        bool isPalindrome=true;
        
        // 바깥이 이미 팰린드롬이면
        if (dp[s+e]>=(e-s+1)/2 ){
            cout<<1<<'\n';
            continue;
        }
        
        for (int j=s; j<=(s+e)/2; j++){
            //안쪽에서 팰린드롬을 발견한다면
            if (dp[s+e]>=(e-s+1)/2 - (j-s) ){
                break;
            }
            
            if (num[j] != num[s+e-j]){
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome)
        {
            // dp
            dp[s+e]=(e-s+1)/2; // 원래는 dp[(s+e)/2] 여야 하지만 index가 정수여야 하므로
            
            // 출력
            cout<<1<<'\n';
        }
            
        else cout<<0<<'\n';
        
        
    }
}
