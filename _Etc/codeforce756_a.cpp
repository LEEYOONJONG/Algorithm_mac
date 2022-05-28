#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        string input;
        cin>>input;
        bool evenFound = false;
        if (int(input[input.size()-1] - '0') % 2 == 0) cout<<0<<'\n';
        else if (int(input[0] - '0') % 2 == 0) cout<<1<<'\n';
        else {
            for (int j=1; j<input.size()-1; j++){
                if (int(input[j]-'0') % 2 == 0){
                    cout<<2<<'\n';
                    evenFound = true;
                    break;
                }
            }
            if (!evenFound) cout<<-1<<'\n';
        }
    }
}
