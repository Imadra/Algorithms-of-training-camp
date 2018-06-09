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
int n, l, r, a[100009], t[100009], tl, tr, v, m;
char h;
void build (int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum (int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum (v * 2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
void update (int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
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
            update(v, tl, tr, l, r);
        }
        else
        {
            cout<<sum(v, tl, tr, l, r)<<endl;
        }
    }
}
