#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool sosu[4000001];
int sosulist[400000];
int main(){
    
    int n; cin>>n;
    if (n==1){
        cout<<0;
        return 0;
    }
    memset(sosu, true, sizeof(sosu));
    int sosuIndex=0;
    for (int i=2; i<=n; i++){
        if (sosu[i] == false) continue;
        sosulist[sosuIndex++] = i;
        for (long long j=(long long)i*(long long)i; j<=n; j += i){
            sosu[j] = false;
        }
    }
   
    int start=0, end=0;

    
    int sum=0, cnt=0;
    while(1){
        if (sum < n){ // 아직 다다르지 못함
            if (sosulist[end] > n) break;
            sum += sosulist[end];
            end++;
        }
        else if (sum > n){
            sum -= sosulist[start];
            start++;
        }
        else{
            cnt++;
            sum -= sosulist[start];
            start++;
        }
    }
    cout<<cnt;
}
