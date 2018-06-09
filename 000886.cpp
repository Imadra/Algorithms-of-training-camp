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
string t, ss, h;
int n, ind, nn, ans, mm, x[1000009], u[100009];
int l, r;
void z_f(int ll, int rr)
{
    l=0, r=0;
    vector<int> z(rr);
    int mi=inf, ma=0;
    for(int i=ll;i<rr;i++)
    {
        if(i<=r)
        {
            z[i]=min(z[i-l], r-i+1);
        }
        while(t[i+z[i]]==t[z[i]] && i+z[i]<rr)
            z[i]++;
        if(i+z[i]-1>r)
            r=i+z[i]-1, l=i;
        if(u[i])
        {
            if(z[i]<mi)
                mi=z[i];
            u[i]=0;
        }
        else
        {
            if(z[i]>ma)
                ma=z[i];
        }
    }
    ma++;
//    cout<<ma<<" "<<mi<<endl;
    if(ma>mi || !mi)
        cout<<"Mistake."<<endl;
    else
        cout<<"Correct. Length = "<<ma<<".."<<mi<<"."<<endl;
}
int main()
{
    while(cin>>nn>>mm)
    {
        if(nn==0 && mm==0)
            return 0;
        cin>>t;
        for(int i=1;i<=mm;i++)
            cin>>x[i], u[x[i]-1]=1;
        ind=x[1]-1;
        z_f(ind, t.length());
    }
}
/*
3 2
0 1
2 1
1 1 0
*/
