#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    //    vector<int> arr(n);
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i=0; i<n; i++){
        int input;
        cin>>input;
        if (maxheap.size() == minheap.size()){
            if (maxheap.size()==0){ // 만약 둘다 비어있다면 무조건 maxheap으로 들어가야
                maxheap.push(input);
            }
            else{       // 1개 vs 1개
                if (input > minheap.top()){
                    int minheaptop = minheap.top();
                    minheap.pop();
                    minheap.push(input);
                    maxheap.push(minheaptop);
                }
                else {
                    maxheap.push(input);
                }
            }
        }
        else {
            if (input < maxheap.top()){
                int maxheaptop = maxheap.top();
                maxheap.pop();
                maxheap.push(input);
                minheap.push(maxheaptop);
            }
            else minheap.push(input);
        }
        cout<<maxheap.top()<<'\n';
    }
    
}
