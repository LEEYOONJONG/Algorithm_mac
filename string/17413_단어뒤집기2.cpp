#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

int main(){
    char ch;
    stack<char> st;
    queue<char> que;
    bool lessthansign=false;
    while(1){
        ch = cin.get();
        if (!lessthansign){
            if (('a'<=ch && ch<='z') || ('0'<=ch && ch<='9')){ // 큐에 넣기
                st.push(ch);
            }
            else if(ch == ' '){ // 띄어쓰기면 앞에꺼 출력
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                cout<<ch;
            }
            else if (ch=='<'){
                lessthansign = true;
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                cout<<ch;
            }
            else if (ch=='\n' || ch == EOF){
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                break;
            }
        }
        else {
            if (ch == '>'){
                lessthansign = false;
                //출력해야함
                while(!que.empty()){
                    cout<<que.front();
                    que.pop();
                }
                cout<<ch;
            }
            else{
                que.push(ch);
            }
        }
            
    }
    
}
