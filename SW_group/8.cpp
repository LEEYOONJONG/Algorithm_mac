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

int fib[45] = {0, 1,};
//int fibonacci(int start){
//
//}

int main(){
    for (int i=2; i<45; i++){
        fib[i] = fib[i-2]+fib[i-1];
    }
    
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        
        int start=-1;
        for (int j=44; j>=0; j--){
            if (fib[j]<=n){
                start = j;
                break;
            }
        }
        int sum=0;
        vector<int> list;
        for (int j=start; j>=0; j--){
            if (sum + fib[j] < n){
                sum += fib[j];
                list.push_back(fib[j]);
            }
            else if (sum + fib[j] == n){
                list.push_back(fib[j]);
                break;
            }
        }
        for (int j = list.size()-1; j>=0; j--){
            cout<<list[j]<< ' ';
        }
        cout<<'\n';
    }
}
