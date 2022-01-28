#include <iostream>
using namespace std;

int arr[500001];
int main(){
    int n, h;
    cin>>n>>h;
    int input;
    int BottomCnt=0;
    for (int i=0; i<n; i++){
        cin>>input;
        if (i%2==0){
            BottomCnt++;
            arr[input+1]--; // 이 높이서부터 -1
        }
        else {
            arr[h-input+1]++; // 이 높이서부터 +1
        }
    }
    int Min=987654321;
    int MinCnt=0;
    for (int i=1; i<=h; i++){
        BottomCnt += arr[i]; //
        if (Min > BottomCnt){
            MinCnt=1;
            Min = BottomCnt;
        }
        else if (Min == BottomCnt){
            MinCnt++;
        }
    }
    cout<<Min<<" "<<MinCnt;
}
