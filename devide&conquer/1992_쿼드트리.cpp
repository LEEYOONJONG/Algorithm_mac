#include <iostream>
using namespace std;

int n;
char arr[65][65];

void dq(int rowS, int rowE, int colS, int colE){
    
    char c = arr[rowS][colS];
    for (int i=rowS; i<=rowE; i++){
        for (int j=colS; j<=colE; j++){
            if (c != arr[i][j]){
                cout<<"(";
                dq(rowS, (rowS+rowE)/2, colS, (colS+colE)/2);
                dq(rowS, (rowS+rowE)/2, (colS+colE)/2+1, colE);
                dq((rowS+rowE)/2+1, rowE, colS, (colS+colE)/2);
                dq((rowS+rowE)/2+1, rowE, (colS+colE)/2+1, colE);
                cout<<")";
                return;
            }
        }
    }
    cout<<c;
    
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    dq(0, n-1, 0, n-1);
}
