#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;


int n;
vector<vector<int>> adj;

void getEulerCircuit(int here, vector<int>& circuit){
    for (int there = 1; there<=n; there++){
        while(adj[here][there] > 0){
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}


int main(){
    cin>>n;
    adj = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    
    for (int i=1; i<=n; i++){
        int count=0;
        for (int j=1; j<=n; j++){
            cin>>adj[i][j];
            count+= adj[i][j];
        }
        if (count%2 == 1){
            cout<<-1;
            return 0;
        }
    }
    vector<int> circuit;
    getEulerCircuit(1, circuit);
    for (int i=0; i<circuit.size(); i++){
        cout<<circuit[i]<< ' ';
    }
}
