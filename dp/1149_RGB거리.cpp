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
int red[1010], green[1010], blue[1010];
int dpRed[1010], dpGreen[1010], dpBlue[1010];
int minimum=123456789;

void dp(){ // sum은 그전까지의 합 의미.
    
    for(int index=n; index>=0; index--){
        dpRed[index] = red[index] + min(dpGreen[index+1], dpBlue[index+1]);
        dpGreen[index] = green[index] + min(dpRed[index+1], dpBlue[index+1]);
        dpBlue[index] = blue[index] + min(dpRed[index+1], dpGreen[index+1]);
    }
    cout<<min({dpRed[0], dpGreen[0], dpBlue[0]});
}

int main(){
    // 코드 진짜 엉망임.
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>red[i]>>green[i]>>blue[i];
    }
    red[n] = green[n] = blue[n] = 0;
    dpRed[n]=dpGreen[n]=dpBlue[n]=0;
    dp();
}
