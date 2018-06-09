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
int n, l, r, a[100009], t[100009], tl, tr, v, m, c[400800], x;
char h;
void push(int v)
{
    if(c[v])
    {
        c[v * 2] = c[v * 2 + 1] = c[v];
        c[v] = 0;
    }
}
void build (int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = min( t[v*2] , t[v*2+1]);
    }
}
int mi (int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return inf;
    if (l == tl && r == tr)
    {
        if(c[v])
            return c[v];
        else
            return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return min(mi (v*2, tl, tm, l, min(r,tm)) , mi (v*2+1, tm+1, tr, max(l,tm+1), r));
}
void update (int v, int tl, int tr, int l, int r, int new_val)
{
    if (tl == l && r == tr)
        c[v] = new_val;
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r, tm), new_val);
        update (v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    v=1, tl=1, tr=n;
    build(a, v, tl, tr);
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>h>>l>>r;
        if(h=='U')
        {
            cin>>x;
            update(v, tl, tr, l, r, x);
        }
        else
        {
            cout<<mi(v, tl, tr, l, r)<<endl;
        }
    }
}
/*
*/
