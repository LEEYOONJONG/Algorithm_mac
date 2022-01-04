#include <iostream>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int arr[10001];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int start=0, end=0;
    int sum = arr[end], cnt=0;
    while(start<n && end<n){
        if (sum == m){
            cnt++;

            sum -= arr[start];
            start++;
            end++;
            sum += arr[end];
        }
        else if (sum < m){ // 아직 작다면
            end++;
            sum += arr[end];
        }
        else {
            sum -= arr[start];
            start++;
        }
    }
    cout<<cnt;
}
