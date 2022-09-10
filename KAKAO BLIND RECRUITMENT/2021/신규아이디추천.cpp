#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string step1 = "";
    // 1
    for (int i=0; i<new_id.length(); i++) {
        if ('A' <= new_id[i] && new_id[i] <= 'Z'){
            step1 += new_id[i] + ('a'-'A');
        } else {
            step1 += new_id[i];
        }
    }

    // 2
    string step2 = "";
    for (int i=0; i<step1.length(); i++) {
        if (('a' <= step1[i] && step1[i] <= 'z') || ('0'<=step1[i] && step1[i]<='9') || (step1[i] == '-' || step1[i] == '_' ||step1[i] =='.')) {
            step2 += step1[i];
        }
    }

    // 3
    string step3 = "";
    for (int i=0; i<step2.length(); i++) {
        if (step2[i]=='.'){
            if (i == step2.length() - 1)
                step3 += '.';
            else
            {
                if (step2[i + 1] == '.')
                {
                    continue;
                }
                else
                    step3 += '.';
            }
        }
        else step3 += step2[i];
    }

    // 4
    if (step3.front() == '.') step3.erase(0, 1);
    if (step3.back() == '.') step3.pop_back();

    // 5
    if (step3.size()==0) step3 = "a";

    // 6
    if (step3.size() >= 16) step3 = step3.substr(0, 15);
    if (step3.back() == '.') step3.pop_back();

    // 7
    while (step3.length() < 3) step3 += step3.back();

    return step3;
}

int main(){
    cout<<solution("abcdefghijklmn.p");
}