#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, l; cin>>n>>l;
    int hole[1001];
    for (int i=0; i<n; i++) cin >> hole[i];
    sort(hole, hole+n);
    
    int isTaped=-1;
    int cnt=0;
    for (int i=0; i<n; i++){
        if (isTaped == -1){
            isTaped = hole[i];
            cnt++;
        }
        else {
            if (hole[i] - isTaped >= l){
                isTaped = hole[i];
                cnt++;
            }
        }
    }
    cout<<cnt;
}