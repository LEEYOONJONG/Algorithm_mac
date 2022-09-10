#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    long long n; cin>>n;
    long long arr[6];
    for (int i=0; i<6; i++) cin>>arr[i];
    if (n==1){
        sort(arr, arr+6);
        long long res = arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
        cout<<res;
        return 0;
    }
    int check1[8] = {0,2, 5, 3, 0,2, 5, 3};
    int check2[8] = {2,5, 3, 0, 2,5, 3, 0};
    int check3[8] = {1,1,1,1,4,4,4,4};
    
    long long mini;
    for (int i=0; i<8; i++){
        long long arr2[3];
        arr2[0] = arr[check1[i]];
        arr2[1] = arr[check2[i]];
        arr2[2] = arr[check3[i]];
        sort(arr2, arr2+3);
        long long res = arr2[0]*((5*n*n) - (8*n) + 4);
        res += arr2[1] * (8*n - 8);
        res += arr2[2] * 4;
        if (i==0) mini = res;
        else mini = min(mini, res);
    }
    
    cout<<mini;
}
