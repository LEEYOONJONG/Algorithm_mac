#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        
        int cntStr1[130]={0,};
        int k;
        cin>>k;
        string str1, str2;
        cin>>str1>>str2;
        for (int j=0; j<str1.size(); j++){
            char alphabet = str1[j];
            cntStr1[(int)alphabet]++;
        }
        int chai = str2.size() - str1.size();
        
    }
}
