#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int parent[200001];
int groupmembers[200001];

int find(int x){
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void uni(int a, int b){
    parent[find(a)] = find(b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    for (int i=0; i<t; i++){
        for (int i=0; i<200001; i++) {
            parent[i] = i;
            groupmembers[i] = 1;
        }
        
        int f; cin>>f;
        string a, b;
        map<string, int> m;
        
        for (int j=0; j<f; j++){
            cin>>a>>b;
            int aIndex, bIndex;
            if (m.find(a) != m.end()){ // 찾았다면
                aIndex = m[a]; // a의 위치를 aIndex에 저장
            } else { // 못찾았다면 삽입
                aIndex = m.size(); // a의 위치는 m의 맨 끝이 된다.
                m.insert({a, m.size()});
            }
            if (m.find(b) != m.end()){
                bIndex = m[b];
            } else {
                bIndex = m.size();
                m.insert({b, m.size()});
            }
            
            int fa = find(aIndex);
            int fb = find(bIndex);
            
            if (fa != fb){
                groupmembers[fb] += groupmembers[fa];
                uni(aIndex, bIndex);
            }
            
            cout<<groupmembers[find(aIndex)]<<'\n';
            
        }
        
        
    }
}
