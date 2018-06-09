#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#define f first
#define s second
using namespace std;
int n, m, sum, d[100009], x, y, z, u[20009], color[100009], k, u2[100009], t[100009];
int f[100009];
vector<int> ans;
vector<int> g[20009];
int ind[2001][2001];
void dfs(int v, int p=-1)
{
    u[v]=1;
    k++;
    t[v]=f[v]=k;
    for(int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
            if(to==p)
                continue;
            if(u[to])
                f[v]=min(f[v], t[to]);
            else
            {
                dfs(to, v);
                f[v]=min(f[v], f[to]);
                if(f[to]>t[v])
                    ans.push_back(ind[v][to]);
            }
    }
}
int main()
{
    //ifstream cin("numbers.in");
    //ofstream cout("numbers.out");
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        ind[x][y]=i;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(vector<int> :: iterator it=ans.begin(); it!=ans.end(); it++)
        cout<<*it<<endl;
}

