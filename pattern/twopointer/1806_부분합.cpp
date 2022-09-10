#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int arr[100001];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    long long start=0, end=0;
    long long sum = arr[end];
    long long minlength = 1000000000;
    while(start<n && end<n){
        
        if (sum < m){ // 아직 작다면
            end++;
            sum += arr[end];
        }
        
        else {
            minlength = min(minlength, end-start+1);

            sum -= arr[start];
            start++;
            
        }
    }
    if (minlength == 1000000000) cout<<0;
    else cout<<minlength;
}
