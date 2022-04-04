#include <iostream>
#include <algorithm>
#define INF 1000000001
using namespace std;

int n, m;
int arr[270000];
int minIDT[270000];
int maxIDT[270000];

int B=1;
void initial(){
    for (int i=B-1; i>=1; i--){
        minIDT[i] = min(minIDT[i*2], minIDT[i*2+1]);
        maxIDT[i] = max(maxIDT[i*2], maxIDT[i*2+1]);
    }
}
int lgMin(int l, int r){ // l은 0부터가 아닌 1부터
    l += B-1; r += B-1;
    int minV = INF;
    while(l <= r){
        if (l%2 == 1) minV = min(minV, minIDT[l]);
        if (r%2 == 0) minV = min(minV, minIDT[r]);
        l = (l+1) / 2;
        r = (r-1) / 2;
    }
    return minV;
}
int lgMax(int l, int r){ // l은 0부터가 아닌 1부터
    l += B-1; r += B-1;
    int maxV = 0;
    while(l <= r){
        if (l%2 == 1) maxV = max(maxV, maxIDT[l]);
        if (r%2 == 0) maxV = max(maxV, maxIDT[r]);
        l = (l+1) / 2;
        r = (r-1) / 2;
    }
    return maxV;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for (B=1; B<n; B*=2);
    
    for (int i=0; i<270000; i++)
        minIDT[i] = INF; // lgMin을 위해
   
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        minIDT[B+i] = arr[i];
        maxIDT[B+i] = arr[i];
    }
    initial();

    int from, to;
    for (int i=0; i<m; i++){
        cin>>from>>to;
        cout<<lgMin(from, to)<<' '<<lgMax(from, to)<<'\n';
    }
}
