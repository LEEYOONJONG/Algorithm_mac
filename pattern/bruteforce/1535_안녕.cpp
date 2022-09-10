#include <iostream>
#include <algorithm>
using namespace std;

int l[21], j[21];
int n;

int dfs(int human, int health){
    if (human == n) return 0;
    
    int joysum1 = -1, joysum2 = -1;
    
    if (health - l[human] > 0){
        joysum1 = j[human] + dfs(human+1, health-l[human]);
    }
    joysum2 = dfs(human+1, health);
    return max(joysum1, joysum2);
}

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>l[i];
    }
    for (int i=0; i<n; i++){
        cin>>j[i];
    }
    cout<<dfs(0, 100);
}
