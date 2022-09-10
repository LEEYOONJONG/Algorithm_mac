//
//  타일채우기.cpp
//  acmicpc
//
//  Created by YOONJONG on 2021/05/05.
//

#include <iostream>
using namespace std;
int dp[31];
int main(){
    int n;
    cin>>n;
    if (n%2==1){
        cout<<0;
        return 0;
    }
    dp[0]=0;
    dp[2]=3;
    
    for (int i=4; i<=n; i+=2){
        dp[i] += dp[2]*dp[i-2]+2;
        for (int j=i-4; j>=2; j--){
            dp[i] += 2*dp[j];
        }
    }
    cout<<dp[n];
}
