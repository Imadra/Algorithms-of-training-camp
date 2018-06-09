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
#define pb insert
using namespace std;
int n, p;
set<int> ans;
int go(int l, int r, int color, int v, int need)
{
    if(r-l+1<=3)
    {
        if(v==1 && r-l+1==3)
            ans.pb(l+1), p=1;
        if(v==1 && r-l+1==2)
            ans.pb(l), ans.pb(r), p=1;
        if(v==1 && r-l+1==1)
            ans.pb(l), p=1;
        else
        {
            if(r-l+1==3)
                return need;
            else
                return 1;
        }
    }
    int next;
    if(color==1)
        next=2;
    else
        next=1;
    if(go(l+1, r, next, v+1, 1)==-1)
    {
        if(v==1)
            ans.pb(l), p=1;
        else
        return 1;
    }
    if(go(l+2, r, next, v+1, 1)==-1)
    {
        if(v==1)
            ans.pb(2), p=1;
        else
        return 1;
    }
    if(go(l, r-1, next, v+1, 1)==-1)
    {
        if(v==1)
            ans.pb(r), p=1;
        else
        return 1;
    }
    if(go(l, r-2, next, v+1, 1)==-1)
    {
        if(v==1)
        ans.pb(r-1), p=1;
        else
        return 1;
    }
    for(int i=l+2;i<=r-2;i++)
    {
        if(go(l, i-1, next, v+1, 1) + go(i+1, r, next, v+1, -1) != 0 && go(l, i-1, next, v+1, -1) + go(i+1, r, next, v+1, 1) != 0)
        {
            if(v==1)
                ans.pb(i), p=1;
            else
                return 1;
        }
    }
    if(v==1 && p==1)
        return 1;
    else
        return -1;
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>n;
    if(go(1, n, 1, 1, 1)==1)
    {
        cout<<"Schtirlitz"<<endl;
        for(set<int>:: iterator i=ans.begin();i!=ans.end();i++)
            cout<<*i<<endl;
    }
    else
        cout<<"Mueller";
}
