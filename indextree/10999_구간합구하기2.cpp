#include <iostream>
using namespace std;

int n, m, k;
long long arr[1000001];
long long plusTree[2100000];
long long minusTree[2100000];
int B;

long long rangeSum(int from){
    from += B-1;
    int to = B*2-1;
    
    long long sum=0;
    while(from <= to){
        if (from % 2 ==1) sum += plusTree[from];
        if (to % 2 == 0) sum += plusTree[to];
        from = (from+1)/2;
        to = (to-1)/2;
    }
    return sum;
}

long long rangeSum2(int from){
    from += B-1;
    int to = B*2-1;
    
    long long sum=0;
    while(from <= to){
        if (from % 2 ==1) sum += minusTree[from];
        if (to % 2 == 0) sum += minusTree[to];
        from = (from+1)/2;
        to = (to-1)/2;
    }
    return sum;
}

void update(int from, int to, long long value){
    to += B-1;
    plusTree[to] += value;
    while((to /=2) > 0 ){
        plusTree[to] += value;
    }
    
    if (from > 1){
        from--;
        from += B-1;
        minusTree[from] -= value;
        while((from /=2) > 0){
            minusTree[from] -= value;
        }
    }
    
}
void initTree(){
    for (B=1; B<n; B*=2);
    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for (int i=0; i<n; i++) cin>>arr[i];
    initTree();
    for (int i=0; i<m+k; i++){
        int a; cin>>a;
        if (a==1){
            int b, c;
            long long d;
            cin>>b>>c>>d; // b번째~c번째에 d를 더함
            update(b, c, d);
        }
        else{
            int b, c;
            cin>>b>>c; //b번째~c번째 수의 합
            long long sum=0;
            for (int j=b; j<=c; j++){
                sum += arr[j-1];
                sum += rangeSum(j);
                sum += rangeSum2(j);
//                cout<<j<<"번째 : "<< arr[j-1]<<"+"<<rangeSum(j)<<"+"<<rangeSum2(j)<<endl;
            }
            cout<<sum<<'\n';
        }
    }
}
