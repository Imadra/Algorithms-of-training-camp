#include <bits/stdc++.h>

#define _cin  ios_base::sync_with_stdio(0); cin.tie(0);

#define clear(a) memset(a,0,sizeof(a))
#define inf(a) memset(a,-1,sizeof(a))

using namespace std;

int n,m,s;
int g[111][111];

int mx(int n, int m)
{
	int mex[1000];
	if(g[n][m] >= 0)
		return g[n][m];
	if(n == 1 && m <= s || m == 1 && n <= s)
    {
		g[n][m] = 0;
		g[m][n]=0;
        return 0;
    }
	clear(mex);
	for(int i = 1; i < n; i++)
		mex[mx(i,m) ^ mx(n - i,m)] = 1;
	for(int j = 1; j < m; j++)
		mex[mx(n,j) ^ mx(n,m - j)] = 1;
	while(mex[g[n][m]])
		g[n][m]++;
	return g[n][m];
	}

main()
	{
	_cin;
	cin>>n>>m>>s;
	inf(g);
	int ans = mx(n, m);
	if(ans == 1)
		cout<<"first";
	else
		cout<<"second";
	}
