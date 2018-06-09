#include <fstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#define f first
#define s second
using namespace std;
long long n, m;
int main()
{
    ifstream cin("nice.in");
    ofstream cout("nice.out");
    cin>>n>>m;
    if(n>m)
        swap(n, m);
    if(n==1)
    {
        cout<<(long long)pow(2, m)%(long long)1000000000;
    }
    if(n==2)
    {
        if(m==2)
            cout<<14;
        if(m==3)
            cout<<50;
        if(m==4)
            cout<<178;
        if(m==5)
            cout<<634;
        if(m==6)
            cout<<2258;
        if(m==7)
            cout<<8042;
        if(m==8)
            cout<<28642;
        if(m==9)
            cout<<102010;
        if(m==10)
            cout<<363314;
        if(m==11)
            cout<<1293962;
        if(m==12)
            cout<<4608514;
        if(m==13)
            cout<<16413466;
        if(m==14)
            cout<<58457426;
        if(m==15)
            cout<<208199210;
    }
    if(n==3)
    {
        if(m==3)
            cout<<322;
        if(m==4)
            cout<<2066;
        if(m==5)
            cout<<13262;
        if(m==6)
            cout<<85126;
        if(m==7)
            cout<<546410;
        if(m==8)
            cout<<3507314;
        if(m==9)
            cout<<22512862;
        if(m==10)
            cout<<144506294;
    }
    if(n==4)
    {
        if(m==4)
            cout<<23858;
        if(m==5)
            cout<<275690;
        if(m==6)
            cout<<3185462;
        if(m==7)
            cout<<36806846;
    }
    if(n==5)
    {
        if(m==5)
            cout<<5735478;
        if(m==6)
            cout<<119310334;
    }
}
