#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int parent[1001];

struct Data{
    int start, end, weight;
    Data(int start, int end, int weight):start(start), end(end), weight(weight){};
    bool operator< (const Data d) const {
        return weight>d.weight;
    }
}; 
 
int find(int a){
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void uni(int a, int b){ //a¸¦ b¿¡
    parent[find(a)] = find(b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>N;
    int weight;
    priority_queue<Data> que;
    for (int i=0; i<N; i++) parent[i] = i;
    for (int row=0; row<N; row++){
        for (int col=0; col<N; col++){
            cin>>weight;
            if (row == col || row>col) continue;
            que.push(Data(row, col, weight));
        }
    }
    
    long long res=0;
    while(!que.empty()){
        Data top = que.top();
        que.pop();
        int start = top.start;
        int end = top.end;
        int weight = top.weight;
        // cout<<"weight : "<<weight<<endl;
        if (find(start) != find(end)){ // dont cycle
            res += weight;
            uni(start, end);
        }
    }
    cout<<res;
    return 0;
}