#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        string a,  b;
        map<string, int> mp;
        for (int j=0; j<n; j++){
            cin>>a>>b;
            if (mp.find(b) == mp.end()){
                mp.insert({b, 1});
            }
            else {
                mp[b] = mp[b]+1;
            }
        }
        // cout<<mp.size()<<endl;
        int res = 1;
        for (auto iter:mp){
            // cout<<iter.first<<" "<<iter.second<<'\n';
            res *= (iter.second + 1);
        }
        cout<<res-1<<'\n';

    }
}