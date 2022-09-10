#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    deque<pair<int, int>> deq; // first : index, second : value
    
    
    int n, l; // 10,0000,0000
    cin>>n>>l;
    for (int i=0; i<n; i++){
        int input;
        cin>>input;
        // 뒤로 갈수록 데이터(.second)는 커져야
        while(!deq.empty() && deq.back().second > input){ // 4 6 10 에 5 들어오면 6, 10 무조건 빼야
            deq.pop_back();
        }
        deq.push_back(make_pair(i, input));
        // L개 제한 지키기
        if (deq.front().first == i-l){ // == 여도 될듯.
            deq.pop_front();
        }
        cout<<deq.front().second<<' ';
    }
}
