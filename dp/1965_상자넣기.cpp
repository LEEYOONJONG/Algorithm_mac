#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    int arr[1001];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int res=1;
    
    //initialize
    for (int i=0; i<n; i++) dp[i] = 1;
    
    for (int i=0; i<n; i++){
        for (int j=i-1; j>=0; j--){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
    }
    cout<<res;
}
