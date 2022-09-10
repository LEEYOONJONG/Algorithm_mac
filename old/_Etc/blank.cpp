#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
using namespace std;
int temp = 0;

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        temp += a[i] - '0';
    }
    cout<<temp;
    return 0;
}
