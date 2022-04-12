#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000011
using namespace std;

pair<int, int> IDT[270000];
int n, m, B;


void initIDT(){
    for (int i=B-1; i>=1; i--){
        IDT[i] = min(IDT[i*2], IDT[i*2+1]);
    }
}
void update(int idx, int val){
    idx += B-1;
    IDT[idx].first = val;
    idx /= 2;
    while(idx>=1){
        IDT[idx] = min(IDT[idx*2], IDT[idx*2+1]);
        idx/=2;
    }
}
int minIDT(int start, int end){
    start+=B-1;
    end += B-1;
    pair<int, int> minV = {INF, INF};
    while(start<=end){
        if (start % 2 == 1){
            minV = min(minV, IDT[start]);
        }
        if (end % 2 == 0){
            minV = min(minV, IDT[end]);
        }
        start = (start+1)/2;
        end = (end-1)/2;
    }
    return minV.second;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    
    for (B=1; B<n; B*=2);
    for (int i=B; i<2*B; i++){
        IDT[i] = {INF, INF};
    }
   
    
    for (int i=0; i<n; i++){
        int value;
        cin>>value;
        IDT[B+i] = {value, i+1};
    }
    cin>>m;
    initIDT();
    int a, b, c;
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        if (a==1){ // update
            update(b, c);
        }
        else {
            cout<<minIDT(b, c)<<'\n';
        }
    }
}
