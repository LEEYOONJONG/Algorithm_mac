#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int a, b, c;
    int arr[101][101];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) arr[i][j] = 987654321;
    }
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        arr[a][b] = min(arr[a][b], c);
    }
    for (int pass=1; pass<=n; pass++){
        for (int start=1; start<=n; start++){
            for (int end=1; end<=n; end++){
                if (start==end) continue;
                if (arr[start][end] > arr[start][pass] + arr[pass][end]){
                    arr[start][end] = arr[start][pass] + arr[pass][end];
                }
            }
        }
    }
    for (int row=1; row<=n; row++){
        for (int col=1; col<=n; col++){
            if (arr[row][col] >= 987654321) cout<<0<<' ';
            else cout<<arr[row][col]<<' ';
        }
        cout<<'\n';
    }
    
}
