#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1025][1025];

int dc(int rowS, int rowE, int colS, int colE){
//    if (rowS==rowE && colS==colE){ // 최대한도로 쪼갬
//        return arr[rowS][colS];
//    }
    if ((rowE-rowS == 1) && (colE-colS == 1)){ // 2x2로 쪼개졌을
        int tmp[4];
        tmp[0] = arr[rowS][colS];
        tmp[1] = arr[rowS][colE];
        tmp[2] = arr[rowE][colS];
        tmp[3] = arr[rowE][colE];
        sort(tmp, tmp+4);
        return tmp[2];
    }
    else {
        int tmp[4];
        tmp[0] = dc(rowS, (rowS+rowE)/2, colS, (colS+colE)/2);
        tmp[1] = dc(rowS, (rowS+rowE)/2, (colS+colE)/2+1, colE);
        tmp[2] = dc((rowS+rowE)/2+1, rowE, colS, (colS+colE)/2);
        tmp[3] = dc((rowS+rowE)/2+1, rowE, (colS+colE)/2+1, colE);
        sort(tmp, tmp+4);
        return tmp[2];
    }
    
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<dc(0, n-1, 0, n-1);
}
