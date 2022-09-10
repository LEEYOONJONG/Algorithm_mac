#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> adj[50001];
int info[50001];
int entry;
int summit;
bool visited[50001];

int dfs(int node, int maxi, bool visitsummit){ // 1, -1, false
    if (visitsummit){
        return maxi;
    }
    int res = INF;
    for (int i=0; i<adj[node].size(); i++){
        int next = adj[node][i].first;
        int cost = adj[node][i].second;
        if (visited[next]) continue;
        visited[next] = true;
        if (next == entry && !visitsummit) continue; // 봉우리 방문 안했는데 입장에 다시들어가면 안됨.
        if (next != entry && info[next] == 1) continue; // 다른 출입문에 들어가면
        

        if (info[next] == -1){ // 산봉우리라면
            summit = next;
            res = min(res, max(maxi, cost));
        }
        else res = min(res, dfs(next, max(maxi, cost), visitsummit));
        visited[next] = false;
    }
    return res;
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    for (int i=0; i<paths.size(); i++){
        int start = paths[i][0];
        int end = paths[i][1];
        int cost = paths[i][2];
        adj[start].push_back(make_pair(end, cost));
        adj[end].push_back(make_pair(start, cost));
    }
    for (int i=0; i<gates.size(); i++){
        int gate = gates[i];
        info[gate] = 1; // 출입문은 1
    }
    for (int i=0; i<summits.size(); i++){
        int gate = summits[i];
        info[gate] = -1; // 봉우리는 -1
    }

    int ansIntensity = INF;
    int ansSummit = INF;
    for (int i=0; i<gates.size(); i++){
        memset(visited, false, sizeof(visited));
        entry = gates[i];
        int calcIntensity= dfs(entry, -1, false);
        
        if (calcIntensity < ansIntensity){
            ansIntensity = calcIntensity;
            ansSummit = summit;
        }
        if (calcIntensity == ansIntensity){
            ansSummit = min(ansSummit, summit);
        }
    }

    answer.push_back(ansSummit);
    answer.push_back(ansIntensity);
    return answer;
}

int main(){
    int n=7;
    vector<vector<int>> paths {{1, 2, 5}, {1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1}};
    vector<int> gates{3,7};
    vector<int> summits{1,5};
    vector<int> sol = solution(n,paths,gates,summits);
    cout<<sol[0]<<" "<<sol[1]<<endl;
}