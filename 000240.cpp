# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <vector>
# define FOR(xxx, yyy, zzz) for (int xxx = yyy; xxx <= zzz; ++xxx)
# define FRO(xxx, yyy, zzz) for (int xxx = yyy; xxx >= zzz; --xxx)
# define pb push_back
# define mp make_pair
# define pii pair <int, int>
# define F first
# define S second
# define sz(xxx) (int)xxx.size()

using namespace std;

typedef long long ll;

const int N = int (5e5 + 7);

vector <int> g[N];

bool u1[N];

int d[N][20], tin[N], tout[N], timer;

void dfs1 (int v, int p = 0)
{
    tin[v] = ++timer;
    u1[v] = true;
    d[v][0] = p;
    FOR (i, 1, 18)
    d[v][i] = d[d[v][i - 1]][i - 1];
    FOR (i, 0, sz (g[v]) - 1)
    {
        int to = g[v][i];
        if (!u1[to])
        {
            dfs1 (to, v);
        }
    }
    tout[v] = ++timer;
}

bool isup (int A, int B)
{
    return tin[A] <= tin[B] && tout[A] >= tout[B];
}

int lca (int A, int B)
{
    if (isup (A, B)) return A;
    if (isup (B, A)) return B;
    FRO (i, 18, 0)
    {
        if (d[A][i] && !isup(d[A][i], B))
            A = d[A][i];
    }
    return d[A][0];
}

vector < pii > ask;
int main ()
{
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    int m;
    cin >> m;
    scanf ("\n");
    while (m --> 0)
    {
        int u, v;
        char ch1, ch2, ch3;
        ch1 = getchar ();
        ch2 = getchar ();
        ch3 = getchar ();
        scanf ("%d%d\n", &u, &v);
        if (ch1 == 'A')
        {
            g[u].pb (v);
            g[v].pb (u);
        }
        else ask.pb (mp (v, u));
    }
    dfs1 (1);
    FOR (i, 0, sz (ask) - 1)
    cout << lca (ask[i].F, ask[i].S) << endl;
}
