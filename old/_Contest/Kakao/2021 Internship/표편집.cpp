#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/*
"U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.
"D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.
"C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다
"Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.
*/
bool isClear[1000001];

struct Data{
    int before;
    int now;
    int after;
    Data(int before, int now, int after):before(before), now(now), after(after){};
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> st;
    vector<Data> board;
    
    int idx = k;
    for (int i=0; i<n; i++){
        board.push_back(Data(i-1, i, i+1));
    }
    
    for (int i=0; i<cmd.size(); i++){
        string str = cmd[i];
        if (str[0] == 'D'){
            int num = stoi(str.substr(2, str.size()-2));
            while(num--){
                idx = board[idx].after;
            }
        }
        else if (str[0] == 'U'){
            int num = stoi(str.substr(2, str.size()-2));
            while(num--){
                idx = board[idx].before;
            }
        }
        else if (str[0] == 'C'){
            int beforeNode = board[idx].before;
            int afterNode = board[idx].after;
            st.push(idx);
            isClear[idx] = true;
            if (beforeNode >= 0) board[beforeNode].after = board[idx].after;
            if (afterNode < n) { // 맨 아래가 아니라면 // ???
                board[afterNode].before = board[idx].before;
            }
            
            if (afterNode < n) idx = afterNode;
            else idx = beforeNode;////////
        }
        else if (str[0] == 'Z'){
            int now = st.top();
            st.pop();
            isClear[now] = false;
            Data node = board[now];
            if (node.before >= 0){
                // Data beforeNode = board[node.before];
                // beforeNode.after = node.now; 미친거 아님?
                board[node.before].after = node.now;
            }
            if (node.after < n){
                // Data afterNode = board[node.after];
                // afterNode.before = node.now;    // 미친거 아님?
                board[node.after].before = node.now;
            }
        }
    }
    for (int i=0; i<n; i++){
        if (isClear[i]) answer += "X";
        else answer += "O";
    }
   
    
    return answer;
}
