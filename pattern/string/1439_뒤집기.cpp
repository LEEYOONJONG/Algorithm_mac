#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str;
    cin>>str;
    int zero=0, one=0;
    
    if (str[0] == '0') zero++;
    else one++;
    
    for (int i=1; i<str.size(); i++){
        if (str[i-1] == str[i]) continue;
        else{
            if (str[i] == '0') zero++;
            else one++;
        }
    }
    cout<<min(one, zero);
}
