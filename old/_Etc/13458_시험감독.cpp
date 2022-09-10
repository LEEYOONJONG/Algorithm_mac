#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,b, c, member[1000001];
    cin>>n;
    long long res=0;
    
    for (int i=0; i<n; i++){
        cin>>member[i];
    }
    cin>>b>>c;
    for (int i=0; i<n; i++){
        member[i] = member[i] - b; // 총감독 뺌
        if (member[i] <= 0){ // 총감독으로 충분하다.
            res += 1;
        }
        else{
            res += 1;
            res += ceil(member[i]/(double)c);
        }
        
    }
    cout<<res;
    
}
