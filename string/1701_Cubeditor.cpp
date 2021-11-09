#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int getPartialMatch(const string& N){
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
    // pi 중 가장 큰 수 리턴
    sort(pi.begin(), pi.end());
    return pi[m-1];
}

int main(){
    string input;
    cin>>input;
    
    int tmp;
    int res = 0;
    int inputLen = input.size();
    for (int i=0; i<inputLen; i++){ // i는 문자열의 시작인덱스
        string sub = input.substr(i, inputLen-i);
        tmp = getPartialMatch(sub);
        res = max(res, tmp);
    }
    cout<<res;
    // 시간복잡도 : N^2
}
