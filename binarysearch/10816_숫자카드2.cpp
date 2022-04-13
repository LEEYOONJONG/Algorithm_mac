#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    int arr[500001];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n); // 정렬
    int m; cin>>m;
    int input;
    for (int i=0; i<m; i++){
        cin>>input;
        // val의 개수 구하기
        cout<<upper_bound(arr, arr+n, input) - lower_bound(arr, arr+n, input)<<' ';
        
    }
}
