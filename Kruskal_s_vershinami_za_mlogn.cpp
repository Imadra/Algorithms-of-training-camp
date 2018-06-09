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
#define sf second.first
#define ss second.second
#define mp make_pair
using namespace std;
int m, n, x, y, z;
vector<int> p (n);
int cost = 0;
vector < pair<int,int> > res;
pair < int, pair<int,int> > g[100009];
int dsu_get (int v)
{
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b)
{
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}
int main()
{

     // вес - вершина 1 - вершина 2
     cin>>n>>m;
     for(int i=0;i<m;i++)
     {
         cin>>x>>y>>z;
         g[i].ff=z;
         g[i].sf=x;
         g[i].ss=y;
     }

    sort (g, g+m);
    p.resize (n+1);
    for (int i=0; i<=n; ++i)
        p[i] = i;
    for (int i=0; i<m; ++i)
    {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b))
        {
            cost += l;
            res.push_back (g[i].second);
            dsu_unite (a, b);
        }
    }
    cout<<cost;
}
