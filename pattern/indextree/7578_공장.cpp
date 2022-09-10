#include <algorithm>
#include <iostream>
using namespace std;

int ranks[1000001];
int B=1;
int IDT[1050000];

void update(int idx, int val){
    idx += B-1;
    IDT[idx] = val;
    idx /= 2;
    while(idx>=1){
        IDT[idx] = IDT[idx*2]+IDT[idx*2+1];
        idx /= 2;
    }
}
int lgSum(int l, int r){
    l += B-1;
    r += B-1;
    int sumV = 0;
    while(l<=r){
        if (l % 2 == 1) sumV += IDT[l];
        if (r % 2 == 0) sumV += IDT[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }
    return sumV;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n; cin>>n;
    int input;
    for (int i=1; i<=n; i++){
        cin>>input;
        ranks[input] = i; // rank[132] = 1, rank[392] = 2, ...
    }
    for (B=1; B<n; B*=2);
    long long res=0;
    for (int i=0; i<n; i++){
        cin>>input;
        int calcRank = ranks[input]; // 2 -> 4 -> 1 -> 3 -> 5
        res += lgSum(calcRank, n);
        update(calcRank, 1);
    }
    cout<<res;
}
