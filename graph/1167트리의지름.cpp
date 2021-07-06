#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

vector<int> adj[100001];
vector<int> dis[100001];
bool visited[100001];
stack<int> candidate;
int ans=0, end_point;

void dfs(int start, int length){
    if (visited[start]) return;
    visited[start] = true;
    
    for (int i=0; i<adj[start].size(); i++){
        int another = adj[start][i];
        if (visited[another] == true) continue;

        dfs(another, length+dis[start][i]);

    }
    if (length > ans){
        ans = length;
        end_point = start;
    }
    
}

void dfsAll(){
    
//    while(!candidate.empty()){
//        memset(visited, 0, sizeof(visited));
//        int tmp =  dfs(candidate.top());
//        if (res < tmp){
//            res = tmp;
//        }
//        candidate.pop();
//    }
    memset(visited, 0, sizeof(visited));
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    ans=0;
    dfs(end_point, 0);
    cout<<ans;
}

int main(){
    int v;
    cin>>v;
    for (int i=0; i<v; i++){
        int num, nodenum, dist;
        cin>>num;
        while(1){
            cin>>nodenum;
            if (nodenum==-1) break;
            cin>>dist;
            adj[num].push_back(nodenum);
            dis[num].push_back(dist);
        }
//        if (adj[num].size()==1){
//            candidate.push(num);
//        }
    }
    
    dfsAll();
}
