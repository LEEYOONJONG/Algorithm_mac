#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n, m;
vector<int> st;
int arr[10];
bool visited[10];

void dfs(int num){
    if (st.size()==m){
        for (int i=0; i<st.size(); i++){
            cout<<st[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    if (num>n) return;
//    st.push_back(num);
//    dfs(num);
//    st.pop_back();
    
    st.push_back(num);
    dfs(num);
    
    st.pop_back();
    dfs(num+1);
    
    
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    dfs(1);
}
