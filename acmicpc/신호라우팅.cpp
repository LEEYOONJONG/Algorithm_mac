#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <cstdlib>
using namespace std;

int n, m; //행 열
string arr[1001];
vector<vector<int>> dp;

bool worm(int rowpivot, int colpivot, int len){
    // 여기서 dp 처리
    if (rowpivot+len>=n || colpivot+len>=m) return false;
    for (int i=rowpivot; i<=rowpivot+len; i++){
        if (arr[i][colpivot+len] == '0') return false;
    }
    for (int i=colpivot; i<=colpivot+len; i++){
        if (arr[rowpivot+len][i] == '0') return false;
    }
    return true;
}

int bigsquare(int rowStart, int colStart, int len){
//    cout<<"진입"<<rowStart<<", "<<colStart<<", "<<len<<endl;
    if (rowStart+len >= n || colStart+len>=m) return 0; // 범위 넘어가면 0 리턴
    if (arr[rowStart][colStart] == '0') return 0;
    
    if (worm(rowStart, colStart, len) == true){
        return 1+bigsquare(rowStart, colStart, len+1);
    }
    else {
        return 0;
    }
}

int main(){
    
    cin>>n>>m;
    
    dp = vector<vector<int>>(n, vector<int>(m, 1));
    int maximum=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int temp = bigsquare(i, j, 0);
            if (maximum < temp){
                maximum = temp;
//                cout<<"* i : "<<i<<", j : "<<j<<", temp : "<<temp<<endl;
            }
        }
    }
    cout<<maximum*maximum;
}
