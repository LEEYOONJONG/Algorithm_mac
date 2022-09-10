#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int crain[51];
    
    vector<int> box;
    
    int n; cin>>n;
    for (int i=0; i<n; i++) cin>>crain[i];
    sort(crain, crain+n, greater<int>());
    
    int m; cin>>m;
    int boxInput;
    for (int i=0; i<m; i++){
        cin>>boxInput;
        box.push_back(boxInput);
    }
    sort(box.rbegin(), box.rend());
    int cnt=0;
    
    while(!box.empty()){
        int boxIndex=0;
        if (box[boxIndex] > crain[0]){
            cout<<-1;
            return 0;
        }
        cnt++;
        for (int i=0; i<n; i++){ // crain
            for (int j=0; j<box.size(); j++){
                if (crain[i] >= box[j]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
    
    
    
    
}
