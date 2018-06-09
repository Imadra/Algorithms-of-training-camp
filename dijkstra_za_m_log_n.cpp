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
int n, m, x, y, z;
vector < pair<int,int> > g[100009];
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;
        x--, y--;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    int s = 0;
    vector<int> d (n, inf),  p (n);
    d[s] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (d[s], s));
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j)
        {
            int to = g[v][j].first,
                len = g[v][j].second;
            if (d[v] + len < d[to])
            {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (make_pair (d[to], to));
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";
}
/*
8 11
1 2 0
1 4 0
2 7 5
2 4 3
2 3 4
3 5 2
3 4 3
4 6 6
5 8 0
6 7 1
6 8 0
*/
