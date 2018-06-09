#include<iostream>
#include<cstdio>
#include<algorithm>
#include<time.h>
#include<cstring>
#include<ctime>
#include<cmath>
#include<set>
#include<vector>
#include<string>
#define inf 1000*1000*1000
#define f first
#define s second
using namespace std ;
long long n, m, a[100009], x[100009], y[100009], l, r;
long long t[400009], t2[400009], v, tl, tr;
void build (long long a[], long long v, long long tl, long long tr)
{
    if(tl>tr)
        return;
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] =min( t[v*2] , t[v*2+1]);
    }
}
void build2 (long long a[], long long v, long long tl, long long tr)
{
    if(tl>tr)
        return;
    if (tl == tr)
        t2[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build2 (a, v*2, tl, tm);
        build2 (a, v*2+1, tm+1, tr);
        t2[v] =max( t2[v*2] , t2[v*2+1]);
    }
}
int mi (int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return inf;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(mi (v*2, tl, tm, l, min(r,tm)) , mi (v*2+1, tm+1, tr, max(l,tm+1), r));
}
int ma (int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return -inf;
    if (l == tl && r == tr)
        return t2[v];
    int tm = (tl + tr) / 2;
    return max(ma (v*2, tl, tm, l, min(r,tm)) , ma (v*2+1, tm+1, tr, max(l,tm+1), r));
}
void update (int v, int tl, int tr, int pos, int new_val)
{
    if(tl>tr)
        return;
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
void update2 (int v, int tl, int tr, int pos, int new_val)
{
    if(tl>tr)
        return;
    if (tl == tr)
        t2[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update2 (v*2, tl, tm, pos, new_val);
        else
            update2 (v*2+1, tm+1, tr, pos, new_val);
        t2[v] = max(t2[v*2] , t2[v*2+1]);
    }
}
int main()
{
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]>0)
            n=max(n, y[i]);
        if(x[i]<0)
            n=max(n, abs(x[i]));
    }
    for(int i=1; i<=n; i++)
    {
        a[i]=i*i%12345;
        long long xx=i*i%23456*i%23456;
        a[i]+=xx;
    }
    //cout<<a[1]<<" "<<a[n];
    v=1, tl=1, tr=n;
    build(a, v, tl, tr);
    build2(a, v, tl, tr);
    for(int i=1; i<=m; i++)
    {
        if(x[i]>0)
        {
            cout<<ma(v, tl, tr, x[i], y[i])-mi(v, tl, tr, x[i], y[i])<<endl;
        }
        else
        {
            x[i]=abs(x[i]);
            update(v, tl, tr, x[i], y[i]);
            update2(v, tl, tr, x[i], y[i]);
        }
    }
}
/*
7
1 3
2 4
-2 -100
1 5
8 9
-3 -101
2 3
*/
