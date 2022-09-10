#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[101][101];
bool visited[101][101];
int cnt=0;
int h, w;

struct Coord{
    int row;
    int col;
    Coord(int row, int col):row(row), col(col) {}
};
queue<Coord> que;
bool keys[26];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void calc(int row, int col){
//    cout<<"탐색 : "<<row<<", "<<col<<endl;
    if (row >= h || row<0 || col<0 || col>=w) return;
    if (visited[row][col]) return;
    if (map[row][col] == '*') return;
    
    visited[row][col] = true;
    
    if ('a' <= map[row][col]  && map[row][col] <= 'z'){ // 일단 키인지 체크
        int idx = map[row][col] - 'a';
        keys[idx] = true;
        for (int i=0; i<4; i++) que.push(Coord(row+dr[i], col+dc[i]));
    }
    else if (map[row][col] == '.'){ // .이면 상하좌우 방향 진행
        for (int i=0; i<4; i++) que.push(Coord(row+dr[i], col+dc[i]));
    }
    else if (map[row][col] == '$') {
        cnt++;
        for (int i=0; i<4; i++) que.push(Coord(row+dr[i], col+dc[i]));
    }
    else { // 대문자라면
        int idx = map[row][col] - 'A';
        if (keys[idx]){ //키가 있다면
            for (int i=0; i<4; i++) que.push(Coord(row+dr[i], col+dc[i]));
        }
        else{ // 키가 없다면 -> 다시 넣고 때를 기다린다.
            visited[row][col] = false;
            que.push(Coord(row, col));
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    for (int tc=0; tc<t; tc++){
        cnt = 0;
        que = queue<Coord>();
        
        memset(visited, false, sizeof(visited));
        memset(keys, false, sizeof(keys));
        cin>>h>>w;
        
        for (int row=0; row<h; row++){
            for (int col=0; col<w; col++){
                cin>>map[row][col];
                // 만약 벽이 아니라면 큐에 일단 넣는다.
                if ((row==0 || row==h-1 || col==0 || col==w-1) && map[row][col] != '*'){
                    que.push(Coord(row, col));
                }
            }
        }
        string str; cin>>str;
        if (str[0] != '0'){
            for (int i=0; i<str.size(); i++){
                int idx = str[i] - 'a';
                keys[idx] = true;
            }
        }
        // 이제 que를 하나씩 방문하자.
        
        while(!que.empty()){
            Coord top = que.front();
            que.pop();
            calc(top.row, top.col);
            
            // 모두 : queue에 있는 원소 전체가 대문자인데 && 키가 없다
            queue<Coord> tempque = que;
            bool cantMore = true;
            while(!tempque.empty()){
                Coord top = tempque.front();
                tempque.pop();
                int idx = map[top.row][top.col] - 'A';
                if ('A' <= map[top.row][top.col] && map[top.row][top.col] <= 'Z' && keys[idx] == false) continue;
                else {
                    cantMore = false;
                    break;
                }
            }
            if (cantMore) break;
        }
        cout<<cnt<<'\n';
        
        
    }
}
