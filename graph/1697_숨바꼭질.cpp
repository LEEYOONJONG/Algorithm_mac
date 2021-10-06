#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    bool visited[200002]={false,};
    queue<int> que;
    int cnt=0;
    cin>>n>>k;
    
    que.push(n);
    bool found=false;
    while(!found){
        int queSize = que.size();
        for (int i=0; i<queSize; i++){
            int top = que.front();
//            cout<<top<<", ";
            if (top == k){
                found = true;
                cout<<cnt;
                break;
            }
            visited[top] = true;
            que.pop();
            
            // -1
            if (top>=1)
                if (!visited[top-1]) que.push(top-1);
            
            // +1
            if (top<100000)
                if (!visited[top+1]) que.push(top+1);
            // *2
            if (top<=70000)
                if (!visited[top*2]) que.push(top*2);
        }
//        cout<<" --> "<<cnt<<endl;
        cnt++;
    }
}
