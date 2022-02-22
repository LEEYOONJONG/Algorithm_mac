#include <iostream>
using namespace std;

long long a, b, c;

long long calc_pow(long long a, long long b){
    if (b==1) return a%c;
    
    if (b%2 == 0){
        long long middle = calc_pow(a, b/2)%c;
        return (middle*middle)%c;
    }
    else { // 11
        long long middle = calc_pow(a, b/2)%c; // 5
        return (((middle*middle)%c)*(a%c))%c; // 5+5+1
    }
}

int main(){
    cin>>a>>b>>c;
    cout<<calc_pow(a, b);
}
