#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
enum Function { NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD, END };
int getInstruction(string str){
    if (str == "NUM") return NUM;
    else if (str == "POP") return POP;
    else if (str == "INV") return INV;
    else if (str == "DUP") return DUP;
    else if (str == "SWP") return SWP;
    else if (str == "ADD") return ADD;
    else if (str == "SUB") return SUB;
    else if (str == "MUL") return MUL;
    else if (str == "DIV") return DIV;
    else if (str == "MOD") return MOD;
    else if (str == "END") return END;
    return 0;
}
void gostack(vector<pair<int, int>> command, int number){
    stack<int> st;
    st.push(number);
    for (int i=0; i<command.size(); i++){
        switch (command[i].first){
            case NUM:
                st.push(command[i].second);
                break;
            case POP:
                if (st.size()==0){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                st.pop();
                break;
            case INV:{
                if (st.size()==0){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int top = st.top();
                st.pop();
                st.push(-top);
                break;
            }
            case DUP:{
                if (st.size()==0){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int top2 = st.top();
                st.push(top2);
                break;
            }
            case SWP:{
                if (st.size()<=1){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first);
                st.push(second);
                break;
            }
            case ADD:{
                if (st.size()<=1){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (abs(first+second) > 1000000000){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                st.push(first+second);
                break;
            }
            case SUB:{
                if (st.size()<=1){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (abs(second-first) > 1000000000){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                st.push(second-first);
                break;
            }
            case MUL:{
                if (st.size()<=1){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                long long multi = (long long)first * (long long)second;
                if (abs(multi)>1000000000){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                st.push(first*second);
                break;
            }
            case DIV:{
                if (st.size()<=1){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (first == 0){
                    cout<<"ERROR"<<'\n';
                    return;
                }
//                int multi = (first/abs(first)) * (second/abs(second));
//                if (multi < 0){
//                    int tmp = abs(second) / abs(first);
//                    st.push(-tmp);
//                }
//                else {
//                    int tmp = abs(second) / abs(first);
//                    st.push(tmp);
//                }
                st.push(second/first);
                break;
            }
            case MOD:{
                if (st.size()<=1){
                    cout<<"ERROR"<<'\n';
                    return;
                }
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (first == 0){
                    cout<<"ERROR"<<'\n';
                    return;
                }
               
                st.push(second%first);
                break;
            }
            
        }
    }
    if (st.size() != 1){
        cout<<"ERROR"<<'\n';
        return;
    }
    cout<<st.top()<<'\n';
    return;
}
int main(){
//    cout<<13/4<<endl;
//    cout<<-13/4<<endl;
//    cout<<13/-4<<endl;
//    cout<<-13/-4<<endl;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(1){
        vector<pair<int, int>> command;
        while(1){
            string input;   cin>>input;
            if (input == "END") break;
            else if (input== "QUIT") return 0;
            int instruction = getInstruction(input);
            switch (instruction) {
            case NUM:
                int number;    cin>>number;
                command.push_back(make_pair(NUM, number));
                break;
            case POP:
                command.push_back(make_pair(POP, -1));
                break;
            case INV:
                command.push_back(make_pair(INV, -1));
                break;
            case DUP:
                command.push_back(make_pair(DUP, -1));
                break;
            case SWP:
                command.push_back(make_pair(SWP, -1));
                break;
            case ADD:
                command.push_back(make_pair(ADD, -1));
                break;
            case SUB:
                command.push_back(make_pair(SUB, -1));
                break;
            case MUL:
                command.push_back(make_pair(MUL, -1));
                break;
            case DIV:
                command.push_back(make_pair(DIV, -1));
                break;
            case MOD:
                command.push_back(make_pair(MOD, -1));
                break;
            default:
                
                break;
            }
        }
        int n;
        cin>>n;
        for (int i=0; i<n; i++){
            int v;
            cin>>v;
//            cout<<v;
            gostack(command, v);
            
        }
        cout<<'\n';
    }
}
