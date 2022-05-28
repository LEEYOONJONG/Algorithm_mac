#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int jipyo[4] = {0, 0, 0, 0}; // RT / CF/ JM / AN
    string answer = "";
    for (int i=0; i<survey.size(); i++){
        int score = choices[i]-4;
        if (survey[i][0] == 'R'){
            jipyo[0] += score;
        } else if (survey[i][0] == 'T'){
            jipyo[0] -= score;
        }
        else if (survey[i][0] == 'C'){
            jipyo[1] += score;
        } else if (survey[i][0] == 'F'){
            jipyo[1] -= score;
        }
        else if (survey[i][0] == 'J'){
            jipyo[2] += score;
        } else if (survey[i][0] == 'M'){
            jipyo[2] -= score;
        }
        else if (survey[i][0] == 'A'){
            jipyo[3] += score;
        } else if (survey[i][0] == 'N'){
            jipyo[3] -= score;
        }
    }
    if (jipyo[0] > 0) answer += "T";
    else answer += "R";
    if (jipyo[1] > 0) answer += "F";
    else answer += "C";
    if (jipyo[2] > 0) answer += "M";
    else answer += "J";
    if (jipyo[3] > 0) answer += "N";
    else answer += "A";
    return answer;
}
int main(){
    vector<string> survey{"TR", "RT", "TR"};
    vector<int> choices{7, 1, 3};
    cout<< solution(survey, choices);
}