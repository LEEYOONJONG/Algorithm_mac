#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, Top;
int arr[100];
int D[100]; // 구성된 순열
vector<int> anslist;
bool Visit[100];
void printD()
{
    int sum=0;
    for(int i=0; i<k; i++){
//        printf("%d ", D[i]);
//        D[i]가 123 이라면 미리 sum에 1000을 곱하고 시작해야.
        int temp=1;
        for (int j=1; temp <= D[i]; temp *= 10);
        sum *= temp;
        sum += D[i];
    }
//    cout<<"** "<<sum<<endl;
    vector<int>::iterator it;
    it = find(anslist.begin(), anslist.end(), sum);
    if (it == anslist.end()){ // 없다면
//        cout<<"* "<<sum<<endl;
        anslist.push_back(sum);
    }
//    printf("\n");
}

void backtracking()
{
    if(Top == k)
    {
        printD();
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(!Visit[i])
        {
            Visit[i] = true;
            D[Top++] = arr[i];
            backtracking();
            Top--;
            Visit[i] = false;
        }
    }
}

int main(){
    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>arr[i];
    Top =0;
    backtracking();
    cout<<anslist.size();
}
