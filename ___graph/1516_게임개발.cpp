#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    
    vector<int> adj[501];
    int indegree[501]={0,};
    int cost[501];
    int costSum[501];
    
    for (int i=1; i<=n; i++){
        cin >> cost[i];
    }
    
}
