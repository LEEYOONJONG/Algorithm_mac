#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        long long n, k;
        cin>>n>>k;
        long long stretched = n+k; // 13
        stretched = stretched-2*k; // 7
        long long res = 0;
        if ( n >= stretched && stretched > 0){
            res = (n+stretched)*(n-stretched+1)*4/2; // 등차수열의합*4
            cout<<res<<'\n';
        }
        else {
            res = (n+1)*(n)*4/2; // 등차수열의합*4
            cout<<res<<'\n';
        }
        
//        cout<<res<<'\n';
    }
}
