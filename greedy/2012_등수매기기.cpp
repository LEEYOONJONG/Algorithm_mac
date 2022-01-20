#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    int predict[500000];
    for (int i=0; i<n; i++) cin>>predict[i];
    sort(predict, predict+n);
    
    long long res=0;
    for (int i=0; i<n; i++){
        int real = i+1;
        res += abs(predict[i] - (long long)real);
    }
    cout<<res;
}
