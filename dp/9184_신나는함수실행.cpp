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

int dp[101][101][101];

int funny(int a, int b, int c){
    if (a<=0 || b<=0 || c<=0) return 1;
    if (dp[50+a][50+b][50+c] != 0) return dp[50+a][50+b][50+c];
    
    if (a > 20 || b > 20 || c > 20){
        return dp[50+a][50+b][50+c] = funny(20, 20, 20);
    }
    else if (a<b && b<c){
        return dp[50+a][50+b][50+c] = funny(a, b, c-1) + funny(a, b-1, c-1) - funny(a, b-1, c);
    }
    else {
        return dp[50+a][50+b][50+c] = funny(a-1, b, c) + funny(a-1, b-1, c) + funny(a-1, b, c-1) - funny(a-1, b-1, c-1);
    }
}

int main(){
    int a, b, c;
    
    while(1){
        cin>>a>>b>>c;
        if (a==-1&&b==-1&&c==-1) break;
        
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<funny(a, b, c)<<'\n';
        
        
    }
}
