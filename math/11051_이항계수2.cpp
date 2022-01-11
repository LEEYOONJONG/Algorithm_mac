#include <iostream>
using namespace std;

int n;
int l[1001][1001]={0,};

void initialize(){
    l[0][0] = 1 ;
    for (int i=1; i<=n; i++){
        l[i][0]=1;
        for (int j=1; j<=i; j++){
            l[i][j] = (l[i-1][j-1] +l[i-1][j]) % 10007;
        }
    }
    
}
int nCr(int n, int r){
    return l[n][r];
}
int main(){
    int k; cin>>n>>k;
    initialize();
    cout<<nCr(n, k);
}
