#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    int cnt=0;
    vector<string> result;
    
    cin>>n>>m;
    vector<string> notseen;
    vector<string> nothear;
    
    string input;
    for (int i=0; i<n; i++){
        cin>>input;
        notseen.push_back(input);
    }
    for (int i=0; i<m; i++){
        cin>>input;
        nothear.push_back(input);
    }
    sort(notseen.begin(), notseen.end());
    sort(nothear.begin(), nothear.end());
        
    int idx1=0, idx2=0;
    while(1){
        if (idx1 >= n || idx2 >= m){
            break;
        }
        string str1 = notseen[idx1];
        string str2 = nothear[idx2];
        int calc = str1.compare(str2);
        // 0보다 작으면 str1 < str2, 크면 str1 > str2
        if (calc < 0){ // str1 < str2
            idx1++;
        }
        else if (calc > 0){ // str1 > str2
            idx2++;
        }
        else {
            cnt++;
            result.push_back(str1);
            idx1++;
            idx2++;
        }
    }
    
    cout<<cnt<<'\n';
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<'\n';
    }
}
