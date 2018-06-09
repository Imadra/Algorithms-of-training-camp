#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int n, l,a[500009],b[500009],k;
vector < int> g[500009];
vector<char> used;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
void dfs (int v, int p = 0)
{
    used[v] = true;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs (to, v);
    }
    tout[v] = ++timer;
}
bool upper (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca (int a, int b)
{
    if (upper (a, b)) return a;
    if (upper (b, a)) return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}
int main()
{
    string s;
    cin>>n;
    used.resize (n), tin.resize (n), tout.resize (n), up.resize (n);
    l = 1;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='A')
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            g[x].push_back(y);
        }
        else
        {
            cin>>a[k]>>b[k];
                k++;
        }
    }
    while ((1<<l) <= n) ++l;
    for (int i=0; i<n; ++i) up[i].resize (l+1);
    dfs (0);
    for(int i=0;i<k;i++)
    {
        a[i]--;b[i]--;
        int res = lca (a[i], b[i]);
        cout<<res+1<<endl;
    }
}
