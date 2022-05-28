#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v = { 1, 3, 4, 4, 7, 10, 10, 10, 13, 17 };
    sort(v.begin(), v.end());
    cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;
    cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 8) - v.begin() << endl;
    cout << "upper_bound: " << upper_bound(v.begin(), v.end(), 8) - v.begin() << endl;
    return 0;
}
