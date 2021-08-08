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

int arr[1000000];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        
        int n, k;
        cin>>n>>k; // n은 개수, k는 목표
        memset(arr, 0, sizeof(arr));
        for (int j=0; j<n; j++){
            cin>>arr[j];
        }
        sort(arr, arr+n);
        int chai = 987654321;
        
        int count=1;
        int biggestSecond = n;
        for (int first=0; first<n-1; first++){
            
            //second 찾자
            // 근데 (first*2 - k)가 chai보다 크다면 볼것도 없다.
            if (arr[first]*2 - k > chai) break;
            int small = first+1;
            int big = biggestSecond-1;
            int mid;
            
            while(1){
                if (big<small) break;
                mid = (small+big)/2;
                int sum = arr[first] + arr[mid];
                
                int temp = abs(sum - k);
                //만약 temp가 chai보다 작다면 업뎃
                if (temp < chai){
                    chai = temp;
                    count=1;
                    biggestSecond = mid+1;
                }
                else if (temp == chai){
                    count++;
                    biggestSecond = mid+1;
                }
                
                // mid 조절하기
                if (sum < k){
                    small = mid+1;
                }
                else if (sum > k){
                    big = mid-1;
                }
                //같다면 break
                else {
                    break;
                }
            }
        }
        cout<<count<<'\n';
    }
}

