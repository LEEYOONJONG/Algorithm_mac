#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int B;
vector<long long> arr(300003, 0);

void initIDT(){
    for (int i=B-1; i>0; i--){ // i=7
        arr[i] = arr[i<<1] + arr[ (i<<1) | 1];
    }
}
void update(int p, long long v){
    p += B-1;
    arr[p] = v;
    while(p>>=1){
        arr[p] = arr[p<<1] + arr[(p<<1)|1];
    }
}
long long rangeSum(int l, int r){
    l += B-1;
    r += B-1;
    long long sum = 0;
    while (l<=r){
        if (l%2 == 1) sum += arr[l];
        if (r%2 == 0) sum += arr[r];
        l = (l+1)>>1;
        r = (r-1)>>1;
    }
    return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, q; cin>>n>>q;
    
    for (B=1; B<n; B<<=1);
    
    for (int i=B; i<B+n; i++)
        cin >> arr[i];
    initIDT();
    
    
    for (int i=0; i<q; i++){
        int x, y, a;
        long long b;
        cin>>x>>y>>a>>b;
        if (x>y) swap(x, y);
        cout<<rangeSum(x, y)<<'\n';
        update(a, b);
    }
}

