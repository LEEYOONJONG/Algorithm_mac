#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int board[21][21];
int n;
vector<int> teamA;
vector<int> teamB;
int minimum = 9876543210;

void dfs(int person, int cnt){
    if (cnt==n){
        if (teamA.size()==0 || teamB.size()==0) return;
        // teamA
        int sumA=0;
        for (int i=0; i<teamA.size()-1; i++){
            for (int j=i+1; j<teamA.size(); j++){
                int a = teamA[i];
                int b = teamA[j];
                sumA += board[a][b];
                sumA += board[b][a];
            }
        }
        // teamB
        int sumB=0;
        for (int i=0; i<teamB.size()-1; i++){
            for (int j=i+1; j<teamB.size(); j++){
                int a = teamB[i];
                int b = teamB[j];
                sumB += board[a][b];
                sumB += board[b][a];
            }
        }
        if (minimum > abs(sumA-sumB)){
//            cout<<sumA<<", "<<sumB<<endl;
            minimum = min(minimum, abs(sumA - sumB));
        }
        return;
    }
    teamA.push_back(person);
    dfs(person+1, cnt+1);
    teamA.pop_back();
    
    teamB.push_back(person);
    dfs(person+1, cnt+1);
    teamB.pop_back();
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            cin>>board[row][col];
        }
    }
    dfs(0, 0);
    cout<<minimum;
}
