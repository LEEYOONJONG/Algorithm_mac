#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, arr[1000001];
int idx[1000001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=0; i<n; i++) cin>>arr[i];
    vector<int> v;
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
            while(true){
                if (left >= right) break;
                int mid = (left+right)/2;
                
                if (v[mid] < arr[i]){
                    left = mid+1; // 원래는 left = mid 일 수도 있었겠지만, 이 문제에서 left는 반드시 mid보다는 커야한다.
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
    vector<int> vRev;
    int K = v.size();
    
    for (int i=n-1; i>=0; i--){
        if (K==0)break;
        if (K == idx[i]){
            vRev.push_back(arr[i]);
            K--;
        }
    }
    for (int i=vRev.size()-1; i>=0; i--){
        cout<<vRev[i]<<' ';
    }
}
