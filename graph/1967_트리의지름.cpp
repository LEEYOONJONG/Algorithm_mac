#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> node[10010];

int childmax[10010]={0,};

int childMax(int start){ // start부터 최대값
    if (childmax[start] != 0) return childmax[start];

    int maximum = 0;
    for (int i=0; i<node[start].size(); i++){
        maximum = max(maximum, node[start][i].second + childMax(node[start][i].first));
    }

    return childmax[start] = maximum;
}
int calc(int start){
    if (node[start].size()==0) return 0;
    
    // 1. start가 루트가 되는 법
    priority_queue<int> pq;
    for (int i=0; i<node[start].size(); i++){
        int tmp = node[start][i].second + childMax(node[start][i].first);
        pq.push(tmp);
    }
    int res1;
    if (pq.size()<=1){
        res1 = 0;
    }
    else{
        res1 = pq.top();
        pq.pop();
        res1 += pq.top();
    }
    // 2. start의 자식이 루트가 되었을때의 값
    int res2=0;
    for (int i=0; i<node[start].size(); i++){
        res2 = max(res2, calc(node[start][i].first));
    }
    
    
    return max(childMax(1), max(res1, res2));
    
}
int main(){
    int n;
    cin >> n;
    
    for (int i=0; i<n-1; i++){
        int a, b, w;
        cin>>a>>b>>w;
        node[a].push_back(make_pair(b, w));
    }
    cout<<calc(1)<<endl;
}
