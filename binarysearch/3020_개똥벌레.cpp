#include <algorithm>
#include <iostream>
using namespace std;

int n, h;
int bottom[100001], top[100001];

int searchBottom(int height){
    // height보다 작은것의 개수를 구하자
    int lo = 0;
    int hi = n/2-1;
    int mid;
    //범위체크
//    cout<<"**"<<height<<" , "<<bottom[hi]<<endl;
    if (height > bottom[hi]) return 0;
    else if (height <= bottom[lo]) return n/2;
    while(1){
        if (lo+1 == hi){
            if (bottom[lo] == height) return n/2-lo;
            else if (bottom[lo] < height) return n/2-lo-1;
        }
        mid = (lo+hi)/2;
        if (height < bottom[mid]){
            hi = mid;
        }
        else if (bottom[mid] < height){
            lo = mid;
        }
        else {  // bottom[mid] == height
            if (mid == 0) return n/2;
            else { // 같은 것이 여러개일 수도 있으니 일단 시도
                hi = mid;
            }
            
        }
    }
}
int searchTop(int height){
    // height보다 작은것의 개수를 구하자
    int lo = 0;
    int hi = n/2-1;
    int mid;
    
    // 범위 체크
    if (height > top[hi]) return 0;
    else if (height <= top[lo]) return n/2;
    // 반복문
    while(1){
        if (lo+1 == hi){
            if (top[lo] == height) return n/2-lo;
            else if (top[lo] < height) return n/2-lo-1;
        }
        mid = (lo+hi)/2;
        if (height < top[mid]){
            hi = mid;
        }
        else if (top[mid] < height){
            lo = mid;
        }
        else {  // bottom[mid] == height
            if (mid == 0) return n/2;
            else { // 같은 것이 여러개일 수도 있으니 일단 시도
                hi = mid;
            }
            
        }
    }
}
int main(){
    cin>>n>>h;
    for (int i=0; i<n/2; i++){
        cin>>bottom[i]>>top[i];
    }
    sort(bottom, bottom+(n/2));
    sort(top, top+(n/2));
    
    int Min=987654321;
    int cnt=0;
    for (int i=1; i<=h; i++){
        int res =searchBottom(i)+searchTop(h-i+1);
        if (Min > res){
            Min = res;
            cnt=1;
        }
        else if (Min == res){
            cnt++;
        }
    }
    cout<<Min<<" "<<cnt;
}
