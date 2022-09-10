#include <algorithm>
#include <iostream>

using namespace std;
int house[200001];
int main(){
    int n, c; cin>>n>>c; // 집 n개, 공유기 c개
    for (int i=0; i<n; i++) cin >> house[i];
    sort(house, house+n);
    int minIdx = 1;
    int maxIdx = house[n-1];
    while(1){
        int midIdx = (minIdx+maxIdx)/2;
    }
}
