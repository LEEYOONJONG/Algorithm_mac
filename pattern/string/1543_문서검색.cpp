#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string doc;
    getline(cin,doc);
    string input;
    getline(cin,input);
    
    int cnt=0;
    if (doc.size() < input.size()){
        cout<<0;
        return 0;
    }
    for (int i=0; i<=doc.size()-input.size(); i++){
        if (doc.substr(i, input.size()) == input){

            cnt++;
            i += input.size()-1;
        }
    }
    cout<<cnt;
}
