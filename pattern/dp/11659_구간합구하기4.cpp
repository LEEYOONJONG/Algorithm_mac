#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int arr[100001]={0,};
    int sum[100001]={0,};
    
    for (int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1]+arr[i];
    }
    int a, b;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }
    
    
}
