#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> numlist;
vector<char> operlist;
long long res=0;
void order(){
    vector<char> oper{'+', '-', '*', '/'};
    sort(oper.begin(), oper.end());
    vector<long long> nlist;
    vector<char> olist;
    do {
        nlist.resize(numlist.size());
        copy(numlist.begin(), numlist.end(), nlist.begin());
        olist.resize(numlist.size());
        copy(operlist.begin(), operlist.end(), olist.begin());

        for (auto it = oper.begin(); it != oper.end(); it++){
            while(find(olist.begin(), olist.end(), *it) != olist.end()){
                int idx = find(olist.begin(), olist.end(), *it) - olist.begin();
                olist.erase(olist.begin() + idx);
                switch (*it)
                {
                case '+':
                    nlist[idx] = nlist[idx]+nlist[idx+1];
                    break;
                case '-':
                    nlist[idx] = nlist[idx]-nlist[idx+1];
                    break;
                case '*':
                    nlist[idx] = nlist[idx]*nlist[idx+1];
                    break;
                case '/':
                    nlist[idx] = nlist[idx]/nlist[idx+1];
                    break;
                default:
                    break;
                } 
                nlist.erase(nlist.begin() + (idx+1));
            }
        }
        res = max(abs(nlist[0]), res);
    } while (next_permutation(oper.begin(), oper.end()));
    
}
long long solution(string expression) {
    
    long long sum=0;
    for (int i=0; i<expression.size(); i++){
        if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*' || expression[i] == '/'){
            operlist.push_back(expression[i]);
            numlist.push_back(sum);
            sum = 0;
        }
        else{
            sum *= 10;
            sum += expression[i] - '0';
        }
    }
    numlist.push_back(sum);
    
    order();
    return res;
} 
int main(){
    cout<<solution("100-200*300-500+20");
}