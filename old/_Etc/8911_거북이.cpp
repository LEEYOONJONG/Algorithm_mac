#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        string command;
        cin>>command;
        int x=0, y=0;
        int minx=0, maxx=0;
        int miny=0, maxy=0;
        int direction=0; // 0북, 1동, 2남, 3서
        for (int j=0; j<command.size(); j++){
//            cout<<"x : "<<x<<", y : "<<y<<", dir : "<<direction<<endl;
            if (command[j] == 'F'){ // 한 칸 앞으로
                if (direction % 4 == 0){ // 북쪽을 바라본다면
                    y += 1;
                    maxy = max(maxy, y);
                }
                else if (direction % 4 == 1){ // 동쪽을 바라본다면
                    x += 1;
                    maxx = max(maxx, x);
                }
                else if (direction % 4 == 2){ // 남쪽을 바라본다면
                    y -= 1;
                    miny = min(miny, y);
                }
                else if (direction % 4 == 3){ // 서쪽을 바라본다면
                    x -= 1;
                    minx = min(minx, x);
                }
            }
            else if (command[j] == 'B'){ // 한 칸 뒤로
                if (direction % 4 == 0){ // 북쪽을 바라본다면
                    y -= 1;
                    miny = min(miny, y);
                }
                else if (direction % 4 == 1){ // 동쪽을 바라본다면
                    x -= 1;
                    minx = min(minx, x);
                }
                else if (direction % 4 == 2){ // 남쪽을 바라본다면
                    y += 1;
                    maxy = max(maxy, y);
                }
                else if (direction % 4 == 3){ // 서쪽을 바라본다면
                    x += 1;
                    maxx = max(maxx, x);
                }
            }
            else if (command[j] == 'L') direction+= 3;
            else if (command[j] == 'R') direction++;
        }
        cout<<(maxx-minx)*(maxy-miny)<<'\n';
    }
}
