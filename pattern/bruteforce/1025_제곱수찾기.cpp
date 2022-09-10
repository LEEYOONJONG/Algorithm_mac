#include <iostream>
#include <cmath>
using namespace std;

int main(){
//    int test = 95482;
//    double sq = sqrt(test);
//    double cha = sq - floor(sq);
//    cout<<cha<<endl;
//    if (cha==0){
//        cout<<"제곱수"<<endl;
//    } else { cout <<"아니ㅛ"<<endl; }
    
    int n, m;
    int table[10][10];
    int maximum=-1;
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++){
            char input;
            cin>>input;
            table[i][j] = input - '0';
        }
    }
    
    // 시작지점
    for (int rowS=0; rowS<n; rowS++){
        for (int colS=0; colS<m; colS++){
            
            for (int rowgap=-(n-1); rowgap<n; rowgap++){
                for (int colgap=-(m-1); colgap<m; colgap++){
                    int res1=0;
//                    int res2=0, revIdx=1;
                    
                    if (rowgap==0 && colgap==0){
                        res1 = table[rowS][colS];
//                        res2 = table[rowS][colS];
                        
                    }
                    else{
                        int rowIdx=rowS, colIdx=colS;
                        while(0<=rowIdx && rowIdx<n && 0<=colIdx && colIdx<m){
                            res1 *= 10;
                            res1 += table[rowIdx][colIdx];
//                            res2 += table[rowIdx][colIdx] * revIdx;
//                            revIdx *= 10;
                            rowIdx += rowgap;
                            colIdx += colgap;
                            if (sqrt(res1) - ceil(sqrt(res1)) == 0){
                                if (maximum < res1) maximum = res1;
                            }
                        }
                    }
                    
                    
//                    if (sqrt(res2) - ceil(sqrt(res2)) == 0){
//                        if (maximum < res2) maximum = res2;
//                    }
                    
                }
            }
        }
    }

    cout<<maximum;
    
}

