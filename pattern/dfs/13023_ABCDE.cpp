#include <iostream>
#include <vector>
using namespace std;

bool visited[2001];

int n, m;
vector<int> friends[2001];
int check;

void dfs(int start, int ssang){
    if (ssang == 4){
        check = 1;
        return;
    }
    for (int i=0; i<friends[start].size(); i++){
        if (check==1) return;
        
        int dest = friends[start][i];
        if (visited[dest]) continue;
        
        visited[dest] = true;
        dfs(dest, ssang+1);
        visited[dest] = false;
        
    }
}
int main(){
    cin>>n>>m;
    
    int a, b;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);

    }
    for (int i=0; i<n; i++){
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
        if (check==1){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
