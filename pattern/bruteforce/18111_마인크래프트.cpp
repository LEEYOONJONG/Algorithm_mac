#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, b; cin>>n>>m>>b;
    int arr[250001];
    int minH = 987654321;
    int maxH = -1;
    
    for (int i=0; i<n*m; i++){
        cin>>arr[i];
        if (arr[i] > maxH) maxH = arr[i];
        if (arr[i] < minH) minH = arr[i];
    }
    sort(arr, arr+(n*m), greater<int>());
    int timeMin = 987654321;
    int resHeight=-1;
    for (int h = maxH; h>=minH; h--){
        int initB = b;
        int time = 0;
        for (int i=0; i<n*m; i++){
            if (h < arr[i]){
                time += 2*(arr[i] - h);
                initB += (arr[i] - h);
            }
            else if (h >arr[i]){
                time += h - arr[i];
                initB -= (h - arr[i]);
                if (initB < 0){
                    time = 1000000000;
                    break;
                }
            }
        }
        if (timeMin > time){
            resHeight = h;
            timeMin = time;
        }
    }
    cout<<timeMin<<" "<<resHeight;
}
