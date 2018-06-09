#include <bits/stdc++.h>

using namespace std;

long long MF;
long long f[1000][1000];
long long c[1000][1000];
int timer;
int p[10000];
// vector <int> g[1000];

int n, m;

int used[1000];

const int inf = (int)(1e9);

int s, t;

bool bfs (int v, int t)
{
	queue <int> q;
	q.push (v);

	while (!q.empty ())
    {
		int x = q.front();
		q.pop();
		if (x == t)
			return true;
		for (int i = 1; i <= n; i++) {
			if (used[i] != timer && c[x][i] > f[x][i])
            {
				p[i] = x;
				used[i] = timer;
				q.push (i);
			}
		}
	}
	return false;
}

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
    {
		int x, y, w; cin >> x >> y >> w;
		c[x][y] = w;
	}
	s = 1;
	t = n;
	int x = inf;
	timer = 1;
    while (bfs (s, t))
    {
        timer++;
        long long mn = inf;
        for (int i = t; i != s; i = p[i])
            mn = min (mn, c[p[i]][i] - f[p[i]][i]);
        for (int i = t; i != s; i = p[i])
            f[p[i]][i] += mn,
            f[i][p[i]] -= mn;
        MF += mn;;
        memset (p, 0, sizeof p);
    }
	cout << MF;

	return 0;
}
