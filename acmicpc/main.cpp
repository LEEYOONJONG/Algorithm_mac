#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    
    vector<vector<string>> variables;
    vector<string> vc;
    vc.push_back("template");
    vc.push_back("{state}");
    variables.push_back(vc);
    vc.clear();
    vc.push_back("state");
    vc.push_back("{template}");
    variables.push_back(vc);
    
    string answer = "";

    for (int i=0; i<variables.size(); i++){
        string from = variables[i][0];  // from : "state"
        string to = variables[i][1];    // to : "{template}"
        if (to[0] == '{'){ // 변수라면
            to = variables[i][1].substr(1, to.size()-2); // to : "template"
            while(1){
                // to : "template"
                cout<<i<<" : from/"<<from<<"/    to/"<<to<<"/"<<endl;
                if (to == from){ // 회전이 되버렸다면
                    cout<<"isSame!!!!"<<endl;
                    variables[i][1] = "{";
                    variables[i][1] += from;
                    variables[i][1] += "}";
                    cout<<variables[i][0]<<" - "<<variables[i][1]<<endl;
                    break;
                }
                bool isFound = false;
                bool isSangsu = false;
                for (int j=0; j<variables.size(); j++){
                    if (variables[j][0] == to){ // "template" == "template"
                        to = variables[j][1]; // to : "{template}"
                        isFound = true;
                        if (to[0] != '{'){ // 상수라면
                            variables[i][1] = to; // 업데이트 완료
                            isSangsu = true;
                        }
                        else{ // 변수라면
                            to = to.substr(1, to.size()-2); // to : "template"
                        }
                        break;
                    }
                }
                if (!isFound){ // 없다면
                    variables[i][1] = "{";
                    variables[i][1] += to;
                    variables[i][1] += "}";
                    break;
                }
                if (isSangsu) break;
            }
        }
    }
    cout<<endl;
    for (int i=0; i<variables.size(); i++){
        string from = variables[i][0];  // from : "a"
        string to = variables[i][1];    // to : "{b}"
        cout<<from<<" -> "<<to <<endl;
    }

    return 0;
}
