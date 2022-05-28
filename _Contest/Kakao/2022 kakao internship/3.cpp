#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Data{
    int al;
    int co;
    int cost;
    Data(int al, int co, int cost):al(al), co(co), cost(cost){};
    bool operator<(const Data d) const {
        if (cost != d.cost) return cost > d.cost; // cost에 대한 오름차순
        else {
            if (al != d.al) return al < d.al; // al에 대한 내림차순
            else return co < d.co;
        }
    }
};
bool isSolved[101];
int visited[5000][5000];
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    priority_queue<Data> pque;
    vector<vector<int>> solved;
    vector<int> alpVector = {1, 0, 1};
    vector<int> copVector = {0, 1, 1};
    solved.push_back(alpVector);
    solved.push_back(copVector);

    // alp, cop이 도달해야 하는 값 설정
    int maxAlp = -1;
    int maxCop = -1;
    

    for (int i=0; i<problems.size(); i++){
        maxAlp = max(maxAlp, problems[i][0]);  // 20
        maxCop = max(maxCop, problems[i][1]);     // 20
    }
    int beforeAl = -1;
    int beforeCo = -1;
    int beforeCost = -1;
    pque.push(Data(alp, cop, 0));
    while(!pque.empty()){
        Data top = pque.top();
        int nowAl = top.al; // 10
        int nowCo = top.co; // 10
        int nowCost = top.cost; // 0
        // cout<<nowAl<<" "<< nowCo<<" "<<nowCost<<endl;
        pque.pop();
        if (visited[nowAl][nowCo] != 0){
            if (visited[nowAl][nowCo] <= nowCost){ // 새로들어온 비용이 오히려 더 크거나 같다면
                continue;
            }
            else visited[nowAl][nowCo] = min(visited[nowAl][nowCo], nowCost);
        }
        else visited[nowAl][nowCo] = nowCost;
        // cost는 큰데, nowAl과 nowCo 모두 전 값들보다 작다면
        
        // 만약 만족한다면 종료
        if (nowAl >= maxAlp && nowCo >= maxCop) return nowCost;

        if (solved.size() != problems.size()+2) { // 아직 다 풀리지 않았다면
            for (int i = 0; i < problems.size(); i++)
            {
                if (isSolved[i])
                    continue; // 이미 풀렸다면 패스
                if (nowAl >= problems[i][0] && nowCo >= problems[i][1])
                {
                    isSolved[i] = true;
                    vector<int> add{problems[i][2], problems[i][3], problems[i][4]};
                    solved.push_back(add);
                }
            }
        } 

        for (int i=0; i<solved.size(); i++){ // 활용 가능한 공부 및 문제들
            int plusAl = solved[i][0];
            int plusCo = solved[i][1];
            int plusCost = solved[i][2];
            if (maxAlp <= nowAl && plusCo == 0) continue; // 만약 al 포인트는 이미 충족되었는데, co 포인트를 충전시켜주지 못한다면 굳이
            if (maxCop <= nowCo && plusAl == 0) continue; 
            pque.push(Data(nowAl+plusAl, nowCo+plusCo, nowCost+plusCost));
        }

           
    }
    return 0;
}

int main(){
    int alp=0, cop=0;
    vector<vector<int>> problems {{0, 0, 4, 4, 2}, {0, 0, 10, 10, 5}, {100, 100, 100, 100, 1000}};
    cout<< solution(alp, cop, problems);
}