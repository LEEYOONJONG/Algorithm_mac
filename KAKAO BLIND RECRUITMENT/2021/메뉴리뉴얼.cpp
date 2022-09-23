#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> gOrders;
vector<string> gCourse;

vector<string> solution(vector<string> orders, vector<int> course) {
    gOrders.resize(orders.size());
    gCourse.resize(course.size());
    copy(orders.begin(), orders.end(), gOrders.begin());
    copy(course.begin(), course.end(), gCourse.begin());

    for (int i=0; i<orders.size(); i++){
        string str = orders[i];
        for (int r=0; r<course.size(); r++){
            if (str.size() < course[r]) break;
            //str에서 str.size C r
            

        }
    }

}

int main(){
    // 그냥 orders의 한 원소씩 글자수 n에 대해 nc2, nc3, ..., ncn 글자에 대해 그 밑으로 find


}