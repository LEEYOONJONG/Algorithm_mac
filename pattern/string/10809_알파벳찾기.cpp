#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string input;
    cin>>input;
    
    for (int i='a'; i<='z'; i++){
        if (input.find(char(i)) != string::npos){
            cout<<input.find(char(i))<<' ';
        }
        else cout<<-1<<' ';
    }
}
