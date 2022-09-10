#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Data{
    int age;
    string name;
    int idx;
    Data(int age, string name, int idx):age(age), name(name), idx(idx){};
    bool operator<(const Data d) const{
        if (age != d.age) return age > d.age; // 오름차순
        else return idx > d.idx;
    }
};

int main(){
    int n; cin>>n;
    priority_queue<Data> pq;
    int inputAge; 
    string inputName;
    for (int i=0; i<n; i++){
        cin>>inputAge>>inputName;
        pq.push(Data(inputAge, inputName, i));
    }
    while(!pq.empty()){
        Data top = pq.top();
        pq.pop();
        cout<<top.age<<" "<<top.name<<'\n';
    }
}