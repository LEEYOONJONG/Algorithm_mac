#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> pyo;
int pyoRow;
int pyoCol;
void shift(){
    vector<int> temp;
    temp.resize(pyo[pyoRow-1].size());
    copy(pyo[pyoRow-1].begin(), pyo[pyoRow-1].end(), temp.begin());

    for (int row = pyoRow-2; row>=0; row--){
        pyo[row+1].resize(pyo[row].size());
        copy(pyo[row].begin(), pyo[row].end(), pyo[row+1].begin());
    }
    pyo[0].resize(temp.size());
    copy(temp.begin(), temp.end(), pyo[0].begin());
}
void rotation(){
    int topright = pyo[0][pyoCol-1];
    for (int col = pyoCol-2; col >= 0; col--){
        pyo[0][col+1] = pyo[0][col];
    }
    
    int bottomright = pyo[pyoRow-1][pyoCol-1];
    for (int row = pyoRow-2; row> 0; row--){ // 1 ~ 0
        pyo[row+1][pyoCol-1] = pyo[row][pyoCol-1];
    }
    pyo[1][pyoCol-1] = topright;

    int bottomleft = pyo[pyoRow-1][0];
    for (int col = 0; col<pyoCol-2; col++){
        pyo[pyoRow-1][col] = pyo[pyoRow-1][col+1];
    }
    pyo[pyoRow-1][pyoCol-2] = bottomright;
    
    for (int row=0; row<pyoRow-2; row++){
        pyo[row][0] = pyo[row+1][0];
    }
    pyo[pyoRow-2][0] = bottomleft;

}
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations)
{

    pyo.assign(rc.size(), vector<int>(rc.size()));
    copy(rc.begin(), rc.end(), pyo.begin());
    pyoRow = rc.size();
    pyoCol = rc[0].size();
    for (int i=0; i<operations.size(); i++){
        if (operations[i] == "ShiftRow"){
            shift();
        }
        else {
            rotation();
        }
    }
    return pyo;
}
int main()
{
    vector<vector<int>> rc{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<string> operations{"Rotate"};
    vector<vector<int>> ss = solution(rc, operations);

    for (int i=0; i<ss.size(); i++){
        for (int j=0; j<ss[0].size(); j++){
            cout<<ss[i][j]<<' ';
        }
        cout<<endl;
    }
}