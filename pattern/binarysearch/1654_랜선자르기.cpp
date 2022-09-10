#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int i, sum, k, n;
    cin>>k>>n;
    int arr[10001];
    
    cin>>arr[0];
    int mid = arr[0];
    for (int i=1; i<k; i++){
        cin>>arr[i];
        mid = max(mid, arr[i]);
    }
    
    long long left = 1;
    long long right = mid;
    while(true){
        // mid 길이에서의 개수 구하기.
        for (sum=i=0; i<k; i++)  sum += arr[i]/mid;
        
        if (sum >= n){ // 여기긴 한데, 아직 후보임. 답이 더 커질 수 있기에. 길이 늘려야
            left = mid;
        }
        else{ //(sum < n)// 길이 줄여야 함 = right을 작게
            right = mid;
        }
       
        if (left+1 >= right){
            cout<<left;
            return 0;
        }
        
        mid = left + (right-left)/2;
    }
}
