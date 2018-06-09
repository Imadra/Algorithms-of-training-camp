#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<utility>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN = 509;
const int INF = 10000009;
int n, c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];
bool bfs()
{
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    //for(int i=0;i<n*sizeof d[0];i++)
      //  d[i]=-1;
    d[s] = 0;
    while (qh < qt)
    {
        int v = q[qh++];
            for (int to=0; to<n; ++to)
                if (d[to] == -1 && f[v][to] < c[v][to])
                {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
    }
    return d[t] != -1;
}
int dfs (int v, int flow)
{
    if (!flow)
        return 0;
    if (v == t)
        return flow;
    for (int & to=ptr[v]; to<n; ++to)
    {
        if (d[to] != d[v] + 1)
            continue;
        int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
        if (pushed)
        {
            f[v][to] += pushed;
            f[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}
int dinic()
{
    int flow = 0;
    for (;;)
    {
        cout<<bfs()<<" ";
        if (!bfs())
            break;
        memset (ptr, 0, n * sizeof ptr[0]);
        //for(int i=0;i<n*sizeof ptr[0];i++)
          //  ptr[i]=0;
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}
int main()
{
    cin>>n;
    s=1, t=n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>c[i][j];
    cout<<dinic();
}
