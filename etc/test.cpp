#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int input1 = 1234;
    double input2 = 12.34;
    
    string str1 = to_string(input1);
    string str2 = to_string(input2);
    
    cout<<str1<<endl; // 1234
    cout<<str2<<endl; // 12.340000 <- 유의
    
    return 0;
}
