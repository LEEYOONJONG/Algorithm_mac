#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int row, col;
bool visited[51][51];
vector<string> board;

int search(int r, int c){
    
    if (r >= row || c >= col || r < 0 || c < 0){
        return 0;
    }
    cout<<r<<", "<<c<<endl;
    if (!visited[r][c]){
        int left =  1 + search(r, c - (board[r][c] -'0'));
        int right = 1 + search(r, c+ (board[r][c]-'0'));
        int up = 1 + search(r - (board[r][c]-'0'), c);
        int down = 1 + search(r + (board[r][c]-'0'), c);
        
        return visited[r][c] = max(max(left, right), max(up, down));
    }
    else { // 방문 했었음
        return visited[r][c];
    }
}
int main(){
    memset(visited, 0, sizeof(visited));
    cin>>row>>col;
    
    for (int i=0; i<row; i++){
        string tmp; cin>>tmp;
        board.push_back(tmp);
    }
    
    cout<<search(0, 0);
}
