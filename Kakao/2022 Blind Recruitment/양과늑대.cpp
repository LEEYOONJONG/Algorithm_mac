#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// 방문해야할 리스트를 파라미터로 넘기기만 계속하면 됨
int dat[18];
vector<int> children[18];
int sheepMax=-1;
void dfs(int now, int sheep, int wolf, vector<int> list){ // 0, 1, 0, [1, 8]
    if (sheep <= wolf) return;
    sheepMax = max(sheepMax, sheep);
    vector<int> newList;
    
    for (int i=0; i<list.size(); i++){
        int next = list[i]; // 1
        newList.resize(list.size());
        copy(list.begin(), list.end(), newList.begin()); // [1, 8]
        newList.erase(remove(newList.begin(), newList.end(), next), newList.end()); // next 지우기 -1
        for (int j=0; j<children[next].size(); j++){ // next 자식 추가 [8 + 2,4]
            newList.push_back(children[next][j]);
        }
        if (dat[next] == 0){ // 양이면
            dfs(next, sheep+1, wolf, newList); //
        }
        else { // 늑대면
            dfs(next, sheep, wolf+1, newList); //
        }
    }
    
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    
    
    for (int i=0; i<info.size(); i++){
        dat[i] = info[i];
    }
    for (int i=0; i<edges.size(); i++){
        int parent = edges[i][0];
        int child = edges[i][1];
        children[parent].push_back(child);
    }
    
    vector<int> list;
    for (int i=0; i<children[0].size(); i++){
        list.push_back(children[0][i]);
    }
    dfs(0, 1, 0, list);
    return sheepMax;
}
