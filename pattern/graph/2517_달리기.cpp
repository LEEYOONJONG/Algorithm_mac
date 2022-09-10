#include <iostream>
#include <queue>
using namespace std;
struct Human {
    int index;
    int speed;
    Human(){};
    Human(int index, int speed) : index(index), speed(speed){};
    bool operator<(const Human next){
        return (speed) < (next.speed); // 오름차순
    }
};
int main(){
    int n; cin>>n;
    priority_queue<Human> pq;
    int input;
    for (int i=1; i<=n; i++){
        cin>>input;
        pq.push(Human(i, input));
    }
    while(!pq.empty()){
        Human human = pq.top();
        pq.pop();
        cout<<human.index<<" "<<human.speed<<endl;
    }
}
