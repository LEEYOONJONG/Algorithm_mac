#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int a, b;
        cin>>a>>b;
        int mini = min(a, b);
//        int maxi = max(a, b);
        
        int sum = a+b;
        int res = sum/4;
        cout<<min(res, mini)<<'\n';
    }
}
