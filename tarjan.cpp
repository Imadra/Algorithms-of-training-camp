#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<utility>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<set>
#define f first
#define s second
using namespace std;
const int MAXN = 10000009;
vector<int> g[MAXN], q[MAXN];
// граф и все запросы
int dsu[MAXN], ancestor[MAXN], n, m, x, y, k, a[100009], b[100009], us[1009][1009], ans[1009][1009];
bool u[MAXN];
int dsu_get (int v)
{
    return v == dsu[v] ? v : dsu[v] = dsu_get (dsu[v]);
}
void dsu_unite (int a, int b, int new_ancestor)
{
    a = dsu_get (a),  b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    dsu[a] = b,  ancestor[b] = new_ancestor;
}
void dfs (int v)
{
    dsu[v] = v,  ancestor[v] = v;
    u[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!u[g[v][i]])
        {
            dfs (g[v][i]);
            dsu_unite (v, g[v][i], v);
        }
    for (size_t i=0; i<q[v].size(); ++i)
        if (u[q[v][i]])
        {
            int d=v+1, f=q[v][i]+1;
            if(d>f)
                swap(d, f);
            ans[d][f]=ancestor[ dsu_get(q[v][i]) ]+1;
        }
}
int main()
{
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // чтение запросов
        cin>>k;
        for (int i=1;i<=k;i++)
        {
            cin>>a[i]>>b[i];
            // очередной запрос
            --a[i], --b[i];
            q[a[i]].push_back (b[i]);
            q[b[i]].push_back (a[i]);
        }
        // обход в глубину и ответ на запросы
        dfs (0);
    for(int i=1;i<=k;i++)
    {
        cout<<ans[a[i]+1][b[i]+1]<<endl;
    }
}
