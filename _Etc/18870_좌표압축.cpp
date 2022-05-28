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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<int> arr;
    vector<int> sorted;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
        sorted.push_back(tmp);
    }
    
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    for(int i=0; i<n; i++){
        cout<<lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin()<< ' ';
    }
    
}
