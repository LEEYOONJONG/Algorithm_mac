#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;

int find(int idx){
    if (parent[idx]==-1) return idx;
    else return parent[idx] = find(parent[idx]);
}

void unions(int idx1, int idx2){
    parent[idx1] = find(idx2); // idx2 조상 밑에 idx1 붙이기
}


int main(){
    int n, m; cin>>n>>m;
    parent = vector<int>(n, -1);
    for (int i=0; i<m; i++){
        int s, a, b; cin>>s>>a>>b;
        if (s==0){
            int first = find(a);
            int second = find(b);
            if (first == second) unions(a, b);
            
        }
    }
    
}
