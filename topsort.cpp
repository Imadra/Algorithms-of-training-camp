#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int n, m, sum, d[100009], ind;
int x, y, z, u[100009], color[100009], k, u2[100009];
vector<int> ans, ans2;
vector< int > g[100009];
void dfs(int v)
{
    u[v]=1;
    for(vector<int> :: iterator it=g[v].begin();it!=g[v].end();it++)
    {
        if(!u[*it])
            dfs(*it);
        else if(u[*it]==1)
        {
            cout<<-1;
            exit(0);
        }
    }
    u[v]=2;
    ans.push_back(v);
}
int main()
{
    //ifstream cin("numbers.in");
    //ofstream cout("numbers.out");
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
        if(!u[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
    for(vector<int> :: iterator it=ans.begin();it!=ans.end();it++)
        cout<<*it<<" ";
}
