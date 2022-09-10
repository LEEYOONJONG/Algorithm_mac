#include <iostream>
using namespace std;

int parent[1000001];

int find(int a){
    if (parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b){ // a를 b에 합치기
    parent[find(a)] = find(b); 
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m; cin>>n>>m;
    for (int i=1; i<=n; i++) parent[i]=i;

    int op, a, b;
    for (int i=0; i<m; i++){
        cin>>op>>a>>b;
        if (op==0){ // union
            uni(a, b);
        } else { // same set
            cout << ((find(a) == find(b)) ? "YES" : "NO")<<'\n';
        }
    }
}