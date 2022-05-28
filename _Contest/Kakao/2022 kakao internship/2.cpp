#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -1;
    long long sum=0;
    long long partialsum = 0;
    vector<int> queue;
    for (int i=0; i<queue1.size(); i++){
        queue.push_back(queue1[i]);
        sum += queue1[i];
        partialsum += queue1[i];
    }
    for (int i=0; i<queue2.size(); i++){
        queue.push_back(queue2[i]);
        sum += queue2[i];
    }
    sum /= 2; // 비교하고자 하는 값

    int start = 0;
    int end = queue1.size()-1;
    
    while(end <= queue.size()){
        if (partialsum == sum){ // 부분합이 구하고자하는 값과 같다면
            if (answer == -1){ 
                answer = start + (end-(queue1.size()-1));
                break;
            }
        }
        else if (partialsum > sum){
            partialsum -= queue[start];
            start++;
        }
        else { // partialsum < sum
            end++;
            partialsum += queue[end % queue.size()]; // 범위 나가는 것 고려 필요
        }
    }
    return answer;
}
int main()
{
    vector<int> queue1{3, 2, 7, 2};
    vector<int> queue2{4, 6, 5, 1};
    cout<<solution(queue1, queue2);
}