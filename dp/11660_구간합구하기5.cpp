#include <iostream>
using namespace std;
int arr[1025][1025];
int sum[1025][1025];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            cin>>arr[row][col];
        }
    }
    sum[0][0] = arr[0][0];
    for (int col=1; col<n; col++){
        sum[0][col] = sum[0][col-1]+arr[0][col];
    }
    for (int row=1; row<n; row++){
        sum[row][0] = sum[row-1][0] + arr[row][0];
    }
    for (int row=1; row<n; row++){
        for (int col=1; col<n; col++){
            sum[row][col] = sum[row-1][col] + sum[row][col-1] - sum[row-1][col-1] + arr[row][col];
        }
    }
    
    int x1, y1, x2, y2;
    for (int i=0; i<m; i++){
        cin>>x1>>y1>>x2>>y2;
        x1--; y1--; x2--; y2--;
        int res = sum[x2][y2];
        if (x1 != 0) res -= sum[x1-1][y2];
        if (y1 != 0) res -= sum[x2][y1-1];
        if (x1 != 0 && y1 != 0) res += sum[x1-1][y1-1];
        cout<<res<<'\n';
    }

}
