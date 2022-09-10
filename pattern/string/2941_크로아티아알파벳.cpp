#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string input;
    cin >> input;
    
    int sum = 0;
    
    int pos=0;
    int first=0;
    
    while(input.find("c=", pos) != string::npos){
        first++;
        pos = input.find("c=", pos) + 2;
    }
    
    pos = 0;
    int second = 0;
    while(input.find("c-", pos) != string::npos){
        second++;
        pos = input.find("c-", pos) + 2;
    }
    
    pos=0;
    int third=0;
    while(input.find("dz=", pos) != string::npos){
        third++;
        pos = input.find("dz=", pos) + 3;
    }
    
    pos = 0;
    int fourth = 0;
    while(input.find("d-", pos) != string::npos){
        fourth++;
        pos = input.find("d-", pos) + 2;
    }
    
    pos = 0;
    int fifth = 0;
    while(input.find("lj", pos) != string::npos){
        fifth++;
        pos = input.find("lj", pos) + 2;
    }
    
    pos = 0;
    int sixth = 0;
    while(input.find("nj", pos) != string::npos){
        sixth++;
        pos = input.find("nj", pos) + 2;
    }
    
    pos = 0;
    int seventh = 0;
    while(input.find("s=", pos) != string::npos){
        seventh++;
        pos = input.find("s=", pos) + 2;
    }
    
    pos = 0;
    int eighth = 0;
    while(input.find("z=", pos) != string::npos){
        eighth++;
        pos = input.find("z=", pos) + 2;
    }
    eighth -= third;
    
    for (char ch='a'; ch<='z'; ch++){
        pos=0;
        int cnt=0;
        while(input.find(ch, pos) != string::npos){
            cnt++;
//            cout<<input.find(ch, pos)<<", ";
            pos = input.find(ch, pos) + 1;
            
        }
//        cout<<"cnt : "<<cnt<<endl;
        if (ch=='c'){
            cnt -= (first+second);
        }
        else if (ch=='d'){
            cnt -= (third+fourth);
        }
        else if (ch=='z'){
            cnt -= (third+eighth);
        }
        else if (ch=='l'){
            cnt -= fifth;
        }
        else if (ch=='j'){
            cnt -= (fifth+sixth);
        }
        else if (ch=='n'){
            cnt -= sixth;
        }
        else if (ch=='s'){
            cnt -= seventh;
        }
        sum += cnt;
    }
    cout<<sum+first+second+third+fourth+fifth+sixth+seventh+eighth;
    // abcc-c=dd-dz=efghijklljmnnjoprss=tuvzz=dzempersljjlljnjjnnjjdzz=d-z
    // 52
}

