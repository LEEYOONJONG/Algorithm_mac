#include <iostream>
#include <cstring>
using namespace std;


long long mod[1000010]; // 배열의 길이가 100만을 넘어가므로 int로는 안된다.
// int 배열 : 약 25만
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long x;
    
    int c;
    cin>>c;
    
    for (int i=0; i<c; i++){
        int d, n;
        long long sum=0; // 누적합
        memset(mod, 0, sizeof(mod));
        
        cin>>d>>n;
        for (int j=0; j<n; j++){
            cin>>x;
            sum += x;
            mod[sum % d]++;
        }
        
        long long res=mod[0];
        for (int j=0; j<d; j++){
            res += mod[j]*(mod[j]-1)/2;
        }
        cout<<res<<'\n';
    }
}
