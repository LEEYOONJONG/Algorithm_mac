#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// N에서 자기 자신을 찾으면서 나타나는 부분일치를 이용해 pi[]를 계산 : pi[i] = N[...i]의 접미사도 되고 접두사도 되는 문자열의 최대길이
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
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a, b;
    cin>>a>>b;
    a += b;
    vector<int> res;
    int calcSize = a.size();
    vector<int> resStr = getPartialMatch(a);
    while(calcSize > 0){
        res.push_back(calcSize);
        calcSize = resStr[calcSize-1];
//        if (calcSize <= 0) break;
    }
    sort(res.begin(), res.end());
    for (int elem:res){
        cout<<elem<< ' ' ;
    }
}
