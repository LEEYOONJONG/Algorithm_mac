#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
//#include <functional>
using namespace std;

vector<int> vc[32010];
int inDegree[32010];

int main(){
    int n, m;
    priority_queue<int, vector<int>, greater<int>> pq;
    memset(inDegree, 0, sizeof(inDegree));
    
    cin>>n>>m; // 문제수, 정보수
    
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b; // a -> b
        vc[a].push_back(b);
        inDegree[b]++;
    }
    for (int i=1; i<=n; i++){
        sort(vc[i].begin(), vc[i].end());
    }
    
    
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            pq.push(i);
        }
    }
    
    
    while(!pq.empty()){
        int top = pq.top();
        cout<<top<<" ";
        pq.pop();
        // top과 연결된 노드와의 엣지 하나씩 제거
        for (int i=0; i<vc[top].size(); i++){
            int there = vc[top][i];
            inDegree[there]--;
            if (inDegree[there]==0){
                pq.push(there);
            }
        }
        
    }
}
