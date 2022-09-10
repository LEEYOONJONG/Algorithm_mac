#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
//    vector<int> length(n);
    
    for(int i=0; i<n; i++){
        int input;
        cin>>input;
        arr[i] = input;
    }
    
//    for (int k=0; k<n; k++){
//        length[k] = 1;
//        for (int j=0; j<k; j++){
//            if (arr[j] < arr[k]){
//                length[k] = max(length[k], length[j]+1);
//            }
//        }
//    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i=1; i<n; i++){
        if (ans.back() < arr[i]){
            ans.push_back(arr[i]);
        }
        else{
            // binary search
            int start = 0; // index임
            int end = ans.size()-1;
            while(1){
                if (start==end){
                    // arr[i]가 ans[start, end]보다 크다면 ans[start, end+1]에 덮어쓰기
                    if (ans[start]< arr[i]) ans[start+1] = arr[i];
                    else ans[start] = arr[i];
                    // 아니면 start,end위치에 덮기
                    break;
                }
                else if (end < start){
                    // start 위치에 덮어써야
                    ans[start]=arr[i];
                    break;
                }
                int mid = (start+end)/2;
                if (arr[i] >ans[mid]){
                    start = mid+1;
                }
                else if (arr[i] < ans[mid]){
                    end = mid-1;
                }
                else { // 같다면
                    // mid 위치 덮어쓰기
                    ans[mid] = arr[i];
                    break;
                }
            }
        }
    }
//    for (int i=0; i<ans.size(); i++){
//        cout<<ans[i]<<' ';
//    }
    cout<<ans.size();
}
