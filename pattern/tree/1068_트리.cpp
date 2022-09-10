#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes[52];
int del;


int printDeletedReefs(int root){ //
    if (nodes[root].size() == 0){ // 더 이상 자식이 없다면
        return 1;   // 그게 리프임
    }
    
    int res=0;
    for (int i=0; i<nodes[root].size(); i++){
        if (nodes[root][i] == del){
            if (nodes[root].size()==1) { // 자식이 지울 대상이라면, 자식이 1개라면
                return 1;   // 현 노드가 리프가 되므로 +1
            }
            else continue;
        }
        res += printDeletedReefs(nodes[root][i]);
    }
    return res;
}
int main(){
    int n;
    
    cin>>n;
    
    int parent;
    for (int i=0; i<n; i++){
        cin>>parent;
        if (parent == -1) nodes[51].push_back(i);
        else nodes[parent].push_back(i);
    }
    cin>>del;
    
    if (nodes[51][0] == del){
        cout<<0;
        return 0;
    }
    cout<<printDeletedReefs(nodes[51][0]);

}

