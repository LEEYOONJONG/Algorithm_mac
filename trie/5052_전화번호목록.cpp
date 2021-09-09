#include <iostream>
#include <string.h>

using namespace std;

struct Trie{
    bool finish;
    
    Trie* next[10];
    
    Trie(): finish(false){
        memset(next, 0, sizeof(next));
        finish = false;
    }
    ~Trie(){
        for (int i=0; i<10; i++){
            if (next[i]) delete next[i];
        }
    }
    void insert(const char* key){ // key가 ABC라면
        if (*key == '\0') finish = true;
        else{
//            finish = false;
            int curr = *key - '0'; // // curr는 A
            if (next[curr] == NULL){
                next[curr] = new Trie(); // ABC였다면 BC를 인서트
            }
            next[curr] -> insert(key+1);
        }
    }
    bool consistent(const char* key){
//        if (*key == '\0'){
//            // 이제 아무것도 찾을게 없고 기존 Trie의 문자열도 종료되었다면
//            if (finish) return true;
//            // 이제 아무것도 찾을게 없는데 종료 안됨 ex. ABC 에서 AB를 탐색한다면
//            else return false;
//        }
//        int curr = *key - '0'; // 문자열의 맨 앞 문자
//        if (next[curr] == NULL) return false; //
//        return next[curr] -> find(key+1);
        if (*key == '\0'){
            return true;
        }
        // 뒤에 더 남아있지만 이미 목록에 존재한다면
        if (*(key+1) != '\0' && finish == true) return false;
        
        int curr = *key - '0';
        // 이미 끝났는데 목록에 뒤이어 남아있는 문자가 있다면
       if (*(key+1) == '\0' && next[curr] != NULL) return false;
        return next[curr] -> consistent(key+1);
    }
};

int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        Trie tri;
        bool isConsistent = true;
        for (int j=0; j<n; j++){
            char input[50];
            cin>>input;
            
            if (j==0) tri.insert(input);
            else if (j != 0){
                if (tri.consistent(input) == true) tri.insert(input);
                else {
                    isConsistent = false;
                }
            }
        }
        if (isConsistent == true){
            cout<<"YES"<<'\n';
        } else {
            cout<<"NO"<<'\n';
        }
    }
}
