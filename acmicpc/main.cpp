#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    vector<int> x;
    int input;
    for (int i=0; i<n; i++){
        cin>>input;
        x.push_back(input);
        sort(x.begin(), x.end());
        cout<<x[i/2]<<'\n';
    }
}
