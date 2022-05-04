#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(10);
    cout << "원래 배열 : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    
    v.erase(remove(v.begin(), v.end(), 3), v.end()); // 원소 3 지우기
    cout << "지운 후 : ";
    for (auto i : v)
        cout << i << " ";
}
