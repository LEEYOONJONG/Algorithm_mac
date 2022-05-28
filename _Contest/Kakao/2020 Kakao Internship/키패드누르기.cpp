#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftRow = 3, leftCol=0;
    int rightRow = 3, rightCol = 2;

    for (int i=0; i<numbers.size(); i++){
        int number = numbers[i];
        if (number == 0) number = 11;
        if (number%3 == 1){ // 1, 4, 7
            answer += "L";
            int row = number/3;
            int col = 0;
            leftRow = row;
            leftCol = col;
        }
        else if (number%3 == 0){ // 3, 6, 9
            answer += "R";
            int row = (number-1)/3;
            int col = 2;
            rightRow = row;
            rightCol = col;
        }
        else { // 2 5 8 0
            
            int row = number/3;
            int col = 1;
            int leftDistance = abs(leftRow-row) + abs(leftCol-col);
            int rightDistance = abs(rightRow-row) + abs(rightCol-col);
            cout<<number<< " : "<<leftDistance<<", "<<rightDistance<<endl;
            if (leftDistance<rightDistance){
                leftRow = row;
                leftCol = col;
                answer += "L";
            }
            else if (leftDistance>rightDistance){
                rightRow = row;
                rightCol = col;
                answer += "R";
            }
            else
            {
                if (hand == "left")
                {
                    leftRow = row;
                    leftCol = col;
                    answer += "L";
                }
                else
                {
                    rightRow = row;
                    rightCol = col;
                    answer += "R";
                }
            }
        }
    }

    return answer;
}
int main(){
    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "left";
    cout<<solution(numbers, hand);
}