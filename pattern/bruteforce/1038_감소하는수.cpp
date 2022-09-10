#include <iostream>
using namespace std;

int n;
int jari;
int cnt;
int arr[100];
bool isFinished = false;
void dfs(int th, int maxiNum){
    if (th==0){
        cnt++; //
        if (cnt==n){ // 내가 찾고자 하는 n번째 수에 도달했다면 출력하고 함수 완전히 종료시켜버림
            for (int i=jari; i>=1; i--){
                cout<<arr[i];
            }
            isFinished = true; // 완전종료 위해
        }
        return;
    }
    if (maxiNum < 0) return; // 다음번 자리 수의 가능한 최댓값이 -1이라면 볼 것도 없이 짤.
    
    for (int i=0; i <= maxiNum; i++){
        arr[th] = i;
        if ((jari != th) && (arr[th+1] <= arr[th])){ // 다음 자리수가 더 크거나 같다면 짤.
            break;
        }
        dfs(th-1, i-1); // 그 다음 자릿수로 이동하며 그 자리수의 최대 가능한 숫자는 현재 자릿수의 수보다 하나 작아야 함.
        if (isFinished) return; //
    }
}


int main(){
    
    // 기본적으로 조합 결괏값을 이용한다.
    // 이를 이용해 구하고자하는 값이 몇번째 자리수를 가지며, 그 자리수의 몇번째 수인지를 알 수 있다.
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n;
    if (n==0){
        cout<<0;
        return 0;
    }
    n++; // 편의상 +1 해줌. ex) 구하는 값이 3번째 수이면 -> 답인 3이 아닌 4이기에.
    
    for (jari=1; jari<=10; jari++){
        // 10 C jari
        long long sum=1;
        for (int i=10; i>10-jari; i--){
            sum *= i;
        }
        for (int j=jari; j>1; j--){
            sum /= j;
        }
        if (n > sum) n -= sum;
        else break;
    }
    // 몇번째 자리 수의 몇번째 수인지 jari / n으로 측정
    
    if (jari == 11 && n >0){ // 연산가능범위 넘어선다면
        cout<<-1;
        return 0;
    }
    dfs(jari, 9); // 첫 jari 수에 올수 있는 수는 일단 0~9까지임.
}
