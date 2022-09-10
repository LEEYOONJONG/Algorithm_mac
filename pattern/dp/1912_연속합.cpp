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

int main(){
    int arr[100001];
    int curMax;
    int maximum;
    
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    curMax = arr[0];
    maximum = curMax;
    for (int end=1; end<n; end++){
        // curMax+arr[end] vs. arr[end]
        if (arr[end] < curMax + arr[end]){ // 새로 시작하는것보다 이전 꺼를 반영하는게 더 큰 경우
            curMax = curMax + arr[end];
        }
        else {
            curMax = arr[end];
        }
        if (curMax>maximum) maximum = curMax;
    }
    cout<<maximum;
}
