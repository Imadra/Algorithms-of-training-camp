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
#define inf 1000*1000*1000
using namespace std;
long long n, ind, nn, ans, mm, a[100009], b[100009], len, m, x[100009], y[100009], c[100009];
int l, r, z[100009], v, p, tl, tr, t[400009];
char h[100009];
void build (long long a[], int v, int tl, int tr)
{
    if (tl == tr)                t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
    }
}
void update (int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)                return;
    if (l == tl && tr == r)                t[v] += add;
    else
    {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}
int get (int v, int tl, int tr, int pos)
{
    if (tl == tr)                return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get (v*2, tl, tm, pos);
    else                return t[v] + get (v*2+1, tm+1, tr, pos);
}
int main()
{
    cin>>n;
    v=1, tl=1, tr=n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>h[i];
        if(h[i]=='+')
        {
            cin>>x[i]>>y[i]>>z[i];
            //for(int j=x;j<=y;j++)
            //    a[j]+=z;
        }
        if(h[i]=='*')
        {
            p=1;
            cin>>x[i]>>y[i]>>z[i];
            //for(int j=x;j<=y;j++)
            //    a[j]*=z;
        }
        if(h[i]=='?')
        {
            cin>>x[i];
            //cout<<a[x]<<endl;
        }
    }
    if(p==1)
    {
        for(int i=1; i<=m; i++)
        {
            if(h[i]=='+')
            {
                for(int j=x[i]; j<=y[i]; j++)
                    a[j]+=z[i];
            }
            if(h[i]=='*')
            {
                p=1;
                for(int j=x[i]; j<=y[i]; j++)
                    a[j]*=z[i];
            }
            if(h[i]=='?')
            {
                cout<<a[x[i]]<<endl;
            }
        }
    }
    else
    {
        build(a, v, tl, tr);
        for(int i=1; i<=m; i++)
        {
            if(h[i]=='+')
            {
                update (v, tl, tr, x[i], y[i], z[i]);
            }
            if(h[i]=='?')
            {
                cout<<get(v, tl, tr, x[i]);
            }
        }
    }
}
