#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    priority_queue<int> pq;
    for (int i=0; i<n; i++){
        int input; cin>>input;
        if (input != 0) pq.push(input);
        else{
            if (!pq.empty()){
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else cout<<0<<'\n';
        }
    }
}
