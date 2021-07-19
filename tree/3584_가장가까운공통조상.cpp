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

vector<int> node[10001];
pair<int, int> calculated[10001];
bool check[50001];
void makeParent(int parent, int depth){ // 1 0
    if (check[parent]== true) return;
    check[parent]=true;
    
    for (int i=0; i<node[parent].size(); i++){
        int child = node[parent][i];
        if (check[child] == true) continue;
        calculated[child].first = parent; // first에는 해당 child의 직속부모
        calculated[child].second = depth+1; // second에는 해당 child의 깊이
//        cout<<"calc["<<child<<"].first = "<<parent<<", calc["<<child<<"].second = "<<depth+1<<endl;;
        makeParent(child, depth+1);
    }
}
void find(int a, int b){
    if (a==b){
        cout<<a<<'\n';
        return;
    }
    int depthA = calculated[a].second;
    int depthB = calculated[b].second;
    
    if (depthA < depthB){ // b가 더 깊다면 b 하나 끌어올리자.
        find(a, calculated[b].first);
    }
    else if (depthA > depthB){ // a가 더 깊다면 a 하나 끌어올리자.
        find(calculated[a].first, b);
    }
    else{
        find(calculated[a].first, calculated[b].first);
    }
    
}

int main(){
    int t;
    cin>>t;
    for (int h=0; h<t; h++){
        memset(check, false, sizeof(check));
        for (int i=0; i<10001; i++){
            /*vector<int> node[10001];
             pair<int, int> calculated[10001];*/
            vector<int>().swap(node[i]);
            pair<int, int>().swap(calculated[i]);
        }
        
        int n;
        cin>>n;
        for (int i=0; i<n-1; i++){
            int a, b;
            cin>>a>>b;
            node[a].push_back(b);
//            node[b].push_back(a);
        }
        makeParent(1, 0);
        int a, b;
        cin>>a>>b;
        find(a, b);
    }
    
}
