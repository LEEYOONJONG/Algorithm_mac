#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> tree;
bool check(int mid){
    long long sum=0;
    for (int i=0; i<n; i++){
        sum += max((long long)0, (long long)(tree[i] - mid));
    }
    return sum >= m;
}

int main(){

    cin>>n>>m;
    tree = vector<int>(n);
    int mintree=0, maxtree=0;
    for(int i=0; i<n; i++){
        cin>>tree[i];
//        mintree = min(mintree, tree[i]);
        maxtree = max(maxtree, tree[i]);
    }
    
    int midtree;
    while(mintree + 1 < maxtree){
        midtree = (mintree+maxtree) / 2;
        if (check(midtree)) mintree = midtree;
        else maxtree = midtree;
    }
    cout<<mintree<<endl;
    return 0;
}
