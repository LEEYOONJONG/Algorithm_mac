#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int arr[100001];
    int idx[100001];
    vector<int> v;
    while(cin>>n){
        v.clear();
        memset(arr, 0, sizeof(arr));
        memset(idx, 0, sizeof(idx));
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        v.push_back(arr[0]);
        idx[0] = 1;
        
        for (int i=1; i<n; i++){
            if (v[v.size()-1] < arr[i]){
                v.push_back(arr[i]);
                idx[i] = v.size();
            }
            else {
                int left = 0;
                int right = v.size()-1;
                while(1){
                    if (left >= right) break;
                    int mid = (left+right)/2;
                    
                    if (v[mid] < arr[i]){
                        left = mid+1;
                    }
                    else {
                        right = mid;
                    }
                }
                v[left] = arr[i];
                idx[i] = left+1;
            }
        }
        cout<<v.size()<<'\n';
    }
}
