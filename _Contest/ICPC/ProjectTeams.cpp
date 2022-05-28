#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int n;
    int arr[10010];
    cin>>n;
    for (int i=0; i<2*n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+2*n);
    int minimum = 987654321;
    for (int i=0; i<n; i++){
        int sum = arr[i] + arr[2*n-1-i];
        minimum = min(minimum, sum);
    }
    cout<<minimum;
}
