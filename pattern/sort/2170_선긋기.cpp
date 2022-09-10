#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y){
    if (x.first != y.first) return x.first<y.first;
    else return x.second < y.second;
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio();
    int n;
    cin>>n;
    vector<pair<int, int>> lines(n);
    int x, y;
    for (int i=0; i<n; i++){
        cin>>x>>y;
        lines[i].first = x;
        lines[i].second = y;
    }
    sort(lines.begin(), lines.end());
    
    int sum = lines[0].second - lines[0].first;
    int top = lines[0].second;
    for (int i=1; i<n; i++){
        if (lines[i].first <= top){
            if (lines[i].second >= top){
                sum += lines[i].second - top;
                top = lines[i].second;
            }
        }
        else {
            sum += lines[i].second-lines[i].first;
            top = lines[i].second;
        }
    }
    cout<<sum;
}
