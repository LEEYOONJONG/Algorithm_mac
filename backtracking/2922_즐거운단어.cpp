#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

string input;
int checkArr[102];
vector<int> blanklist;
long long sum=0;

int isConsonant(int index){
    if (index<0 || index>=input.size() || checkArr[index] == -1) return -1;
    else if (checkArr[index] == 1) return 1; // 자음
    else return 0; // 모음
}
bool consonantPromising(int index){
    if (!(
            (isConsonant(index-2)==1 && isConsonant(index-1)==1) ||
            (isConsonant(index+1)==1 && isConsonant(index+2)==1) ||
            (isConsonant(index-1)==1 && isConsonant(index+1)==1)
            ))
        return true;
    else return false;
}
bool vowelPromising(int index){
    if (!(
        (isConsonant(index-2)==0 && isConsonant(index-1)==0) ||
        (isConsonant(index+1)==0 && isConsonant(index+2)==0) ||
        (isConsonant(index-1)==0 && isConsonant(index+1)==0)
        ))
        return true;
    else return false;
}
void calc(int index, int consonantCnt, int vowelCnt){
//    if (index >= blanklist.size()) return;
    int blankIdx = blanklist[index];
    
    // 자음 넣기 가능한지
    if (consonantPromising(blankIdx)){
        if (index == blanklist.size()-1){
            if (checkArr[input.size()] == 1){ // L이 있다면
                sum += pow(5, vowelCnt) * pow(21, consonantCnt+1);
            }
            else {
                sum += pow(5, vowelCnt) * (pow(21, consonantCnt+1) - pow(20, consonantCnt+1));
            }
        }
        else {
            checkArr[blankIdx] = 1;
            calc(index+1, consonantCnt+1, vowelCnt);
            checkArr[blankIdx] = -1;
        }
    }
    
    // 모음 넣기 가능한지
    if (vowelPromising(blankIdx)){
        if (index == blanklist.size()-1){
            if (checkArr[input.size()] == 1){
                sum += pow(5, vowelCnt+1) * pow(21, consonantCnt);
            } else {
                sum += pow(5, vowelCnt+1) * (pow(21, consonantCnt) - pow(20, consonantCnt));
            }
        }
            
        else {
            checkArr[blankIdx] = 0;
            calc(index+1, consonantCnt, vowelCnt+1);
            checkArr[blankIdx] = -1;
        }
    }
}

int main(){
    cin>>input;
    
    // check[n]은 기존에 L이 있는지 저장한다.
    // check[0~n-1]은 모음인지 자음인지에 따라
    checkArr[input.size()] = 0;
    for (int i=0; i<input.size(); i++){
        if (input[i] == '_') {
            checkArr[i] = -1; // 빈칸
            blanklist.push_back(i);
        }
        
        else if (input[i] == 'A' ||input[i] == 'E'||input[i] == 'I'||input[i] == 'O'||input[i] == 'U') checkArr[i] = 0; // 모음
        
        else if (input[i] == 'L'){ // L이 있다면
            checkArr[i] = 1;
            checkArr[input.size()] = 1;
        }
        else checkArr[i] = 1; // 자음
    }
    
    calc(0, 0, 0);
    cout<<sum;
}
