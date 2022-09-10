#include <iostream>
#include <string.h>

using namespace std;

struct Trie{
    bool finish;
    
    Trie* next[10];
    
    Trie(){
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
//            cout<<"curr : "<<curr<<endl;
            if (next[curr] == NULL){
                next[curr] = new Trie(); // ABC였다면 BC를 인서트
            }
            next[curr] -> insert(key+1);
        }
    }
    bool consistent(const char* key){
        
        if (*key == '\0') return false; // ex) 91125 vs 911
        // 9 vs 9
        
        if (next[*key-'0'] != NULL){
            // 이미 존재한다면, 재귀적으로 계속 들어감. 단 이게 끝이었다면 not consistent
            if (next[*key-'0']->finish){ // 이게 끝이라면 ex) 911 vs 91125
                return false;   // not consistent
            }
            else {
//                cout<<"consistent : "<<*key<<" - go next"<<endl;
                return next[*key-'0']->consistent(key+1);
            }
        }
        // 1 vs 7
        else{
//            cout<<"consistent : "<<*key<<" - 다름"<<endl;
            return true;
        }
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
            else{
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
