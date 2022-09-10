#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=0;
    for (int i=0; i<n; i++){
        string input;
        bool isEnd[26] = {false,};
        bool isGroupword = true;
        cin>>input;
        for (int j=1; j<input.size(); j++){
            // isEnd라면 볼것도 없다
            char nowCh = input[j];
            if (isEnd[nowCh-'a'] == true){
                isGroupword = false;
                break;
            }
            if (input[j-1] != nowCh){
                // 뒤에서 바뀐다면 해당 문자를 isEnd 처리
                char ch = input[j-1];
                isEnd[ch-'a'] = true;
            }
        }
        isGroupword ? cnt++ : cnt+=0 ;
    }
    cout<<cnt;
}
