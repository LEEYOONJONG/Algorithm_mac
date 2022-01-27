#include <iostream>
#include <algorithm>
using namespace std;

int n;
int card[500001];

int search(int x){
    // FFFTTTTT
    int start = 0;
    int end = n-1;
    int found = 0;
    while(card[start+1] < card[end]){
        int mid = (start+end)/2;
        if (x < card[mid]){
            end = mid;
        }
        else if (x > card[mid]){
            start = mid;
        }
        else {
            found = true;
            break;
        }
    }
    return found || (x == card[start+1]) || (x==card[start]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>card[i];
    }
    sort(card, card+n);
    
    int m; cin>>m;
    
    for (int i=0; i<m; i++){
        int input; cin>>input;
        cout<<search(input)<< ' ';
    }
}
