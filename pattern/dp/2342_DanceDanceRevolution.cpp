#include <iostream>
#include <cmath>
using namespace std;

int command[100001];
int len=0, input;
int dp[5][5][100001];

int costs(int from, int to){
    if (from == to) return 1;
    else if (from == 0) return 2;
    else if (abs(from-to) == 1 || (from==1 && to==4) || (from==4 && to==1)) return 3;
    else if (abs(from-to) == 2) return 4;
    else return 10000000;
}

int ddr(int left, int right, int idx){
    if (dp[left][right][idx] != 0) return dp[left][right][idx];
    
    if (idx == len) return 0;
    // 왼발 사용
    int route1 = costs(left, command[idx]) + ddr(command[idx], right, idx+1);
    // 오른발 사용
    int route2 = costs(right, command[idx]) + ddr(left, command[idx], idx+1);
    return dp[left][right][idx] = min(route1, route2);
}

int main(){
    while(1){
        cin>>input;
        if (input==0) break;
        command[len++] = input;
    }
    cout<< ddr(0, 0, 0);
}
