#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct Data{
    int a, b, c;
    Data(int a, int b, int c):a(a), b(b), c(c){};
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int tc; cin>>tc;
    vector<Data> list;
    for (int x=0; x<tc; x++){

        list.clear(); // 5000개
        long long dist[501];
        int n, m, w; cin>>n>>m>>w;
        for (int i=1; i<=n; i++) dist[i] = INF;
        dist[1] = 0; // 중요. 1을 시작지점으로 -> 이러면 INF을 밑에서 씹으면 안됨.
        
        for (int i=0; i<m; i++){
            int s, e, t; cin>>s>>e>>t;
            list.push_back(Data(s, e, t));
            list.push_back(Data(e, s, t));
        }
        for (int i=0; i<w; i++){
            int s, e, t; cin>>s>>e>>t;
            list.push_back(Data(s, e, -t));
        }
        
        for (int i=1; i<n; i++){ // 500
            for (int j=0; j<list.size(); j++){ // 5000
                int from = list[j].a;
                int to = list[j].b;
                int cost = list[j].c;
                if (dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                }
            }
        }
        bool isCycle  = false;
        for (int j=0; j<list.size(); j++){ // 5000
            int from = list[j].a;
            int to = list[j].b;
            int cost = list[j].c;
            if (dist[to] > dist[from] + cost){
                isCycle = true;
                break;
            }
        }
        if (isCycle) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
        
    }
}
