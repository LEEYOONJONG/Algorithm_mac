#include <iostream>
using namespace std;

int parent[1000001];

int find(int x){
    if (parent[x] == x) return x;
    // x가 올라가며 만나는 모든 원소들의 부모는 최상위 부모가 된다.
    return parent[x] = find(parent[x]);
}
void uni(int a, int b){
    //a의 조상의 부모는 b의 조상이다.
    parent[find(a)] = find(b);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    int o, a, b;
    for (int i=0; i<=n; i++){
        parent[i] = i;
    }
    for (int i=0; i<m; i++){
        cin>>o>>a>>b;
        if (o==0){ // 합집합
            uni(a, b);
        }
        else{ // 같은집합인지확인
            if(find(a) == find(b)) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
