#include <iostream>
#include <cmath>
using namespace std;

int n;
int chu[31];
int m;
int marvel[40001];
bool dp[31][40001];
void solve(int i, int w){
    if (i > n || dp[i][w] == true) return;
    dp[i][w] = true;
    solve(i+1, w+chu[i]);
    solve(i+1, abs(w-chu[i]));
    solve(i+1, w);
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++) cin>>chu[i];
    
    solve(0, 0);
    
    
    
    cin>>m;
    int temp;
    for (int i=0; i<m; i++){
        cin>>temp;
        if (dp[n][temp] == true) cout<<"Y ";
        else cout<<"N ";
    }
}
