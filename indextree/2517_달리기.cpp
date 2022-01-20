#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Data {
    int index;
    int speed;
    Data(){};
    Data(int _index, int _speed): index(_index), speed(_speed) {};
    bool operator<(const Data d) const {
        return speed < d.speed; // 내림차순
    }
};

int tree[1050000];
int B;
int n;

int rangeSum(int l, int r){
    l += B;
    r += B;
    int sum=0;
    while(l<=r){
        if ((l%2 == 1)) sum += tree[l];
        if ((r%2 == 0)) sum += tree[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }
    return sum;
}

void update(int loc, int value){
    loc += B;
    tree[loc] = value;
    while ((loc = loc>>1)){
        tree[loc] = tree[loc*2] + tree[loc*2+1];
    }
}

int main(){
    cin>>n;
    int speed;
    priority_queue<Data> pq;
    
    for (int i=0; i<n; i++){
        cin>>speed;
        pq.push(Data(i, speed));
    }
    
    for (B=1; B<n; B*=2);
    int rank[500001];
    
    for (int i=0; i<n; i++){
        Data data = pq.top();
        pq.pop();
        update(data.index, 1);
        rank[data.index] = rangeSum(0, data.index);
    }
    for (int i=0; i<n; i++){
        cout<<rank[i]<<'\n';
    }
}
