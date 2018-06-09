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
void build (int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

void update (int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] += add;
    else
    {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int get (int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return inf;
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(get (v*2, tl, tm, l, min(r, tm)), get (v*2+1, tm+1, tr, max(l, tm+1), r));
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
        cin>>h>>l;
        if(h=='U')
        {
            cin>>r>>x;
            update(v, tl, tr, l, r, x);
        }
        else
        {
            cin>>r;
            cout<<get(v, tl, tr, l, r)<<endl;
        }
    }
}
/*
*/
