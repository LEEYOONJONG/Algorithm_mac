#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n, m;

vector<vector<int>> arr;
vector<pair<int, int>> virus;

vector<int> selectedVirus;

bool selected[11];
void dfs(int idx, int cnt){
    if (cnt == m){
        // bfs 드가자

        selectedVirus = vector<int>(0, 0);
        for (int i=0; i<virus.size(); i++){
            if (selected[i] == true) selectedVirus.push_back(i);
        }
        cout<<endl;
        
        
        return;
    }
    for (int i=idx; i<virus.size(); i++){
        if (selected[i] == true) continue;
        selected[i] = true;
        dfs(i, cnt+1);
        selected[i] = false;
    }
    
}

int main(){
    cin >> n>>m;
    arr = vector<vector<int>>(n, vector<int>(n, 0));
    
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >>arr[i][j];
            if (arr[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, 0);
    
    
    
}
