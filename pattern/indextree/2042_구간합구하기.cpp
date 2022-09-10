#include <iostream>
#include <vector>
using namespace std;

long long tree[2100000];
int n, m, k;
int B;

void initIDT(){
    for (int i=B-1; i>=1; i--){
        tree[i] = tree[i*2]+tree[i*2+1]; // sum index tree
    }
}
void update(long long pivot, long long value){
    pivot += B-1;
    tree[pivot] = value;
    
    while(pivot/=2){
        tree[pivot] = tree[pivot*2]+tree[pivot*2+1];
    }
}
long long rangeSum(long long l, long long r){
    l += B-1;
    r += B-1;
    long long Sum=0;
    while(l<=r){
        if (l%2==1){
            Sum += tree[l];
        }
        l = (l+1)/2;
        if (r%2==0){
            Sum += tree[r];
        }
        r = (r-1)/2;
    }
    return Sum;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m>>k;
    for (B=1; B<n; B*=2);
    
    for (int i=B; i<B+n; i++){
        cin>>tree[i];
    }
    initIDT();
    long long a, b, c;
    for (int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if (a==1){
            //b th => c
            update(b, c);
        }
        else {
            // b ~ c
            cout<<rangeSum(b, c)<<'\n';
        }
    }
    
}
