#include <iostream>

using namespace std;

int parent[201];

int find(int x){
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void uni(int a, int b){
    parent[find(a)] = find(b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
    int m; cin>>m;
    int input;
    for (int row=1; row<=n; row++){
        for (int col=1; col<=n; col++){
            cin>>input;
            if (input==1){
                uni(row, col);
            }
        }
    }
    
    int route[1001];
    for (int i=0; i<m; i++){
        cin>>route[i];
    }
    for (int i=1; i<m; i++){
        if (find(route[i-1]) != find(route[i])){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
