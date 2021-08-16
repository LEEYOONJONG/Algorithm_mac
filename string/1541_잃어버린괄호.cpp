#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
//    cout<<(int)'0'<<endl;
    char ch;
    int res = 0;
    int sum = 0;
    bool start = true;
    bool minusExist = false;
    while(1){
        ch = cin.get();
        if ('0'<= ch && ch<= '9'){
            if (start){
                sum = ch - '0';// sum 초기화
                start = false;
            }
            else {
                sum*=10;
                sum += ch - '0';
            }
        }
        else if (ch == '+' && !minusExist){
            res += sum;
            start = true;
        }
        else if (ch == '+' && minusExist){
            res -= sum;
            start = true;
        }
        else if (ch == '-' && !minusExist){
            res += sum;
            minusExist = true;
            start = true;
        }
        else if (ch == '-' && minusExist){
            res -= sum;
            start = true;
        }
        else if (ch == '\n' || ch == EOF){
            if (minusExist){
                res -= sum;
                break;
            }
            else{
                res += sum;
                break;
            }
        }
        
    }
    cout<<res;
}
