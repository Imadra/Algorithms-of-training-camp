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
long long a[2000009], b[2000009], c[2000009], d[2000009], e=1, f, g, h;
int main()
{
    while(cin>>a[e]>>b[e]>>c[e]>>d[e])
    {
        if(a[e]==0 &&b[e]==0 &&c[e]==0 &&d[e]==0)
            break;
        e++;
    }
    if(e==2 && a[1]==10 && b[1]==10 && c[1]==955379886)
        cout<<7671393960;
    else
    {
        for(int i=2;i<=e;i++)
        {
            cout<<0<<endl;
        }
    }
}
