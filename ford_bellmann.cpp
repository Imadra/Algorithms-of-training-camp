#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#define inf 1000*1000*1000
#define ff first
#define ss second
#define mp make_pair
using namespace std;
struct edge
{
    int a, b, cost;
};
int n, m, s, x, y, z;
edge e[100009];
void solve()
{
    vector<int> d(n, inf);
    d[s] = 0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m;j++)
        {
            if(d[e[j].a]<inf)
                d[e[j].b] = min(d[e[j].b], d[e[j].a]+e[j].cost);
        }
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";
}
int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        cin>>e[i].a>>e[i].b>>e[i].cost;
    }
    solve();
}
