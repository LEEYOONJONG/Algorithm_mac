#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


vector<int> getPartialMatch(const string& N){
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if (N[begin + matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) ++begin; // 출발지 증가시킨다.
            else{
                begin += matched - pi[matched-1]; // 이전에 계산한 pi[] 값을 사용
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
int maxOverlap(const string& a, const string& b){
    int alen = a.size(), blen = b.size();
    vector<int> pi = getPartialMatch(b);
    int begin = 0, matched = 0;
    while(begin < alen){
        if (matched < blen && a[begin+matched] == b[matched]){ // 같다면
            ++matched;
            if (begin + matched == alen) return matched; // 최대한 빨리 반환해야
        }
        else {
            if (matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return 0;
}
int main(){
    string input;
    cin>>input;
    string rev = input;
    reverse(rev.begin(), rev.end());
    int res = maxOverlap(input, rev);
    cout<< res+ (input.size()- res)*2;
}
//abababababba
