#include <iostream>
#include <string.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int m;
    cin>>m;
    int bit = 0;
    for (int i=0; i<m; i++){
        string str;
        int x;
        cin>>str;
//        cout<<str<<", "<<x<<'\n';
        if (str=="add"){
            cin>>x;
            bit |= 1 << x;
        }
        else if (str=="remove"){
            cin>>x;
            bit &= ~ (1 << x);
        }
        else if (str=="check"){
            cin>>x;
            if (bit & (1 << x)){
                cout<<1<<'\n';
            } else {
                cout<<0<<'\n';
            }
        }
        else if (str=="toggle"){
            cin>>x;
            bit ^= 1<< x;
        }
        else if (str == "all"){
            for (int j=1; j<=20; j++){
                bit |= 1 << j;
            }
        }
        else if (str == "empty"){
            for (int j=1; j<=20; j++){
                bit &= ~(1 << j);
            }
        }
        
    }

}
