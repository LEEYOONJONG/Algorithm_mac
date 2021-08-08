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
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        
        int count[201]={0,};
        vector<int> score[201];
        int input[1001]={0,};
        
        int n;
        cin>>n; // n = 15
        for (int j=1; j<=n; j++){
            cin >> input[j];
            count[input[j]]++;
        }
        int scoreIdx = 1;
        for (int j=1; j<=n; j++){
            int team = input[j];
            if (count[team] != 6) continue;
            score[team].push_back(scoreIdx);
            scoreIdx++;
        }
        // 오름차순 정렬
        int minimum=987654321;
        int fifth=-100;
        int victoryTeam;
        
        for (int j=1; j<=200; j++){
            if (score[j].size() != 6) continue;
            sort(score[j].begin(), score[j].end());
            int sum=0;
            for (int k=0; k<4; k++){
                sum += score[j][k];
            }
            if (sum < minimum) {
                minimum = sum;
                fifth = score[j][4];
                victoryTeam = j;
            }
            else if (sum == minimum){ // 점수가 같다면
                if (score[j][4] < fifth){ // 5번째 점수가 작아야지 우승됨.
                    minimum = sum;
                    victoryTeam = j;
                }
            }
        }
        cout<<victoryTeam<<endl;
        
    }
}
