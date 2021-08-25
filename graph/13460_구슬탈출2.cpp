#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string.h> // memset
using namespace std;

int main(){
    int n, m;
    char board[12][12];
    memset(board, 0, sizeof(board));
    int redRow, redCol, blueRow, blueCol;
    int dropRow, dropCol;
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>>board[i][j];
            if (board[i][j] == 'R'){
                redRow = i;
                redCol = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B'){
                blueRow = i;
                blueCol = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'O'){
                dropRow = i;
                dropCol = j;
                board[i][j] = '.';
            }
        }
    }
    queue<tuple<int, int, int>> red;
    queue<tuple<int, int, int>> blue;
    red.push(make_tuple(redRow, redCol, 1));
    blue.push(make_tuple(blueRow, blueCol, 1));
    
    
    while(!red.empty()){
        if (get<2>(red.front()) >= 11) break;
        
        //현재
        redRow = get<0>(red.front());
        redCol = get<1>(red.front());
        blueRow = get<0>(blue.front());
        blueCol = get<1>(blue.front());
//        cout<<"Red : "<<redRow<< ", "<<redCol<<" / Blue : "<<blueRow<<", "<<blueCol<<" : "<< get<2>(red.front())<< endl;
        //왼쪽
        int redColIndex = redCol;
        int blueColIndex = blueCol;
        bool redDrop = false, blueDrop = false;
        while(1){
            // 만약 구멍에 떨어진다면,
            if (redRow == dropRow && redColIndex==dropCol){
                redDrop = true;
                redRow = 1;
                redColIndex = 1;
            }
            if (blueRow==dropRow && blueColIndex==dropCol){
                blueDrop = true;
                break;
            }
            
            if (board[redRow][redColIndex-1]=='.' && board[blueRow][blueColIndex-1] == '.'){ // 둘다 움직임
                redColIndex -= 1;
                blueColIndex -= 1;
            }
            else{
                // blue만 움직임
                if (board[blueRow][blueColIndex-1] == '.' && !(redRow == blueRow && redColIndex == blueColIndex-1)){
                    blueColIndex -= 1;
                }
                // red만 움직임
                else if (board[redRow][redColIndex-1] == '.' && !(redRow == blueRow && redColIndex-1 == blueColIndex)){
                    redColIndex -= 1;
                }
                else break;
            }
        }
        if (redDrop == true && blueDrop == false){
            cout<<get<2>(red.front());
            return 0;
        }
        else if (redDrop == false && blueDrop == false){
            // 만약 전과 모두 똑같은 위치가 아닐때만 푸시해야 시간단축
            if (redColIndex != redCol || blueColIndex != blueCol){
                red.push(make_tuple(redRow, redColIndex, get<2>(red.front())+1));
                blue.push(make_tuple(blueRow, blueColIndex, get<2>(blue.front())+1));
            }
        }
        
        //오른쪽
        redRow = get<0>(red.front());
        redCol = get<1>(red.front());
        blueRow = get<0>(blue.front());
        blueCol = get<1>(blue.front());
        redColIndex = redCol;
        blueColIndex = blueCol;
        redDrop = false;
        blueDrop = false;
        while(1){
            // 만약 구멍에 떨어진다면,
            if (redRow == dropRow && redColIndex==dropCol){
                redDrop = true;
                redRow = 1;
                redColIndex = 1;
            }
            if (blueRow==dropRow && blueColIndex==dropCol){
                blueDrop = true;
                break;
            }
            
            if (board[redRow][redColIndex+1]=='.' && board[blueRow][blueColIndex+1] == '.'){ // 둘다 움직임
                redColIndex += 1;
                blueColIndex += 1;
            }
            else{
                // blue만 움직임
                if (board[blueRow][blueColIndex+1] == '.' && !(redRow == blueRow && redColIndex == blueColIndex+1)){
                    blueColIndex += 1;
                }
                // red만 움직임
                else if (board[redRow][redColIndex+1] == '.' && !(redRow == blueRow && redColIndex+1 == blueColIndex)){
                    redColIndex += 1;
                }
                else break;
            }
        }
        if (redDrop == true && blueDrop == false){
            cout<<get<2>(red.front());
            return 0;
        }
        else if (redDrop == false && blueDrop == false){
            if (redColIndex != redCol || blueColIndex != blueCol){
                red.push(make_tuple(redRow, redColIndex, get<2>(red.front())+1));
                blue.push(make_tuple(blueRow, blueColIndex, get<2>(blue.front())+1));
            }
        }
        
        //위쪽
        redRow = get<0>(red.front());
        redCol = get<1>(red.front());
        blueRow = get<0>(blue.front());
        blueCol = get<1>(blue.front());
        int redRowIndex = redRow;
        int blueRowIndex = blueRow;
        redDrop = false;
        blueDrop = false;
        while(1){
            // 만약 구멍에 떨어진다면,
            if (redRowIndex == dropRow && redCol == dropCol){
                redDrop = true;
                redRowIndex = 1;
                redCol = 1;
            }
            if (blueRowIndex==dropRow && blueCol==dropCol){
                blueDrop = true;
                break;
            }
            
            if (board[redRowIndex-1][redCol]=='.' && board[blueRowIndex-1][blueCol] == '.'){ // 둘다 움직임
                redRowIndex -= 1;
                blueRowIndex -= 1;
            }
            else{
                // blue만 움직임
                if (board[blueRowIndex-1][blueCol] == '.' && !(redRowIndex == blueRowIndex-1 && redCol == blueCol)){
                    blueRowIndex -= 1;
                }
                // red만 움직임
                else if (board[redRowIndex-1][redCol] == '.' && !(redRowIndex-1 == blueRowIndex && redCol == blueCol)){
                    redRowIndex -= 1;
                }
                else break;
            }
        }
        if (redDrop == true && blueDrop == false){
            cout<<get<2>(red.front());
            return 0;
        }
        else if (redDrop == false && blueDrop == false){
            if (redRowIndex != redRow || blueRowIndex != blueRow){
                red.push(make_tuple(redRowIndex, redCol, get<2>(red.front())+1));
                blue.push(make_tuple(blueRowIndex, blueCol, get<2>(blue.front())+1));
            }
        }
        
        //아래쪽
        redRow = get<0>(red.front());
        redCol = get<1>(red.front());
        blueRow = get<0>(blue.front());
        blueCol = get<1>(blue.front());
        redRowIndex = redRow;
        blueRowIndex = blueRow;
        redDrop = false;
        blueDrop = false;
        while(1){
            // 만약 구멍에 떨어진다면,
            if (redRowIndex == dropRow && redCol == dropCol){
                redDrop = true;
                redRowIndex = 1;
                redCol = 1;
            }
            if (blueRowIndex==dropRow && blueCol==dropCol){
                blueDrop = true;
                break;
            }
            
            if (board[redRowIndex+1][redCol]=='.' && board[blueRowIndex+1][blueCol] == '.'){ // 둘다 움직임
                redRowIndex += 1;
                blueRowIndex += 1;
            }
            else{
                // blue만 움직임
                if (board[blueRowIndex+1][blueCol] == '.' && !(redRowIndex == blueRowIndex+1 && redCol == blueCol)){
                    blueRowIndex += 1;
                }
                // red만 움직임
                else if (board[redRowIndex+1][redCol] == '.' && !(redRowIndex+1 == blueRowIndex && redCol == blueCol)){
                    redRowIndex += 1;
                }
                else break;
            }
        }
        if (redDrop == true && blueDrop == false){
            cout<<get<2>(red.front());
            return 0;
        }
        else if (redDrop == false && blueDrop == false){
            if (redRowIndex != redRow || blueRowIndex != blueRow){
                red.push(make_tuple(redRowIndex, redCol, get<2>(red.front())+1));
                blue.push(make_tuple(blueRowIndex, blueCol, get<2>(blue.front())+1));
            }
        }
        
        red.pop();
        blue.pop();
    }
    cout<<-1;
    return 0;
}
