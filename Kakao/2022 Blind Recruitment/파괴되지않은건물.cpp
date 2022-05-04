#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 2차원 누적합 문제 -> IMOS 알고리즘
int dp[1002][1002];
int differential[1002][1002];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for (int i=0; i<skill.size(); i++){
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int num;
        if (skill[i][0] == 1) num = -skill[i][5];
        else num = skill[i][5];
        
        dp[r1][c1] += num;
        dp[r1][c2+1] += -num;
        dp[r2+1][c1] += -num;
        dp[r2+1][c2+1] += num;
    }
    // horizontal prefix sum
    for (int row=0; row<board.size(); row++){
        for (int col=0; col<board[0].size(); col++){
            if (col!=0) dp[row][col] = dp[row][col-1] + dp[row][col];
        }
    }
    
    // vertical prefix sum
    for (int col=0; col<board[0].size(); col++){
        for (int row=0; row<board.size(); row++){
            if (row!=0) dp[row][col] = dp[row-1][col] + dp[row][col];
        }
    }
    
    for (int row=0; row<board.size(); row++){
        for (int col=0; col<board[0].size(); col++){
            if (dp[row][col]+board[row][col] > 0) answer++;
        }
    }
    return answer;
}
