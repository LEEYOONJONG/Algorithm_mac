#include <iostream>
#include <cstring>
using namespace std;
int cache[1000][1000];

int bino(int x, int r){
    if (r==1) return x;
    if (x==r || r==0) return 1;
    if (cache[x][r] != -1) return cache[x][r];
    return cache[x][r] = (bino(x-1, r)+bino(x-1, r-1)) % 10007;
}
int main(){
    memset(cache, -1, sizeof(cache));
    int n;
    cin>>n;
    if (n%2==1){
        int res=1;
        for (int i=n/2; i>=1; i--){
            res = (res+bino(n-i , i))%10007;
        }
        cout<<res;
    }
    else {
        int res = 1;
        for (int i=(n-1)/2; i>=0; i--){
            res = (res+bino( n-i, i))%10007;
        }
        cout<<res;
    }
}
