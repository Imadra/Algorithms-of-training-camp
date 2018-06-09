/*
Solution of Problem "Molecule"
Dinic Algorithm O(V^2E)
Khamitbekov Madi
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cassert>

using namespace std;

int f1 (char ch)
{
    if (ch == 'H') return 1;
    if (ch == 'O') return 2;
    if (ch == 'N') return 3;
    if (ch == 'C') return 4;
    return 0;
}
int n, m;
int get (int i, int j)
{
    assert (i >= 0 && j >= 0);
    return i*m+j;
}
const int maxn = 55;
const int maxN = 50*50+7;
int cc[maxn][maxn];
int c[maxN][maxN], f[maxN][maxN];
vector <int> a[maxN];
int d[maxN], p[maxN];
int q[maxN*100];
bool bfs (int s, int t)
{
    memset (d,-1,sizeof(d));
    memset (p,-1,sizeof(p));
    d[s] = 0;
    int l = 0, r = 0;
    q[r++] = s;
    while (l < r)
    {
        int x = q[l];
        l++;
        for (int j = 0; j < a[x].size(); j++)
        {
            int i = a[x][j];
            if (c[x][i]-f[x][i] > 0 && d[i] == -1)
            {
                d[i] = d[x] + 1;
                p[i] = x;
                q[r++] = i;
            }
        }
    }
    return p[t] != -1;
}
int N;
int tmp[maxN];
#define inf 1000000007
int dfs (int x, int flow)
{
    if (flow <= 0) return 0;
    if (x == N-1) return flow;
    for (int &j = tmp[x]; j < a[x].size(); j++)
    {
        int i = a[x][j];
        if (d[x] == d[i]-1)
        {
            int push = dfs (i, min(c[x][i]-f[x][i],flow));
            if (push)
            {
                f[x][i] += push;
                f[i][x] -= push;
                return push;
            }
        }
    }
    return 0;
}
int MaxFlow (int s, int t)
{
    int flow = 0;
    while (bfs (s,t))
    {
        memset (tmp, 0, sizeof(tmp));
        while (int push = dfs (s,inf)) flow += push;
    }
    return flow;
}
int main ()
{
//   freopen ("molecule.in", "r", stdin);
    // freopen ("molecule.out", "w", stdout);
    char ch;
    cin >> n >> m;
    N = n*m+2;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            cc[i][j] = f1(ch);
            if (cc[i][j] == 0) continue;
            if ((i+j)&1)
            {
                s1 += cc[i][j];
                c[N-2][i*m+j] = cc[i][j];
                a[N-2].push_back (get(i,j));
                a[get(i,j)].push_back (N-2);
                if (i) c[get(i,j)][get(i-1,j)] = 1, a[get(i,j)].push_back(get(i-1,j)), a[get(i-1,j)].push_back(get(i,j));
                if (j) c[get(i,j)][get(i,j-1)] = 1, a[get(i,j)].push_back(get(i,j-1)), a[get(i,j-1)].push_back(get(i,j));
                if (i != n-1) c[get(i,j)][get(i+1,j)] = 1, a[get(i,j)].push_back(get(i+1,j)), a[get(i+1,j)].push_back(get(i,j));
                if (j != m-1) c[get(i,j)][get(i,j+1)] = 1, a[get(i,j)].push_back(get(i,j+1)), a[get(i,j+1)].push_back(get(i,j));
            }
            else         s2 += cc[i][j], c[i*m+j][N-1] = cc[i][j], a[get(i,j)].push_back (N-1), a[N-1].push_back(get(i,j));
        }
    if (s1 == 0 || MaxFlow (N-2,N-1) != s1 || s1 != s2)
    {
        cout << "Invalid";
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {

            if ((i+j)%2 == 0 && f[get(i,j)][N-1] != cc[i][j])
            {
                cout << "Invalid";
                return 0;
            }
            if (((i+j)&1) && f[N-2][get(i,j)] != cc[i][j])
            {
                cout << "Invalid";
                return 0;
            }
        }
    cout << "Valid";
    return 0;
}

