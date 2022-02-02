#include <iostream>
#include <cstring>
using namespace std;

int n;
long long b;
int **arr;


int **multiply(int **matrix1, int **matrix2){
    int **res = nullptr;
    res = new int*[n];
    for (int i=0; i<n; i++) res[i] = new int[n];
    
    // 초기화
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            res[i][j] = 0;
    
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            for (int k=0; k<n; k++){
                res[row][col] += (matrix1[row][k]) * (matrix2[k][col]);
            }
            res[row][col] = res[row][col]%1000;
        }
    }
    return res;
}

int **pow(long long x){
    if (x==1) return arr;
    else if (x%2 == 0){
        int **tmp = pow(x/2);
        return multiply(tmp, tmp);
    }
    else {
        return multiply(arr, pow(x-1));
    }
}

int **add(int **matrix1, int **matrix2){
    int **res = nullptr;
    res = new int*[n];
    for (int i=0; i<n; i++) res[i] = new int[n];
    
    // 초기화
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            res[i][j] = 0;
    
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            res[row][col] = (matrix1[row][col] + matrix2[row][col]) % 1000;;
        }
    }
    return res;
}

// jisu 에서 부터의 합 (A^jisu + A^(jisu-1) + ....+ A^1)
int **calc2(long long jisu){
    if (jisu == 1) return arr;
    else if (jisu % 2 == 1){
        return add(calc2(jisu-1), pow(jisu));
    }
    else {
        // 단위행렬 초기화
        int **unitMatrix;
        unitMatrix = new int*[n];
        for (int i=0; i<n; i++) unitMatrix[i] = new int[n];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) unitMatrix[i][j] = 1;
                else unitMatrix[i][j] = 0;
            }
        }
        
        return  multiply(add(pow(jisu/2), unitMatrix), calc2(jisu/2));
    }
}

int main(){
    cin>>n>>b;
    arr = new int*[n];
    for (int i=0; i<n; i++){
        arr[i] = new int[n];
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    int **answer = calc2(b);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<answer[i][j]%1000<<' ';
        }
        cout<<'\n';
    }
}
