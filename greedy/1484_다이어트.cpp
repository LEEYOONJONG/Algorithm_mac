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
    int g;
    cin>>g;
    vector<int> vc;
    double rootg = floor(sqrt(g));
    for (int b = 1; b <= rootg; b++){
        for (int a = 1; a<=g/2; a++){
            if (b*(2*a+b)>g) break;
            if (b*(2*a+b)==g){
                vc.push_back(a+b);
            }
        }
    }
    sort(vc.begin(), vc.end());
    if (vc.size()==0){
        cout<<-1;
        return 0;
    }
    for (int i=0; i<vc.size(); i++){
        cout<<vc[i]<<'\n';
    }
}

