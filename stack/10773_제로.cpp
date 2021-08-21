#include <iostream>
#include <stack>
using namespace std;

int main(){
    int res=0;
    int k;
    stack<int> st;
    cin>>k;
    for (int i=0; i<k; i++){
        int input;
        cin>>input;
        if (input != 0){
            st.push(input);
        }
        else {
            st.pop();
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    cout<<res;
}
