#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str;
    int k;
    cin>> str>> k;
    for (int i=0; i<k; i++){
        int maxpoint=i;
        int maxnum=-1;
        for (int j=i; j<str.size(); j++){
            if (maxnum <= str[j]){
                maxpoint = j;
                maxnum = str[j];
            }
        }
        
        
    }
}
