#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int fail[1000001];
string input;
string check;

void makeFail(){
    int checkSize = check.size();
    memset(fail, 0, sizeof(fail));
    int j=0;
    for (int i=1; i<checkSize; i++){
        while(j > 0 && check[i] != check[j]){
            j = fail[j-1];
        }
        if (check[i] == check[j]){
            fail[i] = j+1;
            j++;
        }
    }
    
}
void kmp(){
    int inputSize = input.size();
    int checkSize = check.size();
    int j=0;
    for (int i=0; i<inputSize; i++){
        while(j>0 && input[i] != check[j]){
            j = fail[j-1];
        }
        if (input[i] == check[j]){
            if (j == checkSize-1){
                cout<<1;
                j = fail[j];
                return;
            } else {
                j++;
            }
        }
    }
    cout<<0;
    return;
}

int main(){
    
    cin>>input>>check;
    makeFail();
    kmp();
}
