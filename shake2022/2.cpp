
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    vector<pair<int, int>> bridge;
    int n; cin>>n;
    int l, r;
    for (int i=0; i<n; i++){
        cin>>l>>r;
        bridge.push_back(make_pair(l, r));
    }
    sort(bridge.begin(), bridge.end());
//    for (int i=0; i<n; i++){
//        cout<<bridge[i].first<<", "<<bridge[i].second<<endl;
//    }
    
    int summ = bridge[0].second - bridge[0].first;
    int res = bridge[0].second;
    for (int i=1; i<n; i++){
        if (res >= bridge[i].first){ // 연결되면
            if (res >= bridge[i].second){ // 0-6, 2-4
                continue;
            }
            else {
                summ += (bridge[i].second - res);
                res = bridge[i].second;
            }
        }
        else { // jump // res < bridge[i].first
            int blank = bridge[i].first - res;
            if (blank <= summ){
                summ = bridge[i].second-bridge[i].first;
                res = bridge[i].second;
            }
            else { // 종료조건
                break;
            }
        }
    }
    cout<<res;
}
