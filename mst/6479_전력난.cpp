#include <iostream>
#include <queue>
using namespace std;

int parent[200001];

struct Data
{
    int from, to, weight;
    Data(int from, int to, int weight) : from(from), to(to), weight(weight){};
    bool operator<(const Data d) const
    {
        return weight > d.weight;
    }
};
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void uni(int x, int y)
{
    parent[find(x)] = find(y);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while (1)
    {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        int x, y, z;
        int routeSum = 0;
        priority_queue<Data> pq;

        for (int i = 0; i < m; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            pq.push(Data(x, y, z));
            routeSum += z;
        }
        int cnt = 0;
        while (!pq.empty())
        {
            if (cnt == m - 1)
                break;
            Data top = pq.top();
            pq.pop();
            if (find(top.from) != find(top.to))
            {
                cnt++;
                uni(top.from, top.to);
                routeSum -= top.weight;
            }
        }
        cout << routeSum << '\n';
    }
}