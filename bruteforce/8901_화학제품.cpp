#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int a, b, c, ab, bc, ca;

int maximum(int a, int b, int c){
    int na, nb, nc;
    int maximum=-1;
    for (int i=0; i<=min(a, b); i++){
        int sum;
        na = a-i;
        nb = b-i;
        nc = c;
        for (int j=0; j<=min(nb, nc); j++){
            sum = ab*i;
            int nnc = nc-j;
            sum += bc*j;
            sum += ca*(min(na, nnc));
            if (maximum < sum){
                maximum = sum;
            }
        }
    }
    return maximum;
}
int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        cin>>a>>b>>c;
        cin>>ab>>bc>>ca;
        cout<<maximum(a, b, c)<<'\n';
    }
}
