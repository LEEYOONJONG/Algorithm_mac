
#include <iostream>
#include <queue>
using namespace std;

struct Data{
    int node;
    int weight;
    Data(){};
    Data(int node, int weight): node(node), weight(weight){};
    bool operator<(const Data d) const {
        return weight > d.weight; //오름차순
    }
};


int main(){
    priority_queue<Data> pqueue;
    pqueue.push(Data(111, 79));
    pqueue.push(Data(333, 101));
    pqueue.push(Data(222, 21));
    pqueue.push(Data(444, 48));
    pqueue.push(Data(666, 1));
    pqueue.push(Data(555, 1000));
    while(!pqueue.empty()){
        cout<< pqueue.top().weight<<endl;
        pqueue.pop();
    }
}
