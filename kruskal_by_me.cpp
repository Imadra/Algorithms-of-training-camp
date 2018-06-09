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
int m, n, x, y, z, size[100200];
vector<int> p (n);
void make_set (int v)
{
	p[v] = v;
	size[v] = 1;
}
int get(int v)
{
    if(v != p[v])
        return p[v] = get(p[v]);
    else
        return v;
}
void uni (int a, int b)
{
	a = get (a);
	b = get (b);
	if (a != b)
    {
		if (size[a] < size[b])
			swap (a, b);
		p[b] = a;
		size[a] += size[b];
	}
}
vector < pair < int, pair<int,int> > > g;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        x--, y--;
        g.push_back(mp(z, mp(x, y)));
    }
    int cost = 0;
    vector<pair<int, int> > res;
    p.resize(n);
    for(int i=0;i<n;i++)
        make_set(i);
    sort(g.begin(), g.end());
    for(int i=0;i<m;i++)
    {
        int a = g[i].ss.ff, b=g[i].ss.ss, we = g[i].ff;
        if(get(a) != get(b))
        {
            cost+=we;
            res.push_back(mp(a, b));
            uni(a, b);
        }
    }
    cout<<cost<<endl;
    for(int i=0;i<res.size();i++)
        cout<<res[i].ff + 1<<" "<<res[i].ss + 1<<endl;
}
