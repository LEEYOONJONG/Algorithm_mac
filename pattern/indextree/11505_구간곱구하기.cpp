#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
int IDT[2100000];
int B=1;

void init(){
    for (int i=B-1; i>=1; i--){
        IDT[i] = (((long long)IDT[i*2]%1000000007) * ((long long)IDT[i*2+1]%1000000007))%1000000007;
    }
}
void update(int idx, int val){
    idx += B-1;
    IDT[idx] = val;
    idx /= 2;
    while(idx>0){
        IDT[idx] = ((long long)IDT[idx*2] * (long long)IDT[idx*2+1])%1000000007; // ?
        idx /= 2;
    }
}
int lgMultiply(int l, int r){
    l += B-1;
    r += B-1;
    int maxV=1;
    while(l<=r){
        if (l%2 == 1) maxV = ((long long) maxV * IDT[l])%1000000007;
        if (r%2 == 0) maxV = ((long long) maxV * IDT[r])%1000000007;
        l = (l+1)/ 2;
        r = (r-1)/ 2;
    }
    return maxV;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    memset(IDT, 1, sizeof(IDT));
    for (B=1; B<n; B*=2);
    for (int i=0; i<n; i++){
        cin>>IDT[B+i];
    }
    init();
    int a, b, c;
    for (int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if (a==1){
            // bth to c
            update(b, c);
        }
        else {
            // print b~c
            cout<<lgMultiply(b, c)<<'\n';
        }
    }
}
