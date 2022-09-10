#include <iostream>

using namespace std;

int parent[100001];
int counts[100001];

int find(int x){
    if (x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b){
    parent[find(a)] = find(b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int g; cin>>g;
    int p; cin>>p;
    for (int i=0; i<=g; i++) parent[i] = i;
    
    int arr[100001];
    for (int i=1; i<=p; i++){
        cin>>arr[i];
    }
    for (int i=1; i<=p; i++){
        int ancestor = find(arr[i]);
        if (ancestor == 0){
            cout<<i-1;
            return 0;
        }
        uni(ancestor, ancestor-1);
    }
    
    cout<<p;
    return 0;
}
