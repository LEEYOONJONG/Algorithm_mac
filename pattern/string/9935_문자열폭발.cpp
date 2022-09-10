#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

bool trash[1000001];

int main(){
    string input, check;
    cin>>input>>check;
    vector<char> answer;
    int lenInput = input.length();
    int lenCheck = check.length();
    for (int i=0; i<lenInput; i++){
        answer.push_back(input[i]);
        
        int lenAnswer = answer.size();
        bool explode = true;
        for (int j=0; j<lenCheck; j++){
            if (answer[lenAnswer-1-j] != check[lenCheck-1-j]){ // 지금껏 누적된 답의 끝부분부터 = check의 끝부분부터
                explode = false;
                break;
            }
        }
        if (explode){
            for (int j=0; j<lenCheck; j++){
                answer.pop_back();
            }
        }
        
    }
    if (answer.size()==0){
        cout<<"FRULA";
        return 0;
    }
    for (int i=0; i<answer.size(); i++){
        cout<<answer[i];
    }
}
