#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    
    deque<int> dq;
    string str;
    int x;
    int n;
    cin>>n;
    
    while(n){
        cin>>str;
        n--;
        if (str == "push_front"){
            cin>>x;
            dq.push_front(x);
        }
        else if (str == "push_back"){
            cin>>x;
            dq.push_back(x);
        }
        else if (str == "pop_front"){
            if (dq.empty()){
                cout<<-1<<endl;
                continue;
            }
            cout<<dq.front()<<endl;
            dq.pop_front();
        }
        else if (str == "pop_back"){
            if (dq.empty()){
                cout<<-1<<endl;
                continue;
            }
            cout<<dq.back()<<endl;
            dq.pop_back();
        }
        else if (str == "size"){
            cout<<dq.size()<<endl;
        }
        else if (str == "empty"){
            cout<<dq.empty()<<endl;
        }
        else if (str == "front"){
            if (dq.empty()){
                cout<<-1<<endl;
                continue;
            }
            cout<<dq.front()<<endl;
        }
        else if (str == "back"){
            if (dq.empty()){
                cout<<-1<<endl;
                continue;
            }
            cout<<dq.back()<<endl;
        }
    }
}
