#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1001];
int cache[1001];
int nexts[1001];

int lis2(int start){
    int& res = cache[start];
    if (res != -1) return res;
    
    res = 1;
    
    for (int idx = start+1; idx<n; idx++){
        if(arr[start] < arr[idx]){
            int newer = 1+lis2(idx);
            if (res < newer){
                res = newer;
                nexts[start] = idx;
            }
//            res = max(res, 1+lis2(idx));
        }
    }
    return res;
}
int main(){
    memset(nexts, -1, sizeof(nexts));
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for (int i=0; i<n; i++) cin>>arr[i];
    
    int maximum=-1;
    int maxStarts=-1;
    for (int i=0; i<n; i++){
        int newer = lis2(i);
        if (maximum < newer){
            maximum = newer;
            maxStarts = i;
        }
    }
    cout<<maximum<<'\n';
    cout<<arr[maxStarts]<<' ';
    while(nexts[maxStarts] != -1){
        
        cout << arr[nexts[maxStarts]]<<' ';
        maxStarts = nexts[maxStarts];
    }
}
