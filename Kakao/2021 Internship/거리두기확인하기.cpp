#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

vector<string> maps;

int dh[4] = {-1, 0, 1, 0};
int dv[4] = {0, 1, 0, -1};

int nowRow, nowCol;

int finalCheck(int row, int col){
    if (row<0 || row >= 5 || col<0 || col>=5) return 0;
    for (int i=0; i<4; i++){
        int nextRow = row+dv[i];
        int nextCol = col+dh[i];
        if (nextRow<0 || nextRow >= 5 || nextCol<0 || nextCol>= 5) continue;
        if (nextRow == nowRow && nextCol == nowCol) continue;
        if (maps[nextRow][nextCol] == 'P') return 1;
    }
    return 0;
}
int neighborCheck(int row, int col){ // maps[row][col] = P 일때
    if (row<0 || row >= 5 || col<0 || col>=5) return 0;
    for (int i=0; i<4; i++){
        int nextRow = row+dv[i];
        int nextCol = col+dh[i];
        if (nextRow<0 || nextRow >= 5 || nextCol<0 || nextCol>=5) continue;
        if (maps[nextRow][nextCol] == 'P') return 1;
        else if (maps[nextRow][nextCol] == 'X') continue;
        else if (maps[nextRow][nextCol] == 'O'){
            int res = finalCheck(nextRow, nextCol);
            if (res == 1) return 1;
        }
    }
    return 0;
}
int circulate(){ // 전체 체크
    for (int row=0; row<5; row++){
        for (int col=0; col<5; col++){
            if (maps[row][col] == 'P'){
                nowRow = row; // 중복제거 위해
                nowCol = col;
                int res = neighborCheck(row, col);
                if (res == 1) return 0;
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i=0; i<places.size(); i++){
        maps.clear();
        maps.resize(places[i].size());
        copy(places[i].begin(), places[i].end(), maps.begin());
        answer.push_back(circulate());
    }
    
    return answer;
}
