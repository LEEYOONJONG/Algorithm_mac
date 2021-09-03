#include <iostream>
#include <string.h>

using namespace std;

struct Trie {
    bool finish;
    Trie* next[26];
    
    Trie(): finish(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for (int i=0; i<26; i++){
            if (next[i]) delete next[i];
        }
    }
    
    void insert(const char* key){
        if (*key == '\0') finish = true;
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL){
                next[curr] = new Trie();
            }
            next[curr] -> insert(key+1);
        }
    }
    bool find(const char* key){
        if (*key == '\0'){
            if (finish) return true;
            else return false;
        }
        int curr = *key - 'a';
        if (next[curr] == NULL) return false;
        return next[curr] -> find(key+1);
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    Trie tri;

    cin>>n>>m;
    for (int i=0; i<n; i++){
        char input[510];
        cin>>input;
        tri.insert(input);
    }
    int res=0;
    for (int i=0; i<m; i++){
        char test[510];
        cin>>test;
        if (tri.find(test) == true){
            res++;
//            cout<<"**"<<test<<endl;
        }
    }
    cout<<res;
}
