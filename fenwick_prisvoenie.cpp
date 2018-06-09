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
int n, l, r, a[100009], tl, tr, v, m, x, c[100009];
vector<int> t;
char h;
void init1 (int nn)
{
    n = nn;
    t.assign (n, 0);
}
int sum1 (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}
void inc1 (int i, int delta, int mi)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += delta,
        t[i]-=mi;
}
int sum2 (int l, int r)
{
    return sum1 (r) - sum1 (l-1);
}
void init2 (int a[])
{
    init1 (n);
    for (unsigned i = 0; i < n; i++)
        inc1 (i, a[i], 0);
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    init2(a);
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>h>>l>>r;
        if(h=='Q')
        {
            cout<<sum2(l-1, r-1)<<endl;
        }
        else
        {
            inc1(l-1, r, a[l-1]);
            a[l-1]=r;
        }
    }
}
/*
*/
