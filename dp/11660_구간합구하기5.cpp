
#include <iostream>
using namespace std;

long long arr[1025][1025];
long long sum[1025][1025];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    
    for (int row=1; row<=n; row++){
        for (int col=1; col<=n; col++){
            cin>>arr[row][col];
        }
    }
    
    for (int row=1; row<=n; row++){
        for (int col=1; col<=n; col++){
            if (col==1) sum[row][col] = arr[row][col];
            else sum[row][col] = sum[row][col-1] + arr[row][col];
        }
    }
    
    for (int row=2; row<=n; row++){
        for (int col=1; col<=n; col++){
            sum[row][col] += sum[row-1][col];
        }
    }
    int x1, y1, x2, y2;
    for (int i=0; i<m; i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]<<'\n';
    }
}
