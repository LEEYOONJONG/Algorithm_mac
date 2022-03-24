#include <iostream>
using namespace std;

int n; // 점의 개수
int m; // 차례 수
int parent[500010];

int find(int x){//파페파페
    if (x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void uni(int a, int b){//유페파파
    parent[find(a)] = find(b);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    for (int i=0; i<n; i++) parent[i] = i;
    
    int a, b;
    int isExit =  -1;
    for (int i=1; i<=m; i++){
        cin>>a>>b;
        if (find(a) != find(b)){
            uni(a, b);
        }
        else{
            if (isExit == -1) isExit = i;
            uni(a, b);
        }
    }
    if (isExit != -1) cout<<isExit;
    else     cout<<0;
    
}
