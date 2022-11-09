#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> ssang;
    int counter[501] = {0, };
    int remainPeople = stages.size();
    for (int i=0; i<stages.size(); i++) {
        int stage = stages[i];
        counter[stage]++;
    }

    for (int i=1; i<=N; i++) {
        double ratio;
        if (remainPeople == 0) ratio = 0;
        else ratio = counter[i] / (double)remainPeople;
        ssang.push_back(make_pair(ratio, i));
        remainPeople -= counter[i];
    }

    sort(ssang.begin(), ssang.end(), cmp);
    for (int i=0; i<ssang.size(); i++) { 
        answer.push_back(ssang[i].second);
    }
    return answer;
}

int main() {

    vector<int> stages({4,4,4,4,4});
    vector<int> ret = solution(4, stages);
}