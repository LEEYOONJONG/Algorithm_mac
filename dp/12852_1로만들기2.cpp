#include <iostream>
#include <deque>
#include <cstring>
#include <vector>
using namespace std;

int dp[1000001];
vector<int> route[1000001];

int calc(int input, vector<int>& vc){ // 10 0 / 9 1 / 3 2 / 1 3
    if (input == 1){
        return 1;
    }
    if (dp[input] != -1){
        // vc에 input미만부터 시작하는 루트를 추가해줘야함.
        vc.insert(vc.end(), route[input].begin(), route[input].end());
        return dp[input];
        
    }
    
    int r1=987654321, r2=987654321, r3=987654321;
    vector<int> v1, v2, v3;
    
    if (input%3==0){
        v1.push_back(input/3);
        r1 = 1+calc(input/3, v1);
    }
    if (input%2==0){
        v2.push_back(input/2);
        r2 = 1+calc(input/2, v2);
    }
    v3.push_back(input-1);
    r3 = 1+calc(input-1, v3);
    
    
    if (r1 <= r2 && r1 <= r3){
        vc.insert(vc.end(), v1.begin(), v1.end());
        route[input].insert(route[input].end(), v1.begin(), v1.end());
        return dp[input] = r1;
    }
    else if (r2 <= r1 && r2 <= r3){
        vc.insert(vc.end(), v2.begin(), v2.end());
        route[input].insert(route[input].end(), v2.begin(), v2.end());
        return dp[input] = r2;
    }
    else {
        vc.insert(vc.end(), v3.begin(), v3.end());
        route[input].insert(route[input].end(), v3.begin(), v3.end());
        return dp[input] = r3;
    }
    
}
int main(){
    int x;
    vector<int> vc;
    memset(dp, -1, sizeof(dp));
    cin>>x;
    
    vc.push_back(x);
    cout<<calc(x, vc)-1<<endl;
    for (int i=0; i<vc.size(); i++){
        cout<<vc[i]<<' ';
    }
}
