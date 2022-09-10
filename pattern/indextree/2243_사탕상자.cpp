#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int arr[4200000];
int B;
void update(int loc, int value){
    loc += B-1;
    arr[loc] += value;
    while(loc /= 2){
        arr[loc] += value;
    }
}
int search(int pivot){
    int index=1;
    while(index<B){
        if (pivot <= arr[index*2]){
            index *= 2;
        }
        else{
            pivot -= arr[index*2];
            index = index*2+1;
        }
    }
    update((index-(B-1)), -1);
    return (index-(B-1));
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n; cin>>n;
    for (B=1; B<1000000; B *= 2);
    
    for (int i=0; i<n; i++){
        int a; cin>>a;
        if (a==1){
            int b;
            cin>>b;
            cout<<search(b)<<'\n';
        }
        else if (a == 2){
            int b, c;
            cin>>b>>c;
//            [B-1 + b] += c; //4-1 + 1
            update(b, c);
        }
    }
}
