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
    
   
    
    
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int maximumS=-1;
        
        vector<pair<int, int>> vc;
        int n;
        cin>>n;
        bool** coord;
        coord = new bool*[20001];
        for (int init=0; init<20001; init++){
            coord[init] = new bool[20001];
        }
        for (int q=0; q<20001; q++) for (int w=0; w<20001; w++) coord[q][w] = false;
       
        for (int j=0; j<n; j++){
            int x, y;
            cin>>x>>y;
            int newx = x+10000, newy = y+10000;
            vc.push_back(make_pair(newx, newy));
            coord[newx][newy]=true;
        }
        for (int j=0; j<vc.size(); j++){
            for (int k=0; k<vc.size(); k++){
                if (i==k) continue;
                int x1 = vc[j].first;
                int y1 = vc[j].second;
                int x2 = vc[k].first;
                int y2 = vc[k].second;
                
                int deltaX = x2 - x1;
                int deltaY = y2 - y1;
                
                // 첫번째 직사각형 후보
                int rect1_x1 = x1+deltaY;
                int rect1_y1 = y1-deltaX;
                int rect1_x2 = x2+deltaY;
                int rect1_y2 = y2-deltaX;
                if (rect1_x1 >=0 && rect1_y1 >=0 && rect1_x2 >=0 && rect1_y2 >=0){
                    if (coord[rect1_x1][rect1_y1] == true && coord[rect1_x2][rect1_y2] == true){
                        int newS = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                        if (maximumS < newS) maximumS = newS;
                    }
                }
                // 두번째 직사각형 후보
                int rect2_x1 = x1-deltaY;
                int rect2_y1 = y1+deltaX;
                int rect2_x2 = x2-deltaY;
                int rect2_y2 = y2+deltaX;
                if (rect2_x1 >=0 && rect2_y1 >=0 && rect2_x2 >=0 && rect2_y2 >=0){
                    if (coord[rect2_x1][rect2_y1] == true && coord[rect2_x2][rect2_y2] == true){
                        int newS = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                        if (maximumS < newS) maximumS = newS;
                    }
                }
            }
        }
        cout<<maximumS<<'\n';
        for (int init=0; init<20001; init++){
            delete[] coord[init];
        }
        delete coord;
    }
}
