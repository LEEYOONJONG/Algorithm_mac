#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k; cin>>n>>k;
    vector<pair<int, int>> arr(n);
    vector<int> bag(k);
    
    for (int i=0; i<n; i++){
        int m, v; cin>>m>>v;
        arr[i].first = m;
        arr[i].second = v;
    }
    for (int i=0; i<k; i++){
        cin>>bag[i];
    }
    sort(arr.begin(), arr.end());
    sort(bag.begin(), bag.end());
    
    priority_queue<int> pq;
    int idx=0;
    long long res=0;
    for (int i=0; i<k; i++){ // 가방
        while (idx < n){
            if (arr[idx].first <= bag[i]){
                pq.push(arr[idx].second);
            } else break;
            idx++;
        }
        if (!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        
    }
    cout<<res;
}
