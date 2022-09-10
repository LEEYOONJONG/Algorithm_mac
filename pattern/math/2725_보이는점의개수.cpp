#include <iostream>
using namespace std;
int memo[1001];

int gcd(int a, int b){ // a <= b
    if (a==0) return b;
    return gcd(b%a, a);
}

int eulerpie(int n){
    int result = 1;
    for (int i=2; i<n; i++){
        if (gcd(i,n) == 1)
            result++;
    }
    return result;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int c; cin>>c;
    
    memo[1]=3;
    for (int j=2; j<=1000; j++){
        memo[j] = memo[j-1] + (2 * eulerpie(j));
    }
    
    
    for (int i=0; i<c; i++){
        int n; cin>>n;
//        if (memo[n] != 0){
//            cout<<memo[n]<<'\n';
//            continue;
//        }
        
        
        cout<<memo[n]<<'\n';
        
    }
}
