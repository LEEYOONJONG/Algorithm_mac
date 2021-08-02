#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    int books[10001];
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>books[i];
    }
    sort(books, books+n);
    
    int negativeMax = -1;
    int positiveMin = -1;
    for (int i=0; i<n-1; i++){
        if (books[i] < 0 && 0 < books[i+1]){
            negativeMax = i;
            positiveMin = i+1;
        }
    }
    bool isPositiveAll;
    if (books[0] > 0) isPositiveAll = true;
    else isPositiveAll = false;
    for (int i=0; i<n; i++){
        if (books[i] < 0) books[i] = -books[i];
    }

    if (negativeMax != -1){ // 양, 음 모두 존재
        // 음수 -> 양수
        int namuji = (negativeMax - 0 + 1) % m;
        int negIdx =negativeMax-namuji+1;
        int sum1=0;
        if (namuji != 0) sum1 = 2 * books[negIdx];
        while(negIdx != 0){
            negIdx -= m;
            sum1 += 2 * books[negIdx];
        }
        
        namuji = ((n-1) - positiveMin + 1) % m;
        int posIdx = positiveMin + namuji - 1;
        if (namuji != 0) sum1 += 2 * books[posIdx];;
        
        while(posIdx != n-1){
            posIdx += m;
            sum1 += 2 * books[posIdx];
        }
        sum1 -= books[n-1]; // 마지막 수에서 그냥 끝나버리도록
        
        // 양수 -> 음수
        namuji = ((n-1) - positiveMin + 1) % m;
        posIdx = positiveMin + namuji - 1;
        int sum2=0;
        if (namuji != 0) sum2 = 2 * books[posIdx];
        
        while(posIdx != n-1){
            posIdx += m;
            sum2 += 2 * books[posIdx];
        }
        
        namuji = (negativeMax - 0 + 1) % m;
        negIdx = negativeMax-namuji+1; // 여 사이에 if 필요
        if (namuji != 0) sum2 += 2 * books[negIdx];
        while(negIdx != 0){
            negIdx -= m;
            sum2 += 2 * books[negIdx];
        }
        sum2 -= books[0];
        
        (sum1 > sum2)? cout<<sum2 : cout<<sum1;
    }
    else if (isPositiveAll == false){ // 음만 존재
        negativeMax = n-1;
        int namuji = ((negativeMax) - 0 + 1) % m;
        int negIdx = negativeMax-namuji+1;
        int sum=0;
        if (namuji != 0) sum = 2 * books[negIdx];
        while(negIdx != 0){
            negIdx -= m;
            sum += 2 * books[negIdx];
        }
        sum -= books[0];
        cout<<sum;
    }
    else { // 양만 존재
        positiveMin = 0;
        int namuji = ((n-1) - positiveMin + 1) % m;
        int posIdx = positiveMin + namuji - 1;
        int sum=0;
        if (namuji != 0) sum = 2 * books[posIdx];
        while(posIdx != n-1){
            posIdx += m;
            sum += 2 * books[posIdx];
        }
        sum -= books[n-1];
        cout<<sum;
    }
}
