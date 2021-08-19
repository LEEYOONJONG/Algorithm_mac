#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    for (int i=0; i<t; i++){
        string str;
        int huimun = 0;
        cin>>str;
        // str이 짝수개라면
        int fp = 0;
        int sp = str.size()-1;
        int trial=0;
        int originfp, originsp;
        while(fp<=sp){
            if (str[fp] == str[sp]){
                fp++;
                sp--;
            }
            else{ // 다르다면
                if (huimun == 0){
                    if (trial==0){ //지금까지는 다 같았다면,
                        // 저장
                        originfp=fp;
                        originsp=sp;
                        //fp 그대로
                        sp--;
                        huimun = 1;
                        trial=1;
                    }
                }
                else if (huimun == 1){
                    if (trial==1){
                        trial=2;
                        fp = originfp;
                        sp = originsp;
                        fp++;
                        //이번엔 sp 그대로
                    }
                    else if (trial == 2){
                        huimun = 2;
                        break;
                    }
                }
            }
        }
        cout<<huimun<<'\n';
    }
}
