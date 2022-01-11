#include <iostream>
using namespace std;

int hIndex, cIndex;
int hrow[5001];
int hcol[5001];
int crow[14];
int ccol[14];
int n, m;

int top;
int selected[14];
void backtracking(int start){
    if (top == m){
        for (int i=0; i<m; i++) cout<<crow[i]<<", "<<ccol[i]<<endl;
        cout<<"---"<<endl;
        return;
    }
    for (int i=start; i<cIndex; i++){
        selected[top++] = i;
        backtracking(i+1);
        top--;
    }
    
}

int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int input; cin>>input;
            if (input==1){
                hrow[hIndex] = i;
                hcol[hIndex] = j;
                hIndex++;
            }
            else if (input==2){
                crow[cIndex] = i;
                ccol[cIndex] = j;
                cIndex++;
            }
        }
    }
    
    backtracking(0);
    
    
}
