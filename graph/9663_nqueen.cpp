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

int n;
int cnt=0;
int col[16];

bool promising(int i){
    bool isOK=true;
    int k=1;
    while(k<i && isOK){
        if (col[i]==col[k] || i-k==abs(col[i]-col[k])){
            isOK=false;
        }
        k++;
    }
    return isOK;
}
void queens(int i){
    if (promising(i)){
        if (i==n){
            cnt++;
        }
        else{
            for (int j=1; j<=n; j++){
                col[i+1] = j;
                queens(i+1);
            }
        }
    }
}


int main(){
    cin>>n;
    queens(0);
    cout<<cnt;
}
