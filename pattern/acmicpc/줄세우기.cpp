#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vc[32001];
int inDegree[32001];

int main(){
    int n, m; // n은 명 수, m은 케이스 개수
    cin>>n>>m;
    
    int a, b;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        inDegree[b]++;
        vc[a].push_back(b);
    }
    
    queue<int> q;
    int result[32001];
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    for (int i=0; i<n; i++){
        if (q.empty()) break;
        int x = q.front();
        q.pop();
        result[i] = x;
        for (int j=0; j<vc[x].size(); j++){
            int d = vc[x][j];
            inDegree[d]--;
            if (inDegree[d] == 0) q.push(d);
        }
    }
    for (int i=0; i<n; i++){
        cout<<result[i]<<' ';
    }
}
