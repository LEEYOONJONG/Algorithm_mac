
#include <iostream>
using namespace std;
int dp[1001]={0,};

int calc(int s){
    if (s<=3){
        return dp[s];
    }
    if (dp[s] != 0) return dp[s];
    
    if (s%2 == 0){
        int tmp = calc(s/2);
        int tmp2 = calc(s/2-1);
        return dp[s] = (tmp*tmp+2*tmp2*tmp2)%10007;
    }
    else{
        int tmp = calc((s+1)/2-1);
        int tmp2 = calc((s+1)/2);
        
        return dp[s] = (tmp*tmp2 + 2* calc((s+1)/2-2) * tmp)%10007;
    }
}

int main(){
    int n;
    cin>>n;
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=3;
    dp[3]=5;
    
    cout<<calc(n);
    
}
