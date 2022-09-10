#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    while(1){
        stack<char> stack;
        bool stable=true;
        string str;
        getline(cin, str);
        if (str == ".") break;
        for (int i=0; i<str.size(); i++){
            if (str[i] == '(' || str[i] == '[') stack.push(str[i]);
            else if (str[i] == ')'){
                if (stack.empty()){
                    stable = false;
                    break;
                }
                else if (stack.top() != '('){
                    stable = false;
                    break;
                }
                else {
                    stack.pop();
                }
            }
            else if (str[i] == ']'){
                if (stack.empty()){
                    stable = false;
                    break;
                }
                else if (stack.top() != '['){
                    stable = false;
                    break;
                }
                else {
                    stack.pop();
                }
            }
        }
        if (!stack.empty()) cout<<"no"<<endl;
        else if (stable == false) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
        
    }
}
