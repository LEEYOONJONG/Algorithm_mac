#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 힌트 봤음!!! ㅠ
int main(){
    string input;
    stack<char> st;
    string output;
    cin>>input;
    
    for (int i=0; i<input.size(); i++){
        if ('A'<=input[i] && input[i]<='Z'){
            output += input[i];
        }
        else if (input[i]=='+' || input[i]=='-'){
            while(!st.empty()){
                if (st.top()=='(') break;
                else output += st.top();
                st.pop();
            }
            st.push(input[i]);
        }
        else if (input[i]=='*' || input[i]=='/'){
            while(!st.empty()){
                if (st.top()=='(') break;
                else if (st.top()=='+' || st.top()=='-') break;
                else output += st.top();
                st.pop();
            }
            st.push(input[i]);
        }
        else if (input[i]==')'){
            while(st.top() != '('){
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            st.push(input[i]);
        }
    }
    
    while(!st.empty()){
        output += st.top();
        st.pop();
    }
    cout<<output;

}
