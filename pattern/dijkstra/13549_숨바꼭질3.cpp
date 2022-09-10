#include <queue>
#include <iostream>

using namespace std;

struct Data{
    int loc;
    int time;
    bool operator<(const Data d) const{
        return d.time < time;
    }
    Data(int loc, int time):loc(loc), time(time){};
};
bool visited[200000];
int n, k;
int main(){
    cin>>n>>k;
    priority_queue<Data> pqueue;
    pqueue.push(Data(n, 0));
    
    while(!pqueue.empty()){
        Data top = pqueue.top();
        pqueue.pop();
        int topLoc = top.loc;
        int topTime = top.time;
        if (topLoc == k){
            cout<<topTime;
            break;
        }
        visited[topLoc] = true;
        
        if ((topLoc + (topLoc*2)) / 2 <= k && topLoc != 0 && !visited[topLoc*2]) {
            pqueue.push(Data(topLoc*2, topTime));
        }
        if (topLoc >= 1 && !visited[topLoc-1]){
            pqueue.push(Data(topLoc-1, topTime+1));
        }
        if (!visited[topLoc+1]) pqueue.push(Data(topLoc+1, topTime+1));
    }
}
