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

int map[21][21];
int dice[6];
void south(){
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = tmp;
}
void north(){
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[2];
    dice[2] = dice[1];
    dice[1] = tmp;
}
void east(){
    int tmp = dice[5];
    dice[5] = dice[2];
    dice[2] = dice[4];
    dice[4] = dice[0];
    dice[0] = tmp;
}
void west(){
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[2];
    dice[2] = dice[5];
    dice[5] = tmp;
}

void copy(int row, int col){
    if (map[row][col] == 0){
        map[row][col] = dice[0];
    }
    else{ // 지도에 0이라면
        dice[0] = map[row][col];
        map[row][col] = 0;
    }
}

int main(){
    int direction[1001];
    int n, m, row, col, k; // n=4행, m=2열
    cin>>n>>m>>row>>col>>k;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    for (int i=0; i<k; i++){
        cin>>direction[i];
        if (direction[i]==1){ //동쪽방향
            if (col+1 < m){
                col += 1; // 방향으로 위치 이동
                east(); // 주사위 위치 변경
                copy(row, col);
                cout<<dice[2]<<'\n';
            }
        }
        else if (direction[i]==2){ // 서쪽
            if (col-1 >= 0){
                col -= 1; // 방향으로 위치 이동
                west(); // 주사위 위치 변경
                copy(row, col);
                cout<<dice[2]<<'\n';
            }
        }
        else if (direction[i]==3){ // 북쪽
            if (row-1 >= 0){
                row -= 1; // 방향으로 위치 이동
                north(); // 주사위 위치 변경
                copy(row, col);
                cout<<dice[2]<<'\n';
            }
        }
        else if (direction[i]==4){ // 남쪽
            if (row+1 < n){
                row += 1; // 방향으로 위치 이동
                south(); // 주사위 위치 변경
                copy(row, col);
                cout<<dice[2]<<'\n';
            }
        }
//        cout<<i<<"번째 : "<<dice[0]<<dice[1]<<dice[2]<<dice[3]<<dice[4]<<dice[5]<<endl;
        
    }
    
    
}
