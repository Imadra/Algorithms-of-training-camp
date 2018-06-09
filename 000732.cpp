#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#define f first
#define s second
using namespace std;
int n, m, a[1009][1009], b[1009][1009], sum, d[100009], ind, x[1009], y[1009], z, u[10009], color[100009], k, u2[100009];
int cl[1009];
vector<int> ans;
void dfs(int v)
{
    u[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[v][i] && !u[i])
            dfs(i);
    }
    ind++;
    d[ind]=v;
}
void col(int v)
{
    u2[v]=1;
    color[v]=k;
    for(int i=1;i<=n;i++)
    {
        if(b[v][i] && !u2[i])
            col(i);
    }
}
int main()
{
    //ifstream cin("numbers.in");
    //ofstream cout("numbers.out");
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        a[x[i]][y[i]]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j])
                b[j][i]=1;
        }
    for(int i=1;i<=n;i++)
        if(!u[i])
            dfs(i);
    for(int i=1;i<=n;i++)
    {
        if(!color[d[i]])
        {
            k++;
            ans.push_back(d[i]);
            col(d[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(vector<int> :: iterator it=ans.begin(); it!=ans.end(); it++)
        cout<<*it<<" ";
}
