#include <iostream>
#include <algorithm>
using namespace std;

struct Data{
    int price;
    int count;
};
bool compare(const Data& d1, const Data& d2){
    return d1.price < d2.price; // price의 오름차순
}

int dp[101][10001];
int main(){
    int t;
    int k;
    int p, n;
    cin>>t>>k;
    Data coin[101];
    for (int i=0; i<k; i++){
        cin>>p>>n;
        coin[i].price = p;
        coin[i].count = n;
    }
    sort(coin, coin+k, compare);
    
    dp[0][0] = 1;
    int coinSum=0;
    for (int row=1; row<=k; row++){
        int price = coin[row-1].price;
        int maxCount = coin[row-1].count;
        coinSum += price*maxCount;
        for (int col=0; col<=t; col++){
            if (col > coinSum) break;
            // price 동전이 더 없다면
            if (col >= price*(maxCount+1)) dp[row][col] =dp[row-1][col] + dp[row][col-price] - 1;
            else{
                if (col-price< 0) dp[row][col] = dp[row-1][col];
                else dp[row][col] = dp[row-1][col] + dp[row][col-price];
            }
        }
    }
    cout<<dp[k][t];
}
