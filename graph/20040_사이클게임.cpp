//
//  20040_사이클게임.cpp
//  acmicpc
//
//  Created by YOONJONG on 2021/09/09.
//

#include <iostream>
using namespace std;

int parent[500010];
int ranking[500010];

int find(int u){
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
bool uni(int u, int v){
    u = find(u);
    v = find(v);
    
    if (u == v) return true; // 같다는 건 사이클 완성 의미
    
    if (ranking[u] > ranking[v]){
        // v가 u에 들어가야 함.
        parent[v] = u;
    }
    else if (ranking[u] < ranking[v]){
        //u가 v에 들어가야 함
        parent[u] = v;
    }
    else {
        parent[u] = v; // u를 v의 자식으로
        ranking[v]++;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    
    // parent 초기화
    for (int i=0; i<n; i++){
        parent[i] = i;
        ranking[i] = 1;
    }
    
    // m차례까지 입력
    for (int i=1; i<=m; i++){
        int a, b;
        cin>>a>>b;
        // a의 parent 찾기
        if (uni(a, b) == true){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
