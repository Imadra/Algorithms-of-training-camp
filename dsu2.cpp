#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> p, rnk;
int n, m, x, y, l[150009], r[150009], k;
string h[150009];
vector<int> ans;
int find_set (int x)
{
    if (x == p[x])  return x;
    return p[x] = find_set (p[x]);
}
void unite (int x, int y)
{
    x = find_set (x);
    y = find_set (y);
    if (rnk[x] > rnk[y])
        p[y] = x;
    else
    {
        p[x] = y;
        if (rnk[x] == rnk[y])
            ++rnk[y];
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>h[i]>>l[i]>>r[i];
    }
    p.resize (n+1);
    for (int i=1; i<=n; ++i)
        p[i] = i;
    rnk.resize (n+1);
    for(int i=k;i>=1;i--)
    {
        //cout<<find_set(l[i])<<endl<<find_set(r[i])<<endl;
        if(h[i]=="ask")
        {
            if(find_set(l[i])==find_set(r[i]))
            {
                ans.push_back(1);
                continue;
            }
            ans.push_back(2);
        }
        else
        {
            unite(l[i], r[i]);
        }
    }
    //cout<<"ok";
    reverse(ans.begin(), ans.end());
    //cout<<"ok";
    for(vector<int> :: iterator i=ans.begin();i!=ans.end();i++)
    {
        if(*i==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
