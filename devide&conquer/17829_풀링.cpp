#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1025][1025];

int dc(int rowS, int rowE, int colS, int colE){
    if (rowS==rowE && colS==colE){
        cout<<arr[rowS][colS];
    }
    if ((rowE-rowS == 1) && (colE-colS == 1)){
        int tmp[4];
        tmp[0] = arr[rowS][colS];
        tmp[1] = arr[rowS][colE];
        tmp[2] = arr[rowE][colS];
        tmp[3] = arr[rowE][colE];
        sort(tmp, tmp+4);
        return tmp[2];
    }
    int newArr[1025][1025];
    int rowIndex=0;
    int colIndex=0;
    for (int i=rowS; i<=rowE; i+=2){
        for (int j=colS; j<=colE; j+=2){
            newArr[rowIndex][colIndex] = dc(i, i+1, j, j+1);
            colIndex++;
        }
        rowIndex++;
    }
    copy(&newArr[0][0], &newArr[0][0] + (1025*1025), &arr[0][0]);
    return 0; // 무의미
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    dc(0, n-1, 0, n-1);
}
